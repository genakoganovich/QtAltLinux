#ifndef LEDINDICATOR_H
#define LEDINDICATOR_H

#include <QWidget>

class QString;
class QSize;
class LedIndicator: public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString Text READ Text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(bool turnedOn READ isTurnedOn WRITE setTurnedOn NOTIFY stateToggled)
public:
    explicit LedIndicator(QWidget *parent = 0);
    QString Text() const;
    bool isTurnedOn() const;
    QSize minimumSizeHint() const;
protected:
    void paintEvent(QPaintEvent *pEvent);
signals:
    void textChanged(const QString &text);
    void stateToggled(bool on);
public slots :
    void setText(const QString &pText);
    void setTurnedOn(bool pIsTurnedOn);
private :
    QString mText;
    bool mIsTurnedOn;
    static const int cLedRadius;
    static const int cLedSpacing;

};

#endif // LEDINDICATOR_H
