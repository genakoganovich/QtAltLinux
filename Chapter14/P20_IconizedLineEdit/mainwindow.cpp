#include "mainwindow.h"
#include "iconizedlineedit.h"
#include <QVBoxLayout>
#include <QFileDialog>

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
    iconizedLineEdit->setIconPixmap(QPixmap(":/resources/Folder.png"));
    iconizedLineEdit->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);
    iconizedLineEdit->setIconClickable(true);
    connect(iconizedLineEdit, SIGNAL(iconPressed()), this, SLOT(slotChooseFile()), Qt::UniqueConnection);
    lMainLayout->addWidget(iconizedLineEdit);

    iconizedLineEdit_2 = new IconizedLineEdit;
    iconizedLineEdit_2->setPlaceholderText("Enter IP address");
    iconizedLineEdit_2->setIconPixmap(QPixmap(":/resources/Checkmark.png"));
    iconizedLineEdit_2->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);
    lMainLayout->addWidget(iconizedLineEdit_2);

    iconizedLineEdit_3 = new IconizedLineEdit;
    iconizedLineEdit_3->setPlaceholderText(" ");
    iconizedLineEdit_3->setIconPixmap(QPixmap(":/resources/Questions.png"));
    iconizedLineEdit_3->setIconVisibility(IconizedLineEdit::IconVisibleOnTextPresence);
    lMainLayout->addWidget(iconizedLineEdit_3);

    iconizedLineEdit_4 = new IconizedLineEdit;
    iconizedLineEdit_4->setPlaceholderText("Cannot be empty");
    iconizedLineEdit_4->setIconPixmap(QPixmap(":/resources/Warning.png"));
    iconizedLineEdit_4->setIconVisibility(IconizedLineEdit::IconVisibleOnEmptyText);
    lMainLayout->addWidget(iconizedLineEdit_4);

    iconizedLineEdit_5 = new IconizedLineEdit;
    iconizedLineEdit_5->setPlaceholderText("Clearable");
    iconizedLineEdit_5->setIconPixmap(QPixmap(":/resources/X.png"));
    iconizedLineEdit_5->setIconVisibility(IconizedLineEdit::IconVisibleOnTextPresence);
    iconizedLineEdit_5->setIconClickable(true);
    connect(iconizedLineEdit_5, SIGNAL(iconPressed()), iconizedLineEdit_5, SLOT(clear()), Qt::UniqueConnection);
    lMainLayout->addWidget(iconizedLineEdit_5);
}

void MainWindow::slotChooseFile()
{
    QString lFileName = QFileDialog::getOpenFileName(this, "open File");
    iconizedLineEdit->setText(lFileName);
}
