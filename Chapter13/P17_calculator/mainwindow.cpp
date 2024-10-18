#include "mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QSignalMapper>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 300);
    setWindowTitle("Simple Calculator");
    createWidgets();

    connect(pushButtonC, SIGNAL(clicked(bool)), this, SLOT(slotClear()), Qt::UniqueConnection);
    connect(pushButtonPlus, SIGNAL(clicked(bool)), this, SLOT(slotPlusEqual()), Qt::UniqueConnection);

    mMapper = new QSignalMapper(this);
    connect(pushButton, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_2, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_3, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_4, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_5, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_6, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_7, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_8, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_9, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushButton_10, SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);

    mMapper->setMapping(pushButton, 1);
    mMapper->setMapping(pushButton_2, 2);
    mMapper->setMapping(pushButton_3, 3);
    mMapper->setMapping(pushButton_4, 4);
    mMapper->setMapping(pushButton_5, 5);
    mMapper->setMapping(pushButton_6, 6);
    mMapper->setMapping(pushButton_7, 7);
    mMapper->setMapping(pushButton_8, 8);
    mMapper->setMapping(pushButton_9, 9);
    mMapper->setMapping(pushButton_10, 0);
    slotClear();

    connect(mMapper, SIGNAL(mapped(int)), this, SLOT(slotButtonPressed(int)), Qt::UniqueConnection);
}

Calculator::~Calculator() {}

void Calculator::createWidgets()
{
    QGridLayout *calcLayout = new QGridLayout;
    setLayout(calcLayout);

    lcdNumber = new QLCDNumber;
    pushButton = new QPushButton("1");
    pushButton_2 = new QPushButton("2");
    pushButton_3 = new QPushButton("3");
    pushButton_4 = new QPushButton("4");
    pushButton_5 = new QPushButton("5");
    pushButton_6 = new QPushButton("6");
    pushButton_7 = new QPushButton("7");
    pushButton_8 = new QPushButton("8");
    pushButton_9 = new QPushButton("9");
    pushButton_10 = new QPushButton("0");
    pushButtonC = new QPushButton("C");
    pushButtonPlus = new QPushButton("+/=");

    calcLayout->addWidget(lcdNumber, 0, 0, 1, 4);
    calcLayout->addWidget(pushButton, 1, 0);
    calcLayout->addWidget(pushButton_2, 1, 1);
    calcLayout->addWidget(pushButton_3, 1, 2);
    calcLayout->addWidget(pushButton_4, 2, 0);
    calcLayout->addWidget(pushButton_5, 2, 1);
    calcLayout->addWidget(pushButton_6, 2, 2);
    calcLayout->addWidget(pushButton_7, 3, 0);
    calcLayout->addWidget(pushButton_8, 3, 1);
    calcLayout->addWidget(pushButton_9, 3, 2);

    calcLayout->addWidget(pushButton_10, 4, 0, 1, 3);
    calcLayout->addWidget(pushButtonC, 1, 3);
    calcLayout->addWidget(pushButtonPlus, 2, 3, 3, 1);

    pushButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_10->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonC->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonPlus->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    lcdNumber->setFixedHeight(50);
}

void Calculator::slotClear()
{
    lcdNumber->display(0);
    mSum = 0;
    mNextNumber = 0;
}

void Calculator::slotButtonPressed(int pNum)
{
    mNextNumber = pNum;
    lcdNumber->display(pNum);
}

void Calculator::slotPlusEqual()
{
    mSum += mNextNumber;
    lcdNumber->display(mSum);
    mNextNumber = 0;
}
