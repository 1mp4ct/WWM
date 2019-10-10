#include "controller.h"

Controller::Controller(QObject *parent, QApplication *appl) : QObject(parent) {
       app = appl;
       currentQuest = 0;
       money = 0;
       startViewWidget = new QWidget;
       startViewWidget->setStyleSheet("background-image: url(:/assets/logo2.png); color: white;");
       //Ui::StartView start_ui;
       start_ui.setupUi(startViewWidget);
       connect(start_ui.exitButton, SIGNAL(clicked()), this, SLOT(exit()));
       connect(start_ui.startButton, SIGNAL(clicked()), this, SLOT(goToQuestion()));



       questViewWidget = new QWidget;
       questViewWidget->setStyleSheet("QWidget{background-image: url(:/assets/wwmfragen.png); color: white; border: none;} QTextEdit, QPushButton{background: transparent;}");
       quest_ui.setupUi(questViewWidget);
       updateMoney();
       connect(quest_ui.AnswerA, SIGNAL(clicked()), this, SLOT(onAnsA()));
       connect(quest_ui.AnswerB, SIGNAL(clicked()), this, SLOT(onAnsB()));
       connect(quest_ui.AnswerC, SIGNAL(clicked()), this, SLOT(onAnsC()));
       connect(quest_ui.AnswerD, SIGNAL(clicked()), this, SLOT(onAnsD()));
       //connect(quest_ui.startButton, SIGNAL(clicked()), this, SLOT(goToQuestion()));

       endViewWidget = new QWidget;

       end_ui.setupUi(endViewWidget);

       connect(end_ui.exitButton, SIGNAL(clicked()), this, SLOT(exit()));
       connect(end_ui.startButton, SIGNAL(clicked()), this, SLOT(goToStart()));
       connect(end_ui.newGameButton, SIGNAL(clicked()), this, SLOT(goToQuestion()));
}

void Controller::startGame(QList<frage> *questions) {
    quests = questions;

    startViewWidget->show();
}

void Controller::exit() {
    app->exit();
}

void Controller::goToQuestion() {
    money = 0;
    currentQuest = 0;
    setCurrentQuest(quests->at(currentQuest));
    updateMoney();

    startViewWidget->hide();
    endViewWidget->hide();
    questViewWidget->show();
}

void Controller::goToStart() {
    startViewWidget->show();
    endViewWidget->hide();
    questViewWidget->hide();
}

void Controller::goToEnd() {
    end_ui.endText->setText("Spiel vorbei, Gewinn: " + QString::number(money));

    startViewWidget->hide();
    endViewWidget->show();
    questViewWidget->hide();
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
        if (currentQuest < 11) {
            money = 0;
        }
        goToEnd();
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

