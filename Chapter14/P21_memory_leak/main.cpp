#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

int main (int argc, char *argv[])
{
    QApplication lApplication(argc, argv);
    //(1) Память в динамически-распределяемой памяти (heap)
    QWidget *lSomeWidget = new QWidget(0); //Окно
    //Задаём родительский виджет с помощью конструктора
    QLabel *lLabel = new QLabel(lSomeWidget);
    //Задаём родительский виджет с помощью метода QObject::setparent ( )
    QPushButton *lPushButton = new QPushButton;
    lPushButton->setParent(lSomeWidget);
    lLabel->setText("Label");
    lLabel->move(10, 10);
    lPushButton->setText("Button");
    lPushButton->move(50, 10);
    //(1) Память в динамически-распределяемой памяти (heap)
    lSomeWidget->resize(150, 50);
    lSomeWidget->show();
    int exitCode = lApplication.exec();
    delete lSomeWidget;
    return exitCode;
}
