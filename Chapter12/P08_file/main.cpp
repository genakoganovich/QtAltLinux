#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    const QString fileName(":/file.txt");

    if(!QFile::exists(fileName))
    {
        qCritical("File %s does not exist.", qPrintable(fileName));
        return 1;
    }
    QFile file;
    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical("Error %d : %s.", file.error(), qPrintable(file.errorString()));
        return 2;
    }

    while (!file.atEnd()) {
        qDebug() << file.readLine();
    }

    file.close();
    return 0;
}
