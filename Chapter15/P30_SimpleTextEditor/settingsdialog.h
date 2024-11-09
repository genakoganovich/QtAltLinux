#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();
    bool isShowToolBar() const;
    void setShowToolBar(bool pShow);
    bool isShowStatusBar() const;
    void setShowStatusBar(bool pShow);
    bool isSaveGeometry() const;
    void setSaveGeometry(bool pSave);
private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
