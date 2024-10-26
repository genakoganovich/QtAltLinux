#include "iconlineedit.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Создаем основное окно
    IconLineEdit window;
    window.setWindowTitle("QLineEdit with Icon");
    window.resize(300, 50);
    window.show();

    return app.exec();
}
