#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QHash>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
    list.append(3);
    list.append(6);
    list.append(9);

    // Java like iterator
    QListIterator<int> it(list);
    while(it.hasNext())
    {
        qDebug() << it.next();
    }


    QHash<QString, int> numberByName;
    numberByName.insert("twelve", 12);
    numberByName.insert("thirty three", 33);
    numberByName.insert("one hundred and twenty file", 125);


    QHashIterator<QString, int> hashIterator(numberByName);
    while(hashIterator.hasPrevious())
    {
        hashIterator.previous();
        qDebug() << hashIterator.key() << " - " << hashIterator.value();
    }

    // STL like iterator
    QHash<QString, int>::iterator stlLikeIterator;
    for(stlLikeIterator = numberByName.begin(); stlLikeIterator != numberByName.end(); stlLikeIterator++)
    {
        qDebug() << stlLikeIterator.key() << " - " << stlLikeIterator.value();
    }
    return a.exec();
}
