#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
class IconizedLineEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    void createUi();
private:
    IconizedLineEdit *iconizedLineEdit;
    IconizedLineEdit *iconizedLineEdit_2;
    IconizedLineEdit *iconizedLineEdit_3;
    IconizedLineEdit *iconizedLineEdit_4;
    IconizedLineEdit *iconizedLineEdit_5;
};
#endif // MAINWINDOW_H
