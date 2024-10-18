#include <QCoreApplication>
#include <QDebug>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file(":/in.txt");
    // if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        while (!in.atEnd()) {
            qDebug() << qPrintable(in.readLine());
        }
        file.close();
    }
    else
    {
        qDebug() << "Cannot open file!";
    }
    return 0;
}
