#include "iconizedlineedit.h"
#include <QStyle>
#include <QLabel>

IconizedLineEdit::IconizedLineEdit(QWidget *parent) : QLineEdit (parent), mIconVisibilityMode(IconAlwaysVisible)
{
    mIconLabel = new QLabel(this);
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

void IconizedLineEdit::updateIconPositionAndsize()
{
    mIconLabel->setScaledContents(true);
    mIconLabel->setFixedSize(height(), height());

    QSize lsize = mIconLabel->size();
    mIconLabel->move(rect().right() - lsize.width(), (rect().bottom() + 1 - lsize.height()) / 2 );

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
