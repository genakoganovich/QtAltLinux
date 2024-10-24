#include "mainwindow.h"
#include <QLabel>
#include <QSlider>
#include <QScrollBar>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    label = new QLabel("Move the slider or scroll", this);
    slider = new QSlider(Qt::Horizontal, this);
    scrollbar = new QScrollBar(Qt::Horizontal, this);
    button = new QPushButton("Clear Text", this);
    lineEdit = new QLineEdit(this);


    slider->setMinimum(0);
    slider->setMaximum(100);
    scrollbar->setMinimum(0);
    scrollbar->setMaximum(100);


    layout->addWidget(label);
    layout->addWidget(slider);
    layout->addWidget(scrollbar);
    layout->addWidget(button);
    layout->addWidget(lineEdit);

    setWindowTitle("Signal slot example");
    resize(400, 300);

    // Соединение сигналов и слотов
    connect(slider, &QSlider::valueChanged, this, &MainWindow::onSliderChange);
    connect(scrollbar, &QScrollBar::valueChanged, this, &MainWindow::onScrollChange);
    connect(lineEdit, &QLineEdit::textChanged, this, &MainWindow::onTextChanged);
    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClick);

    // Связываем слайдер и полосу прокрутки
    connect(slider, &QSlider::valueChanged, scrollbar, &QScrollBar::setValue);
    connect(scrollbar, &QScrollBar::valueChanged, slider, &QSlider::setValue);

}

MainWindow::~MainWindow() {}

void MainWindow::onSliderChange(int value)
{
    label->setText(QString("Slider Value: %1").arg(value));
}

void MainWindow::onScrollChange(int value)
{
    label->setText(QString("Scrollbar Value: %1").arg(value));
}

void MainWindow::onTextChanged(const QString &text)
{
    label->setText(QString("Text: %1").arg(text));
}

void MainWindow::onButtonClick()
{
    lineEdit->clear();
    label->setText("Text Cleared");
}
