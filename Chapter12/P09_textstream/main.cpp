#include <QDebug>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QTextStream in(stdin);
    QFile file("in.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QString data = in.readLine();
        file.write(qPrintable(data));
        file.close();
    }
    else
    {
        qDebug() << "Cannot open file!";
    }
    return 0;
}
