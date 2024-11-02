#include "iconizedlineedit.h"
#include <QStyle>
#include <QLabel>
#include <QEvent>

IconizedLineEdit::IconizedLineEdit(QWidget *parent) : QLineEdit (parent), mIconVisibilityMode(IconAlwaysVisible)
{
    mIconLabel = new QLabel(this);
    mIconLabel->installEventFilter(this);
    connect(this, SIGNAL(textChanged(QString)), this, SLOT(slotTextChanged(QString)), Qt::UniqueConnection);
}

bool IconizedLineEdit::isIconVisible() const
{
    return mIconLabel->isVisible();
}

void IconizedLineEdit::setIconPixmap(const QPixmap &pPixmap)
{
    mIconLabel->setPixmap(pPixmap);
    updateIconPositionAndsize();
}

void IconizedLineEdit::setIconTooltip(const QString &pToolTip)
{
    mIconLabel->setToolTip(pToolTip);
}

void IconizedLineEdit::setIconVisibility(IconVisibilityMode pIconVisibilityMode)
{
    mIconVisibilityMode = pIconVisibilityMode;

    switch (pIconVisibilityMode)
    {
    case IconAlwaysVisible :
        setIconVisible(true);
        break;
    case IconVisibleOnEmptyText :
    case IconVisibleOnTextPresence :
        slotTextChanged(text());
        break;
    default :
        setIconVisible(false);
        break;
    }
}

//Установить режим реакции на нажатие мышкой на пиктограмму
void IconizedLineEdit::setIconClickable(bool pIsIconClickable)
{
    mIsIconClickable = pIsIconClickable;
    //Устанавливаем вид курсора при наведении на метку с пиктограммой
    if (mIsIconClickable)
    {
        mIconLabel->setCursor(Qt::PointingHandCursor);
    }
    else
    {
        mIconLabel->setCursor(Qt::ArrowCursor);
    }
}

void IconizedLineEdit::updateIconPositionAndsize()
{
    mIconLabel->setScaledContents(true);
    mIconLabel->setFixedSize(height(), height());

    QSize lsize = mIconLabel->size();
    mIconLabel->move(rect().right() - lsize.width(), (rect().bottom() + 1 - lsize.height()) / 2);

    if (mIconLabel->isVisible())
    {
        QMargins lMargins = textMargins();
        lMargins.setRight(mIconLabel->size().width() + 1);
        setTextMargins(lMargins);
    }
    else
    {
        setTextMargins(QMargins(0, 0, 0, 0));
    }
}

void IconizedLineEdit::setIconVisible(bool pisVisible)
{
    mIconLabel->setVisible(pisVisible);
}

void IconizedLineEdit::slotTextChanged(const QString &pText)
{
    if (IconVisibleOnEmptyText == mIconVisibilityMode)
    {
        setIconVisible(pText.isEmpty());
    }
    else if (IconVisibleOnTextPresence == mIconVisibilityMode)
    {
        setIconVisible(!pText.isEmpty());
    }
}
//Событие изменения размера виджета
void IconizedLineEdit::resizeEvent(QResizeEvent *pEvent)
{
    //Если изменение размера состоялось, обновить позицию и размер пиктограммы
    updateIconPositionAndsize();
    QWidget::resizeEvent(pEvent);
}

bool IconizedLineEdit::eventFilter(QObject *pobject, QEvent *pEvent)
{
    if (mIsIconClickable)
    {
        if ((pobject == mIconLabel) && (pEvent->type() == QEvent::MouseButtonPress))
        {
            emit iconPressed();
            return true;
        }
    }
    return false;
}
