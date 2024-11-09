#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(new QWidget); //Центральный виджет
    QLayout *lLayout = new QVBoxLayout;
    centralWidget()->setLayout(lLayout); //компоновщик для размещения графика
    QwtPlot *lPlot = new QwtPlot; //Визуальный элемент — График
    lLayout->addWidget(lPlot);
    QwtPlotCanvas *lCanvas = new QwtPlotCanvas(); //Объект для отображения
    lCanvas->setFrameStyle (QFrame::Box|QFrame::Plain); //нашего графика
    lPlot->setCanvas(lCanvas);
    lPlot->setAxisTitle(QwtPlot::xBottom, "x"); //Название оси — x
    lPlot->setAxisScale(QwtPlot::xBottom, -10.0, 10.0); //Границы оси x
    lPlot->setAxisTitle(QwtPlot::yLeft, "y"); //Название оси — y
    lPlot->setAxisScale(QwtPlot::yLeft, -10.0, 10.0); //Границы оси у
    new QwtPlotPanner(lCanvas); //Добавляем инструмент для перетягивания смещения
    //графика указателем мышки
    new QwtPlotMagnifier(lCanvas); //Добавляем инструмент для увеличения уменьшения
    //графика роликом мышки
}

MainWindow::~MainWindow()
{
    delete ui;
}
