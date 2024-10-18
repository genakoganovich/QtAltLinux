#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QDebug>

class Person
{
    QString m_name;
    QString m_phone;
    QString m_address;
public:
    friend QDebug operator<<(QDebug dbg, const Person &person);
    Person(const QString &name, const QString &phone, const QString &address);
};



#endif // PERSON_H
