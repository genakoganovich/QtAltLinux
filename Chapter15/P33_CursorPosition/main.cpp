#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Пример QPlainTextEdit с cursorPositionChanged");
    window.resize(400, 300);
    window.show();
    return app.exec();
}
