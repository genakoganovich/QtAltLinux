#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;
class QSlider;
class QScrollBar;
class QPushButton;
class QLineEdit;
class QString;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QLabel *label;
    QSlider *slider;
    QScrollBar *scrollbar;
    QPushButton *button;
    QLineEdit *lineEdit;

private slots:
    void onSliderChange(int value);
    void onScrollChange(int value);
    void onTextChanged(const QString &text);
    void onButtonClick();
};
#endif // MAINWINDOW_H
