#include <QCoreApplication>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString mainStr = "string";
    mainStr += ' ';
    (mainStr += "is") += ' ';
    qDebug() << mainStr;

    QString helperStr1("composed");
    mainStr += helperStr1;
    qDebug() << mainStr;

    QString helperStr2 = + ' ' + QString("from") + ' ';
    mainStr.append(helperStr2);
    qDebug() << mainStr;

    mainStr.push_back("fragments");
    qDebug() << mainStr;

    mainStr.prepend("This ");
    qDebug() << mainStr;

    mainStr.insert(mainStr.length(), ".");
    qDebug() << mainStr;

    mainStr += QString(2, '.');
    qDebug() << mainStr;

    mainStr = mainStr.rightJustified(mainStr.length() + 8, ' ');
    qDebug() << mainStr;

    QString quote = "This is sentence one. This is sentence two.";
    qDebug() << quote;

    QString fragment1 = quote.left(5);
    qDebug() << "Fragment1 is: " << fragment1;

    QString sentence = quote.section('.', 0, 0);
    qDebug() << "Sentence is: " << sentence;

    QStringList wordsList = sentence.split(' ', Qt::SkipEmptyParts);
    qDebug() << wordsList;

    qDebug() << "QString().isNull()" <<  QString().isNull();
    qDebug() << "QString().isEmpty()" << QString().isEmpty();
    qDebug() << "QString(\"\").isNull()" <<  QString("").isNull();
    qDebug() << "QString(\"\").isEmpty()" << QString("").isEmpty();
    qDebug() << "QString(\"abc\").isNull()" << QString("abc").isNull();
    qDebug() << "QString(\"abc\").isEmpty()" << QString("abc").isEmpty();

    QString qtStringInitial = "I am a standard STL string";
    qDebug() << "QString qtStringInitial: " << qtStringInitial;
    std::string stdString = qtStringInitial.toStdString();
    QString qtString = QString::fromStdString(stdString);
    qDebug() << "QString qtString: " << qtString;

    int x = 16;
    QString xStr = QString::number(x);
    qDebug() << "x = " << x << ", QString::number(x) = " << xStr;

    int y = xStr.toInt();
    qDebug() << "xStr = " << xStr << ", xStr.toInt() = " << y;

    double teta = 12099.10012021210102109991;
    QString tetaStr = QString::number(teta);
    qDebug() << "teta = " << teta << ", QString::number(teta) = " << tetaStr;

    tetaStr.setNum(teta);
    qDebug() << "teta = " << teta << ", tetaStr.setNum(teta) = " << tetaStr;

    tetaStr = QString::number(teta, 'f', 4);
    qDebug() << "teta = " << teta << ", QString::number(teta, 'f', 4) = " << tetaStr;

    tetaStr = QString::number(teta, 'e');
    qDebug() << "teta = " << teta << ", QString::number(teta, 'e') = " << tetaStr;

    xStr = QString("int %1 is %2 in decimal system , %3 in binary system , and %4 in hexadecimal")
               .arg(x).arg(x, 0, 10)
               .arg(x, 0, 2)
               .arg(x, 0, 16);
    qDebug() << xStr;

    return a.exec();
}
