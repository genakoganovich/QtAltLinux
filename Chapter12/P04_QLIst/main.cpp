#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> list;
    QString str1("string1");
    QString str2("string2");
    list << str1 << str2;
    qDebug() << list;

    list.prepend(str1);
    qDebug() << list;

    list.append("string3");
    qDebug() << list;

    list << "string4";
    qDebug() << list;

    qDebug() << list.first();
    qDebug() << list.last();

    if(list.size() > 3) qDebug() << list.at(3);

    return a.exec();
}
