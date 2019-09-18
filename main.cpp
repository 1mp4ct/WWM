#include "mainwindow.h"
#include "questionview.h"
#include "startview.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c(&a);
    c.startGame();

    return a.exec();
}
