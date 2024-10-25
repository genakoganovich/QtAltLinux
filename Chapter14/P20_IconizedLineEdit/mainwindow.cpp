#include "mainwindow.h"
#include "iconizedlineedit.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createUi();
}

void MainWindow::createUi()
{
    QVBoxLayout *lMainLayout = new QVBoxLayout;
    setLayout(lMainLayout);

    iconizedLineEdit = new IconizedLineEdit;
    iconizedLineEdit->setPlaceholderText("Click to open File");
    iconizedLineEdit->setIconPixmap(QPixmap("Folder.png"));
    iconizedLineEdit->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);
    lMainLayout->addWidget(iconizedLineEdit);

    iconizedLineEdit_2 = new IconizedLineEdit;
    iconizedLineEdit_2->setPlaceholderText("Enter IP address");
    iconizedLineEdit_2->setIconPixmap(QPixmap("Checkmark.png"));
    iconizedLineEdit_2->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);
    lMainLayout->addWidget(iconizedLineEdit_2);

    iconizedLineEdit_3 = new IconizedLineEdit;
    iconizedLineEdit_3->setPlaceholderText(" ");
    iconizedLineEdit_3->setIconPixmap(QPixmap("Questions.png"));
    iconizedLineEdit_3->setIconVisibility(IconizedLineEdit::IconVisibleOnTextPresence);
    lMainLayout->addWidget(iconizedLineEdit_3);

    iconizedLineEdit_4 = new IconizedLineEdit;
    iconizedLineEdit_4->setPlaceholderText("Cannot be empty");
    iconizedLineEdit_4->setIconPixmap(QPixmap("Questions.png"));
    iconizedLineEdit_4->setIconVisibility(IconizedLineEdit::IconVisibleOnEmptyText);
    lMainLayout->addWidget(iconizedLineEdit_4);

    iconizedLineEdit_5 = new IconizedLineEdit;
    iconizedLineEdit_5->setPlaceholderText("Clearable");
    iconizedLineEdit_5->setIconPixmap(QPixmap("X.png"));
    iconizedLineEdit_5->setIconVisibility(IconizedLineEdit::IconVisibleOnTextPresence);
    lMainLayout->addWidget(iconizedLineEdit_5);
}
