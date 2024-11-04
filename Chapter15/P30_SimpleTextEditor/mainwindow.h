#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class QString;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString mFileName;
    void updateTitle();
    bool askForFileSaveAndclose();

private slots:
    void slotNew();
    void slotOpen();
    void slotSave();
    void slotAboutProgram();
};
#endif // MAINWINDOW_H
