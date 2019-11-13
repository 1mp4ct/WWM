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

       startViewWidget->setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);



       questViewWidget = new QWidget;
       questViewWidget->setStyleSheet("QWidget{background-image: url(:/assets/wwmfragen.png); color: white; border: none;} QPushButton{background: transparent; font-size: 14px; Text-align:left;} QPushButton:hover{background: transparent; color: yellow;} QTextEdit{background: transparent; font-size: 14px;} QPushButton#PhoneJoker, QPushButton#AudJoker, QPushButton#Joker50 {background: transparent; border: 1px solid blue;} QPushButton#Joker50:disabled, QPushButton#AudJoker:disabled, QPushButton#PhoneJoker:disabled {color: #444444; border-color: #444444}");
       quest_ui.setupUi(questViewWidget);
       updateMoney();
       connect(quest_ui.AnswerA, SIGNAL(clicked()), this, SLOT(onAnsA()));
       connect(quest_ui.AnswerB, SIGNAL(clicked()), this, SLOT(onAnsB()));
       connect(quest_ui.AnswerC, SIGNAL(clicked()), this, SLOT(onAnsC()));
       connect(quest_ui.AnswerD, SIGNAL(clicked()), this, SLOT(onAnsD()));
       //connect(quest_ui.startButton, SIGNAL(clicked()), this, SLOT(goToQuestion()));

       questViewWidget->setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

       connect(quest_ui.Joker50, SIGNAL(clicked()), this, SLOT(onJoker50()));
       connect(quest_ui.AudJoker, SIGNAL(clicked()), this, SLOT(onAudJoker()));
       connect(quest_ui.PhoneJoker, SIGNAL(clicked()), this, SLOT(onPhoneJoker()));

       endViewWidget = new QWidget;
       endViewWidget->setStyleSheet("QWidget{background-image: url(:/assets/logo2.png); color: white;} QLabel{background: transparent; font-size: 16px; font-weight: bold; border: none;}");

       end_ui.setupUi(endViewWidget);

       connect(end_ui.exitButton, SIGNAL(clicked()), this, SLOT(exit()));
       connect(end_ui.startButton, SIGNAL(clicked()), this, SLOT(goToStart()));
       connect(end_ui.newGameButton, SIGNAL(clicked()), this, SLOT(goToQuestion()));

       endViewWidget->setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}

void Controller::startGame(QList<frage> *questions) {
    quests = questions;

    startViewWidget->show();
}

void Controller::exit() {
    app->exit();
}

/*
void Controller::disableAnswer(String s) {
    switch (s) {
        case "a":

    }
}*/

void Controller::goToQuestion() {
    money = 0;
    currentQuest = 0;
    setCurrentQuest(quests->at(currentQuest));
    updateMoney();

    quest_ui.AudJoker->setEnabled(true);
    quest_ui.PhoneJoker->setEnabled(true);
    quest_ui.Joker50->setEnabled(true);

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

       removeJoker();

     quest_ui.Question->setText(quest.qw);
     quest_ui.AnswerA->setText(quest.an1);
     quest_ui.AnswerB->setText(quest.an2);
     quest_ui.AnswerC->setText(quest.an3);
     quest_ui.AnswerD->setText(quest.an4);

}

void Controller::setJoker(Joker* joker) {
    quest_ui.jokerFieldA->setText(QString(std::to_string(joker->a*100.0).c_str()));
    quest_ui.jokerFieldB->setText(QString(std::to_string(joker->b*100.0).c_str()));
    quest_ui.jokerFieldC->setText(QString(std::to_string(joker->c*100.0).c_str()));
    quest_ui.jokerFieldD->setText(QString(std::to_string(joker->d*100.0).c_str()));
}

void Controller::removeJoker() {
    quest_ui.jokerFieldA->setText("");
    quest_ui.jokerFieldB->setText("");
    quest_ui.jokerFieldC->setText("");
    quest_ui.jokerFieldD->setText("");
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
        addMoney();
        updateMoney();

        if (currentQuest < 14)  {
            setCurrentQuest(quests->at(++currentQuest));
        } else {
            goToEnd();
        }

    } else {
        if (currentQuest < 9) {
            money = 0;
        } else if (currentQuest < 16){
            money = 16000;
        }
        goToEnd();
    }
}

void Controller::addMoney() {
    switch(currentQuest + 2) {
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

void Controller::onJoker50() {
    quest_ui.Joker50->setEnabled(false);
    FiftyFiftyJoker* j = new FiftyFiftyJoker();
    j->evalQuest(quests->at(currentQuest));
    setJoker(j);
}

void Controller::onAudJoker() {
    quest_ui.AudJoker->setEnabled(false);
    AudJoker* j = new AudJoker();
    j->evalQuest(quests->at(currentQuest));
    setJoker(j);
}

void Controller::onPhoneJoker() {
    quest_ui.PhoneJoker->setEnabled(false);
    PhoneJoker* j = new PhoneJoker();
    j->evalQuest(quests->at(currentQuest));
    setJoker(j);
}

