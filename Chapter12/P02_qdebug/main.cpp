#include <QCoreApplication>
#include <QDebug>

struct complex
{
    double re;
    double im;
};

QDebug operator << (QDebug dbg, const complex &c)
{
    dbg.nospace() << "(" << c.re << " + i*" << c.im << ")";
    return dbg.space();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hello, " << "this is debug output";
    qDebug() << "Integer values: " << 1 << 10 << 100;
    qDebug() << "Doubles and floats: " << .1 << .123 << 0.112345;
    qDebug() << "Characters: " << 'c' << '\t' << '$' << '\n' << "newline";
    qDebug() << "Booleans: " << true << false;
    qDebug() << "Pointers: " << argv;
    qDebug() << "and much more...";
    //Вывод собственного типа данных
    complex c;
    c.re = 0.2;
    c.im = 1.5;
    qDebug() << "including custom types: " << c;

    return a.exec();
}
