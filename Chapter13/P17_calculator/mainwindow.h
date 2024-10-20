#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
class QString;
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
    static const int size = 16;
    const QString buttonLabels[size];
    static const QString op;
    QSignalMapper *mMapper;
    int mSum;
    int mNextNumber;
    QPushButton *pushButtons[size];
    QLCDNumber *lcdNumber;

private slots:
    void slotClear();
    void slotButtonPressed(int pNum);
    void slotOperator(const QString& s);
};
#endif // MAINWINDOW_H
