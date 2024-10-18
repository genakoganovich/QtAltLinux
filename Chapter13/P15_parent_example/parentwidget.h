#ifndef PARENTWIDGET_H
#define PARENTWIDGET_H

#include <QWidget>

class ParentWidget : public QWidget
{
public:
    explicit ParentWidget(QWidget *parent = nullptr);

signals:
};

#endif // PARENTWIDGET_H
