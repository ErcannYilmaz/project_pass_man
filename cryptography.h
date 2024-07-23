#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QCryptographicHash>
#include <QRandomGenerator>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/hex.h>
#include <cryptopp/base64.h>

using namespace CryptoPP;
using namespace std;

std::pair<QByteArray, QByteArray> hash_password(const QString &password);
QByteArray hash_password(const QString &password, const QString &salt);
QString encrypt_aes(const QString& plaintext, const QString& key, QString& saltOut, QString& ivOut);
QString decrypt_aes(const QString& ciphertext, const QString& key, const QString& salt, const QString& iv);
SecByteBlock derive_key(const QString& password, const CryptoPP::byte* salt, size_t saltSize, size_t keyLength);
QString to_hex_string(const CryptoPP::byte* data, size_t length);
SecByteBlock from_hex_string(const QString& hexString);

#endif // CRYPTOGRAPHY_H
