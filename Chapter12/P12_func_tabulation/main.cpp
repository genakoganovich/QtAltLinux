#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

double function(double x) {
    return x * x; // Пример функции: y = x^2
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString filePath = "output.txt"; // Задаем адрес текстового файла
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing!";
        return 1;
    }

    QTextStream out(&file);
    out << "x\ty\n"; // Заголовок таблицы

    // Табулируем функцию для значений x от -10 до 10 с шагом 1
    for (int x = -10; x <= 10; ++x) {
        double y = function(x);
        out << x << "\t" << y << "\n"; // Записываем значения в файл
    }

    file.close();
    qDebug() << "Tabulation complete. Data written to" << filePath;

    return 0;
}
