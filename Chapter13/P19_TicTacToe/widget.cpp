#include "widget.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QSignalMapper>
#include <QDebug>

const QString Widget::players[2] = {"X", "O"};
int Widget::currentPlayer = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QGridLayout *buttonsLayout = new QGridLayout();
    mMapper = new QSignalMapper(this);

    layout->addLayout(buttonsLayout);
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            pushButtons[i][j] = new QPushButton(QString(""), this);
            pushButtons[i][j]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            buttonsLayout->addWidget(pushButtons[i][j], i, j);

            connect(pushButtons[i][j], &QPushButton::clicked, mMapper, QOverload<>::of(&QSignalMapper::map), Qt::UniqueConnection);
            mMapper->setMapping(pushButtons[i][j], pushButtons[i][j]);
        }
    }
    buttonsLayout->setSpacing(0);
    buttonsLayout->setContentsMargins(0, 0, 0, 0);

    label = new QLabel(QString("Player%1").arg(currentPlayer), this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    clearButton = new QPushButton("Clear", this);
    layout->addWidget(clearButton);

    connect(clearButton, &QPushButton::clicked, this, &Widget::slotClear, Qt::UniqueConnection);
    connect(mMapper, &QSignalMapper::mappedWidget, this, &Widget::slotButtonPressed, Qt::UniqueConnection);

    setWindowTitle("Tic Tac Toe");
    resize(250, 200);
}

Widget::~Widget() {}

void Widget::slotClear()
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            pushButtons[i][j]->setText("");
        }
    }
}

void Widget::slotButtonPressed(QWidget *widget)
{
    QPushButton* button = qobject_cast<QPushButton*>(widget);
    if (button) {
        button->setText(players[currentPlayer]);
        currentPlayer ^= 1;
        label->setText(QString("Player%1").arg(currentPlayer));
    } else {
        qDebug() << "Can't cast to QPushButton";
    }
}
