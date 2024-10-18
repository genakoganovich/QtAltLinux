#include <QApplication>
#include "parentwidget.h"

int main(int argc, char *argv[])
{
    QApplication appication(argc, argv);

    ParentWidget parentWidget;
    parentWidget.move(100, 200);
    parentWidget.show();

    return appication.exec();
}
