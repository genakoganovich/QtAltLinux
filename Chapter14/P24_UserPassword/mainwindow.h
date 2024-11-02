#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "iconizedlineedit.h"

class QPushButton;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    IconizedLineEdit *usernameLineEdit;
    IconizedLineEdit *passwordLineEdit;
    QPushButton *loginButton;
};

#endif // MAINWINDOW_H
