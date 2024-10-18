#include "person.h"

Person::Person(const QString &name, const QString &phone, const QString &address)
    : m_name(name), m_phone(phone), m_address(address) {}


QDebug operator<<(QDebug dbg, const Person &person) {
    dbg.nospace() << "Person(Name: " << person.m_name
                  << ", Phone Number: " << person.m_phone
                  << ", Address: " << person.m_address << ")";
    return dbg;
}
