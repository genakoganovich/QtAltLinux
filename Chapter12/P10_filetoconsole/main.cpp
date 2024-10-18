#include <QDebug>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QFile file(":/in.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString data = in.readLine();
        qDebug() << data;
        file.close();
    }
    else
    {
        qDebug() << "Cannot open file!";
    }
    return 0;
}
