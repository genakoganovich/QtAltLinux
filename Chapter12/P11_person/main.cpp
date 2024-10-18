#include "person.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    Person person("John Doe", "+123456789", "123 Main St, Anytown");
    qDebug() << person;  // Вывод информации о person

    return 0;
}
