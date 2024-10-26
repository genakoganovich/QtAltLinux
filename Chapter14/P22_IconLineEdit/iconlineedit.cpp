#include "iconlineedit.h"
#include <QLineEdit>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>

IconLineEdit::IconLineEdit(QWidget *parent)
    : QWidget(parent)
{
    // Создаем QLineEdit
    QLineEdit* lineEdit = new QLineEdit(this);

    // Создаем QLabel для отображения иконки
    QLabel* iconLabel = new QLabel(this);

    // Устанавливаем QPixmap в QLabel
    // Путь к изображению (иконке)

    // Уменьшаем изображение до 24x24
    QPixmap scaledPixmap =  QPixmap(":/resources/icon.png")
                               .scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    iconLabel->setPixmap(scaledPixmap);

    // Создаем горизонтальный компоновщик
    QHBoxLayout* layout = new QHBoxLayout(this);

    // Добавляем QLabel (иконку) и QLineEdit в компоновщик
    layout->addWidget(iconLabel);
    layout->addWidget(lineEdit);

    // Устанавливаем отступы в компоновщике, чтобы иконка и текст не слипались
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(5);
}

IconLineEdit::~IconLineEdit() {}
