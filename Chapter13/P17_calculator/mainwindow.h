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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;

    QPushButton *pushButtonPlus;
    QPushButton *pushButtonC;

    QLCDNumber *lcdNumber;

private slots:
    void slotClear();
    void slotButtonPressed(int pNum);
    void slotPlusEqual();
};
#endif // MAINWINDOW_H
