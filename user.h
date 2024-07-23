#ifndef USER_H
#define USER_H

class User
{
public:
    // Constructor
    User(int id, const QString &username, const QString &password, const QString &salt);



private:
    int m_id;
    QString m_username;
    QString m_password;
    QString m_salt;
};

#endif // USER_H
