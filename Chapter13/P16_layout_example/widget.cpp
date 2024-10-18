#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLineEdit *lineEdit = new QLineEdit("Text 1");
    QLabel *label = new QLabel("Line Edit &1");
    label->setBuddy(lineEdit);

    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    hBoxLayout->addWidget(label);
    hBoxLayout->addWidget(lineEdit);

    QLineEdit *lineEdit2 = new QLineEdit("Text 2");
    QLabel *label2 = new QLabel("Line Edit &2");
    label2->setBuddy(lineEdit2);

    QHBoxLayout *hBoxLayout2 = new QHBoxLayout;
    hBoxLayout2->addWidget(label2);
    hBoxLayout2->addWidget(lineEdit2);

    QPushButton *pushButtonOk = new QPushButton("&Ok");
    QPushButton *pushBottonCancel = new QPushButton("&Cancel");
    QHBoxLayout *hBoxLayout3 = new QHBoxLayout;
    hBoxLayout3->addStretch();
    hBoxLayout3->addWidget(pushButtonOk);
    hBoxLayout3->addWidget(pushBottonCancel);

    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    vBoxLayout->addLayout(hBoxLayout);
    vBoxLayout->addLayout(hBoxLayout2);
    vBoxLayout->addLayout(hBoxLayout3);

    setLayout(vBoxLayout);
    setWindowTitle("LayoutExample");
}

Widget::~Widget() {}
