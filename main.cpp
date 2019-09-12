#include "mainwindow.h"
#include "questionview.h"
#include "startview.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c;

    QuestionView *q = new QuestionView();
    StartView *startView = new StartView();
    startView->show();


    return a.exec();
}
