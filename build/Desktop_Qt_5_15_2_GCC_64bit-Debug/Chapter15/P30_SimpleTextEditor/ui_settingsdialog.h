/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *saveGeometryCheckBox;
    QCheckBox *showToolbarCheckBox;
    QCheckBox *showStatusBarCheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(1053, 150);
        SettingsDialog->setModal(true);
        verticalLayout = new QVBoxLayout(SettingsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(SettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveGeometryCheckBox = new QCheckBox(groupBox);
        saveGeometryCheckBox->setObjectName(QString::fromUtf8("saveGeometryCheckBox"));

        horizontalLayout->addWidget(saveGeometryCheckBox);

        showToolbarCheckBox = new QCheckBox(groupBox);
        showToolbarCheckBox->setObjectName(QString::fromUtf8("showToolbarCheckBox"));

        horizontalLayout->addWidget(showToolbarCheckBox);

        showStatusBarCheckBox = new QCheckBox(groupBox);
        showStatusBarCheckBox->setObjectName(QString::fromUtf8("showStatusBarCheckBox"));

        horizontalLayout->addWidget(showStatusBarCheckBox);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Settings", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingsDialog", "View Settings", nullptr));
        saveGeometryCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Save Geometry", nullptr));
        showToolbarCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Show Toolbar", nullptr));
        showStatusBarCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Show Status Bar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
