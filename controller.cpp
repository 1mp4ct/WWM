#include "controller.h"

Controller::Controller(QObject *parent, QApplication *appl) : QObject(parent) {
       app = appl;
       currentQuest = 0;
       money = 0;
       startViewWidget = new QWidget;
       //Ui::StartView start_ui;
       start_ui.setupUi(startViewWidget);
       connect(start_ui.exitButton, SIGNAL(clicked()), this, SLOT(exit()));
       connect(start_ui.startButton, SIGNAL(clicked()), this, SLOT(goToQuestion()));

       questViewWidget = new QWidget;
      // Ui::QuestionView quest_ui;
       quest_ui.setupUi(questViewWidget);
       updateMoney();
       connect(quest_ui.AnswerA, SIGNAL(clicked()), this, SLOT(onAnsA()));
       connect(quest_ui.AnswerB, SIGNAL(clicked()), this, SLOT(onAnsB()));
       connect(quest_ui.AnswerC, SIGNAL(clicked()), this, SLOT(onAnsC()));
       connect(quest_ui.AnswerD, SIGNAL(clicked()), this, SLOT(onAnsD()));
       //connect(quest_ui.startButton, SIGNAL(clicked()), this, SLOT(goToQuestion()));

}

void Controller::startGame(QList<frage> *questions) {
    quests = questions;

    startViewWidget->show();
}

void Controller::exit() {
    app->exit();
}

void Controller::goToQuestion() {
    startViewWidget->hide();
    setCurrentQuest(quests->at(currentQuest));
    questViewWidget->show();
}

void Controller::setCurrentQuest(frage quest) {
       currAnswer = nullptr;
     quest_ui.Question->setText(quest.qw);
     quest_ui.AnswerA->setText(quest.an1);
     quest_ui.AnswerB->setText(quest.an2);
     quest_ui.AnswerC->setText(quest.an3);
     quest_ui.AnswerD->setText(quest.an4);

}

void Controller::onAnsA() {
    evalQuest("a");
}

void Controller::onAnsB() {
    evalQuest("b");
}

void Controller::onAnsC() {
    evalQuest("c");
}

void Controller::onAnsD() {
    evalQuest("d");
}

QString Controller::waitForAnswer() {
    while(currAnswer == nullptr) {
        timer.setSingleShot(true); // if you only want it to fire once
        timer.start(50);
    }

    return currAnswer;
}

void Controller::evalQuest(QString answer) {
    if (answer == quests->at(currentQuest).ar) {
        setCurrentQuest(quests->at(++currentQuest));
        addMoney();
        updateMoney();
    } else {
        app->exit();
    }
}

void Controller::addMoney() {
    switch(currentQuest + 1) {
        case 2: money = 50; break;
        case 3: money = 100; break;
        case 4: money = 200; break;
        case 5: money = 300; break;
        case 6: money = 500; break;
        case 7: money = 1000; break;
        case 8: money = 2000; break;
        case 9: money = 4000; break;
        case 10: money = 8000; break;
        case 11: money = 16000; break;
        case 12: money = 32000; break;
        case 13: money = 64000; break;
        case 14: money = 125000; break;
        case 15: money = 500000; break;
        case 16: money = 1000000; break;
    }
}

void Controller::updateMoney() {
    quest_ui.moneyField->setText("Gewinn: " + QString::number(money));
}

