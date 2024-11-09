#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class QString;
class SettingsDialog;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static int getTIME_OUT();

private:
    Ui::MainWindow *ui;
    QString mFileName;
    SettingsDialog * mSettingsDialog;
    static const QString SETTINGS_GROUP_VIEW;
    static const QString SETTING_SHOW_TOOLBAR;
    static const QString SETTING_SHOW_STATUS_BAR;
    static const QString SETTING_SAVE_GEOMETRY;
    static const QString SETTING_GEOMETRY;
    static const int TIME_OUT;
    void updateTitle();
    bool askForFileSaveAndclose();
    void readSettings();
    void writeSettings();
    void applySettings();
    void restoreGeometrySettings();

private slots:
    void slotNew();
    void slotOpen();
    void slotSave();
    void slotAboutProgram();
    void showPreferencesDialog();
    void slotPreferencesAccepted();
    void slotStatusBarMessage();

protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
