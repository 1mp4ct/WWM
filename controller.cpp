#include "controller.h"

Controller::Controller(QApplication *app) {
    this->app = app;
    startView = new StartView();
    startView->setController(&this);
    questView = new QuestionView();
    questView->setController(&this);
}

void Controller::onStartButtonClicked() {
    questView->show();
}

void Controller::onExitButtonClicked() {
    app->quit();
}

void Controller::startGame() {
    startView->show();
}
