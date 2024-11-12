#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_curve.h>

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

    // Данные для графика
    QwtPlotCurve *curve = new QwtPlotCurve();
    double x[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    double y[10] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
    curve->setSamples(x, y, 10);
    curve->attach(lPlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}
