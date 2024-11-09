#include "mainwindow.h"

#include <QWidget>
#include <QPlainTextEdit>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // Создаем виджет QPlainTextEdit
    textEdit = new QPlainTextEdit(this);
    textEdit->setPlainText("Это пример текста.\nПереместите курсор, чтобы увидеть координаты.");

    // Создаем QLabel для отображения позиции курсора
    cursorPositionLabel = new QLabel("Позиция курсора: (0, 0)", this);

    // Соединяем сигнал cursorPositionChanged с пользовательским слотом
    connect(textEdit, &QPlainTextEdit::cursorPositionChanged, this, &MainWindow::onCursorPositionChanged);

    // Устанавливаем компоновку
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    layout->addWidget(cursorPositionLabel);
    setLayout(layout);
}

MainWindow::~MainWindow() {}

void MainWindow::onCursorPositionChanged()
{
    // Получаем текущую позицию курсора
    QTextCursor cursor = textEdit->textCursor();
    int line = cursor.blockNumber() + 1;       // Номер строки (начиная с 1)
    int column = cursor.columnNumber() + 1;    // Номер столбца (начиная с 1)

    // Обновляем текст метки
    cursorPositionLabel->setText(QString("Позиция курсора: (%1, %2)").arg(line).arg(column));
}
