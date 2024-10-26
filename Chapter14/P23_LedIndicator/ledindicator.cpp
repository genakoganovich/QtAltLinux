#include "ledindicator.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <QPainterPath>
#include <QRect>
#include <QRadialGradient>

const int LedIndicator::cLedRadius = 7;
const int LedIndicator::cLedSpacing = 5;

LedIndicator::LedIndicator(QWidget *parent)
    : QWidget(parent), mIsTurnedOn(false)
{}

QString LedIndicator::Text() const
{
    return mText;
}

bool LedIndicator::isTurnedOn() const
{
    return mIsTurnedOn;
}

QSize LedIndicator::minimumSizeHint() const
{
    return QSize(cLedRadius * 2 //Диаметр индикатора
                + fontMetrics().horizontalAdvance(mText) //Ширина текста mText fontMetrics().width(mText)
                + cLedSpacing, //Отступ
                cLedRadius * 2);
}

void LedIndicator::paintEvent(QPaintEvent *pEvent)
{
    //Создаём объект QPainter и указываем QPaintDevice текущий виджет
    QPainter lPainter(this);

    //Используем сглаживание при рисовании для лучшего вида
    lPainter.setRenderHint(QPainter::Antialiasing);

    //Центр окружности индикатора QPoint — класс для описания точки
    QPoint lLedCenter(cLedRadius + 1, height() / 2);

    //Фигура, которую мы будем рисовать QPainterPath — класс для описания фигуры
    //состоящей из нескольких примитивов
    QPainterPath lPath;

    //Добавляем окружность
    lPath.addEllipse(lLedCenter, cLedRadius, cLedRadius);

    //Сохраняем настройки после всех изменений мы восстановим их для рисования подписи
    lPainter.save();

    //Создаём радиальный (окружностями) градиент указываем центр для градиента и радиус
    QRadialGradient lGradient(lLedCenter, cLedRadius);
    if (mIsTurnedOn) //Устанавливаем цвет границы и градиент
    { //для включённого и выключенного состояний
        //Задаём объект QPen — настройки рисования контуров
        //Используем константу для задания цвета контура в конструкторе QPen
        lPainter.setPen(QPen(Qt::darkGreen));
        //Задаём цвет в разных точках (0 — центр, 1 — край) цвет будет равномерно изменяться
        //Для задания цвета пользуемся текстовым шестнадцатеричным RGB обозначением
        //— неявное преобразование в QColor
        // lGradient.setColorAt(0.2, "#70FF70");
        //lGradient.setColorAt(1, "#00CC00");

        lGradient.setColorAt(0.2, QColor(112, 255, 112));
        lGradient.setColorAt(1, QColor(0, 204, 0));

    }
    else
    {
        //Здесь задаём чёрный цвет. Конструктор QColor, значение красной,
        //зелёной и синей (0-255) компонент цвета
        lPainter.setPen(QPen(QColor(0, 0, 0)));
        lGradient.setColorAt(0.2, Qt::gray);
        lGradient.setColorAt(1, Qt::darkGray);
    }
    //Заполняем фигуру индикатора градиентом
    lPainter.fillPath(lPath, QBrush(lGradient));

    //Рисуем границу индикатора
    lPainter.drawPath(lPath);

    //Восстанавливаем настройки перед последним сохранением
    lPainter.restore();

    //Устанавливаем шрифт для рисования текста используем QWidget::font(),
    //чтобы иметь возможность стилизовать надпись
    lPainter.setFont(font());

    //Квадрат, в котором будет рисоваться текст. QRect — класс для обозначения прямоуольной области
    QRect lTextRect(cLedRadius*2 + cLedSpacing, 0, width() - (cLedRadius*2 + cLedSpacing), height());

    //Рисуем текст в заданном прямоугольнике, выравнивание по левому краю и вертикально по центру
    lPainter.drawText(lTextRect, Qt::AlignVCenter | Qt::AlignLeft, mText);
}

void LedIndicator::setText(const QString &pText)
{
    mText = pText;
}

void LedIndicator::setTurnedOn(bool pIsTurnedOn)
{
    //Проверка уже установленного значения
    if (isTurnedOn() == pIsTurnedOn)
    {
        return;
    }
    mIsTurnedOn = pIsTurnedOn;
    //Выпускаем сигнал про изменение
    emit stateToggled(mIsTurnedOn);
    //Вызываем метод QWidget::update(), который добавляет в очередь событий QPaintEvent
    //для того чтобы перерисовать наш виджет в соответствии с установленным isTurnedOn()
    update();
}





