#include "mainwindow.h"
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QSignalMapper>

const QString Calculator::op = "+-*/=";

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
    buttonLabels{"1", "2", "3", "C",
                 "4", "5", "6", "+",
                 "7", "8", "9", "-",
                 "0", "*", "/", "="
                }
{
    resize(300, 300);
    setWindowTitle("Simple Calculator");
    createWidgets();

    mMapper = new QSignalMapper(this);
    for (int i = 0; i < size; ++i) {
        if (buttonLabels[i] == "C") {

            connect(pushButtons[i], SIGNAL(clicked(bool)), this, SLOT(slotClear()), Qt::UniqueConnection);

        } else if (op.contains(buttonLabels[i])) {

            connect(pushButtons[i], SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
            mMapper->setMapping(pushButtons[i], buttonLabels[i]);
        } else {

            connect(pushButtons[i], SIGNAL(clicked(bool)), mMapper, SLOT(map()), Qt::UniqueConnection);
            mMapper->setMapping(pushButtons[i], buttonLabels[i].toInt());
        }
    }

    slotClear();
    connect(mMapper, SIGNAL(mapped(int)), this, SLOT(slotButtonPressed(int)), Qt::UniqueConnection);
    connect(mMapper, SIGNAL(mapped(QString)), this, SLOT(slotOperator(QString)), Qt::UniqueConnection);
}

Calculator::~Calculator() {}

void Calculator::createWidgets()
{
    QGridLayout *calcLayout = new QGridLayout;
    setLayout(calcLayout);

    lcdNumber = new QLCDNumber;

    for (int i = 0; i < size; ++i) {
        pushButtons[i] = new QPushButton(buttonLabels[i], this);
        pushButtons[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    }


    calcLayout->addWidget(lcdNumber, 0, 0, 1, 4);

    for (int i = 0; i < size; ++i) {
        int row = 1 + (i / 4);
        int col = i % 4;

        calcLayout->addWidget(pushButtons[i], row, col);
    }

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

void Calculator::slotOperator(const QString& s)
{
    if(s == "+")
    {
        mSum += mNextNumber;
        lcdNumber->display(mSum);
        mNextNumber = 0;
    }
}
