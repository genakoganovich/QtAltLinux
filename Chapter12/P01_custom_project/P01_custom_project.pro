# Указываем тип проекта
TEMPLATE = app # app − Application , прикладная программа
# Используемые модули Qt
QT -= gui # Удаляем из списка модуль gui
# это означает отказ от использования графического интрефейса,
# то есть — консольную программу
CONFIG += console # Конфигурируем создание консольного проекта
# (нужно только для консольных проектов в Windows, в Linux и Mac OS X не выполняет никаких действий)
CONFIG =- app_bundle # Предотвращает создание Application bundle в Mac OS X
# (нужно только для консольных проектов в Mac OS X)
TARGET = P01_custom_project # Название исполняемого файла

SOURCES += \
    main.cpp
