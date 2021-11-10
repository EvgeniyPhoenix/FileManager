#include "mainwindow.h"
#include "signin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    signin s;
    s.setStyleSheet("QMainWindow {background: 'white';}");
    s.show();
    return a.exec();
}
