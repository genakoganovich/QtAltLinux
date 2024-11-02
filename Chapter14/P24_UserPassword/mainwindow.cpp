#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // Создаем поля для ввода
    usernameLineEdit = new IconizedLineEdit(this);
    passwordLineEdit = new IconizedLineEdit(this);

    // Устанавливаем иконки для полей ввода
    usernameLineEdit->setIconPixmap(QPixmap(":/icons/user.png")); // Замените путь на иконку пользователя
    usernameLineEdit->setIconTooltip("Введите имя пользователя");
    usernameLineEdit->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);

    passwordLineEdit->setIconPixmap(QPixmap(":/icons/lock.png")); // Замените путь на иконку замка
    passwordLineEdit->setIconTooltip("Введите пароль");
    passwordLineEdit->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);

    // Устанавливаем режим ввода пароля (скрытие текста)
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    // Создаем кнопку входа
    loginButton = new QPushButton("Войти", this);

    // Создаем layout для размещения виджетов
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Имя пользователя:"));
    layout->addWidget(usernameLineEdit);
    layout->addWidget(new QLabel("Пароль:"));
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);

    // Устанавливаем layout для окна
    setLayout(layout);
    setWindowTitle("Вход в систему");

    // Подключаем сигнал кнопки к лямбда-функции для обработки нажатия
    connect(loginButton, &QPushButton::clicked, this, [this]() {
        QString username = usernameLineEdit->text();
        QString password = passwordLineEdit->text();
        // Здесь можно добавить логику обработки введенных данных
    });
}

MainWindow::~MainWindow() {}
