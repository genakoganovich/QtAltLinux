#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_curve.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <QMessageBox>

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
    // Пути к файлу данных
    QString filePath = "/home/gena/Documents/Qt_projects/QtAltLinux/Chapter15/P36_qwt_plot_file/file.txt";
    QVector<double> xData, yData;

    // Чтение данных из файла
    if (!loadDataFromFile(filePath, xData, yData)) {
        return;
    }

    // Установить автоматическое масштабирование на обеих осях
    lPlot->setAxisAutoScale(QwtPlot::xBottom, true); // Автоматическое масштабирование по оси X
    lPlot->setAxisAutoScale(QwtPlot::yLeft, true);   // Автоматическое масштабирование по оси Y

    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setSamples(xData, yData);
    curve->attach(lPlot);
    lPlot->replot(); // Перерисовать график с учётом новых данных и масштабов
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::loadDataFromFile(const QString &filePath, QVector<double> &xData, QVector<double> &yData)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Unable to open file!");
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        int x, y;
        in >> x >> y;
        if (in.status() == QTextStream::Ok) {
            xData.append(x);
            yData.append(y);
        }
    }

    file.close();
    return true;
}
