#include "mainwindow.h"
#include <QValidator>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QValidator *validator = new QIntValidator(100, 999, this);
    QLineEdit *edit = new QLineEdit(this);

    // the edit lineedit will only accept integers between 100 and 999
    edit->setValidator(validator);
}

MainWindow::~MainWindow() {}
