#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QPlainTextEdit;
class QLabel;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPlainTextEdit *textEdit;
    QLabel *cursorPositionLabel;

private slots:
    void onCursorPositionChanged();
};
#endif // MAINWINDOW_H
