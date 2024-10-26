#include <QHBoxLayout>
#include <QCheckBox>
#include "mainwindow.h"
#include "ledindicator.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    //Главное компонование
    QHBoxLayout *lLayout = new QHBoxLayout;
    setLayout(lLayout);

    //Создаём наш индикатор и добавляем его к компоновщику
    LedIndicator * lLedIndicator = new LedIndicator;
    lLedIndicator->setText( "LED Indicator");
    lLayout->addWidget(lLedIndicator);

    //Создаём и добавляем флажок
    QCheckBox *lCheckBox = new QCheckBox("Led ON");
    lLayout->addWidget(lCheckBox);

    //Соединяем флажок и индикатор
    connect(lCheckBox, SIGNAL(toggled(bool)), lLedIndicator, SLOT(setTurnedOn(bool)), Qt::UniqueConnection);
}

MainWindow::~MainWindow() {}
