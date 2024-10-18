#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    QLabel label;
    label.setText("I am Widget!");
    label.setGeometry(200, 200, 300, 150);

    label.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QFont blackFont("Arial Black", 12);
    label.setFont(blackFont);

    label.show();

    return application.exec();
}
