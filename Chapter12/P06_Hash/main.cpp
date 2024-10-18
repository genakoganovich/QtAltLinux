#include <QCoreApplication>
#include <QHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString, QString> classificationHash;
    classificationHash.insertMulti("fruits", "apple");
    classificationHash.insertMulti("fruits", "orange");
    classificationHash.insertMulti("vegetables", "potato");
    classificationHash.insertMulti("vegetables", "cabbage");
    classificationHash.insertMulti("vegetables", "tomato");

    qDebug() << classificationHash.value("fruits");
    qDebug() << classificationHash.values("fruits");
    qDebug() << classificationHash.values("vegetables");

    return a.exec();
}
