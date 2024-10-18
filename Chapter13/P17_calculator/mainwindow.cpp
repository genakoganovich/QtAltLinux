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
    for (int i = 0; i < 10; ++i)
    {
        connect(pushButtons[i], SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
        mMapper->setMapping(pushButtons[i], i);
    }

    slotClear();
    connect(mMapper, SIGNAL(mapped(int)), this, SLOT(slotButtonPressed(int)), Qt::UniqueConnection);
}

Calculator::~Calculator() {}

void Calculator::createWidgets()
{
    QGridLayout *calcLayout = new QGridLayout;
    setLayout(calcLayout);

    lcdNumber = new QLCDNumber;

    for (int i = 0; i < 10; ++i) {
        pushButtons[i] = new QPushButton(QString::number(i), this);
        pushButtons[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    }

    pushButtonC = new QPushButton("C");
    pushButtonPlus = new QPushButton("+/=");

    calcLayout->addWidget(lcdNumber, 0, 0, 1, 4);

    for (int i = 1; i < 10; ++i)
    {
        int row = 1 + (i - 1) / 3;
        int col = (i - 1) % 3;

        calcLayout->addWidget(pushButtons[i], row, col);
    }
    calcLayout->addWidget(pushButtons[0], 4, 0, 1, 3);

    calcLayout->addWidget(pushButtonC, 1, 3);
    calcLayout->addWidget(pushButtonPlus, 2, 3, 3, 1);

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
