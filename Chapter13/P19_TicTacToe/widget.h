#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QSignalMapper;
class QPushButton;
class QLabel;
class QString;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    static int currentPlayer;
    static const QString players[2];
    static const int size = 3;
    QSignalMapper *mMapper;
    QPushButton *pushButtons[size][size];
    QLabel *label;
    QPushButton *clearButton;

private slots:
    void slotClear();
    void slotButtonPressed(QWidget* widget);
};
#endif // WIDGET_H
