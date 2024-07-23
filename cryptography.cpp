#include "cryptography.h"

// Derive a key from the password and salt
SecByteBlock derive_key(const QString& password, const CryptoPP::byte* salt, size_t salt_size, size_t key_length) {
    SecByteBlock key(key_length);
    PKCS5_PBKDF2_HMAC<SHA256> pbkdf;

    QByteArray password_bytes = password.toUtf8();
    pbkdf.DeriveKey(key, key.size(), 0, (const CryptoPP::byte*)password_bytes.constData(), password_bytes.size(), salt, salt_size, 10000);

    return key;
}

// Convert data to a hexadecimal string
QString to_hex_string(const CryptoPP::byte* data, size_t length) {
    std::string hex_str;
    CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(hex_str));
    encoder.Put(data, length);
    encoder.MessageEnd();
    return QString::fromStdString(hex_str);
}

// Convert a hexadecimal string to SecByteBlock
SecByteBlock from_hex_string(const QString& hex_string) {
    std::string decoded;
    if (hex_string.length() % 2 != 0) {
        throw std::runtime_error("Invalid hex string length");
    }

    CryptoPP::StringSource ss(hex_string.toStdString(), true, new CryptoPP::HexDecoder(new CryptoPP::StringSink(decoded)));
    return SecByteBlock(reinterpret_cast<const CryptoPP::byte*>(decoded.data()), decoded.size());
}

// Hash the password and generate a salt
std::pair<QByteArray, QByteArray> hash_password(const QString &password) {
    QByteArray salt(16, 0);
    for (int i = 0; i < salt.size(); ++i) {
        salt[i] = static_cast<char>(QRandomGenerator::global()->bounded(256));
    }

    QByteArray hashed_password = QCryptographicHash::hash(password.toUtf8() + salt, QCryptographicHash::Sha256);

    return std::make_pair(hashed_password.toBase64(), salt.toBase64());
}

// Hash the password with a given salt
QByteArray hash_password(const QString &password, const QString &salt) {
    QByteArray decoded_salt = QByteArray::fromBase64(salt.toUtf8());
    QByteArray hashed_password = QCryptographicHash::hash(password.toUtf8() + decoded_salt, QCryptographicHash::Sha256);

    return hashed_password.toBase64();
}

// Encrypt plaintext using AES with the provided key, and output salt and IV
QString encrypt_aes(const QString& plaintext, const QString& key, QString& salt_out, QString& iv_out) {
    AutoSeededRandomPool rng;

    // Generate salt
    CryptoPP::byte salt[16];
    rng.GenerateBlock(salt, sizeof(salt));
    salt_out = to_hex_string(salt, sizeof(salt));

    // Derive key from key and salt
    SecByteBlock aes_key = derive_key(key, salt, sizeof(salt), AES::DEFAULT_KEYLENGTH);

    // Generate IV
    CryptoPP::byte iv[AES::BLOCKSIZE];
    rng.GenerateBlock(iv, sizeof(iv));
    iv_out = to_hex_string(iv, sizeof(iv));

    string ciphertext;

    try {
        CBC_Mode<AES>::Encryption encryption;
        encryption.SetKeyWithIV(aes_key, aes_key.size(), iv);

        StringSource ss1(plaintext.toStdString(), true, new StreamTransformationFilter(encryption, new StringSink(ciphertext)));
    }
    catch (const Exception& e) {
        qDebug() << e.what();
        return QString();
    }

    // Convert binary ciphertext to Base64
    string encoded;
    StringSource ss2(ciphertext, true, new Base64Encoder(new StringSink(encoded)));

    return QString::fromStdString(encoded);
}

// Decrypt ciphertext using AES with the provided key, salt, and IV
QString decrypt_aes(const QString& ciphertext, const QString& key, const QString& salt_hex, const QString& iv_hex) {
    string decrypted_text;

    // Convert Base64 ciphertext to binary
    string binary_ciphertext;
    StringSource ss1(ciphertext.toStdString(), true, new Base64Decoder(new StringSink(binary_ciphertext)));

    // Hex string to SecByteBlock conversion for salt
    SecByteBlock salt_block = from_hex_string(salt_hex);

    // Hex string to SecByteBlock conversion for iv
    SecByteBlock iv_block = from_hex_string(iv_hex);

    // Derive key from key and salt
    SecByteBlock aes_key = derive_key(key, salt_block.data(), salt_block.size(), AES::DEFAULT_KEYLENGTH);

    try {
        CBC_Mode<AES>::Decryption decryption;
        decryption.SetKeyWithIV(aes_key, aes_key.size(), iv_block.data());

        StringSource ss2(binary_ciphertext, true, new StreamTransformationFilter(decryption, new StringSink(decrypted_text)));
    }
    catch (const Exception& e) {
        qDebug() << e.what();
        return QString();
    }

    return QString::fromStdString(decrypted_text);
}
