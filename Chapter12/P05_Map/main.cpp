#include <QCoreApplication>
#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, QString> surnameByName;
    surnameByName.insert("Bill", "Hunter");
    surnameByName.insert("Marry", "Lee");

    qDebug() << "Bill" << surnameByName.value("Bill");
    qDebug() << "Marry" << surnameByName.value("Marry");

    surnameByName.insert("Marry", "Hunter");
    qDebug() << "Marry" << surnameByName.value("Marry");

    qDebug() << "James" << surnameByName.value("James");
    qDebug() << "John" << surnameByName.value("John", "Doe");


    return a.exec();
}
