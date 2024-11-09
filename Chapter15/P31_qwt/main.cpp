#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;

    QwtPlot *plot = new QwtPlot(&window);
    plot->setTitle("Простой график");
    plot->setCanvasBackground(Qt::white);
    plot->setAxisScale(QwtPlot::yLeft, 0.0, 10.0);
    plot->setAxisScale(QwtPlot::xBottom, 0.0, 10.0);

    // Данные для графика
    QwtPlotCurve *curve = new QwtPlotCurve();
    double x[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    double y[10] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
    curve->setSamples(x, y, 10);
    curve->attach(plot);

    window.setCentralWidget(plot);
    window.resize(800, 600);
    window.show();

    return a.exec();
}
