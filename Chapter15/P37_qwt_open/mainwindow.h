#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class QwtPlot;
class QwtPlotCurve;
class QPlainTextEdit;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile();

private:
    void plotData(const QVector<double> &xData, const QVector<double> &yData);
    Ui::MainWindow *ui;
    QwtPlot *plot;
    QPlainTextEdit *textEdit;
    QMenuBar *menuBar;
};
#endif // MAINWINDOW_H
