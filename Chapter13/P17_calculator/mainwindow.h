#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
class QPushButton;
class QLCDNumber;
class QSignalMapper;

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();
private:
    void createWidgets();

private:
    QSignalMapper *mMapper;
    int mSum;
    int mNextNumber;
    QPushButton *pushButtons[10];
    QPushButton *pushButtonPlus;
    QPushButton *pushButtonC;

    QLCDNumber *lcdNumber;

private slots:
    void slotClear();
    void slotButtonPressed(int pNum);
    void slotPlusEqual();
};
#endif // MAINWINDOW_H
