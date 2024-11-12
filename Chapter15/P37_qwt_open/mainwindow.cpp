#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    // Создаем компоненты: меню, текстовый редактор и график
    menuBar = new QMenuBar(this);
    textEdit = new QPlainTextEdit(this);
    textEdit->setReadOnly(true);
    plot = new QwtPlot(this);

    // Создаем меню и действие "Open"
    QMenu *fileMenu = menuBar->addMenu("File");
    QAction *openAction = fileMenu->addAction("Open");
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

    // Размещаем компоненты на форме
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setMenuBar(menuBar);

    QHBoxLayout *contentLayout = new QHBoxLayout();
    contentLayout->addWidget(textEdit, 1); // Растягиваем textEdit на 1 часть
    contentLayout->addWidget(plot, 2);     // Растягиваем график на 2 части
    mainLayout->addLayout(contentLayout);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (fileName.isEmpty()) return;

    QVector<double> xData, yData;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContent;

        while (!in.atEnd()) {
            QString line = in.readLine();
            fileContent += line + "\n"; // Сохраняем содержимое для показа в textEdit

            QStringList values = line.split(QRegExp("\\s+"), Qt::SkipEmptyParts);
            if (values.size() == 2) {
                xData.append(values[0].toDouble());
                yData.append(values[1].toDouble());
            }
        }
        file.close();

        // Отображаем содержимое файла в textEdit
        textEdit->setPlainText(fileContent);
    }

    plotData(xData, yData);
}

void MainWindow:: plotData(const QVector<double> &xData, const QVector<double> &yData) {
    QwtPlotCurve *curve = new QwtPlotCurve("Data Curve");
    curve->setSamples(xData, yData);

    // Стиль линии
    QPen pen(Qt::blue);
    pen.setWidth(2);
    curve->setPen(pen);

    // Стиль точек
    QwtSymbol *symbol = new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::red), QSize(6, 6));
    curve->setSymbol(symbol);

    curve->attach(plot);
    plot->replot();
}

