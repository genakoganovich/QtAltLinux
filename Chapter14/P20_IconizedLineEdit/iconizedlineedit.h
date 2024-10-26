#ifndef ICONIZEDLINEEDIT_H
#define ICONIZEDLINEEDIT_H
#include <QLineEdit>

class QLabel;

class IconizedLineEdit: public QLineEdit
{
    Q_OBJECT
public:
    enum IconVisibilityMode
    {
        IconAlwaysVisible = 0,
        IconVisibleOnHover,
        IconVisibleOnTextPresence,
        IconVisibleOnEmptyText,
        IconAlwaysHidden
    };
    explicit IconizedLineEdit(QWidget *parent = 0);
    bool isIconVisible() const;
    void setIconPixmap(const QPixmap &pPixmap);
    void setIconTooltip(const QString &pToolTip);
    void setIconVisibility(IconVisibilityMode pIconVisibilityMode);
    void setIconClickable(bool pIsIconClickable);
signals:
    void iconPressed();
private slots:
    void slotTextChanged(const QString &pText);
private:
    QLabel *mIconLabel;
    IconVisibilityMode mIconVisibilityMode;
    bool mIsIconClickable;
    void updateIconPositionAndsize();
    void setIconVisible(bool pisVisible);
protected:
    void resizeEvent(QResizeEvent *pEvent) override;
    bool eventFilter(QObject *pobject, QEvent *pEvent);
};

#endif // ICONIZEDLINEEDIT_H
