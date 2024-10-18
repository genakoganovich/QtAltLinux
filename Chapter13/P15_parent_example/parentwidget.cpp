#include "parentwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

ParentWidget::ParentWidget(QWidget *parent)
    : QWidget{parent}
{
    QLabel *label = new QLabel(this);
    label->setGeometry(50, 0, 100, 30);
    label->setText("Text Label");

    QPushButton *pushButton = new QPushButton(this);
    pushButton->setGeometry(50, 50, 100, 30);
    pushButton->setText("PushButton");

    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(50, 100, 100, 30);
    lineEdit->setText("LineEdit");
    lineEdit->selectAll();

    setGeometry(x(), y(), 300, 150);
    setWindowTitle("Parent Widget Example");
}
