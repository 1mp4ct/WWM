#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include "ui_startview.h"
#include "ui_questionview.h"
#include "ui_endview.h"
#include "frage.h"
#include <string>
#include <QTimer>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr, QApplication *appl = nullptr);
    //Controller(QApplication *appl);
    void startGame(QList<frage> *questions);
    void setCurrentQuest(frage quest);
    QString waitForAnswer();

private slots:
    void exit();
    void goToQuestion();
    void goToStart();
    void goToEnd();
    void onAnsA();
    void onAnsB();
    void onAnsC();
    void onAnsD();
private:
    void evalQuest(QString answer);
    void addMoney();
    void updateMoney();

    QWidget *startViewWidget;
    QWidget *questViewWidget;
    QWidget *endViewWidget;

    Ui::StartView start_ui;
    Ui::QuestionView quest_ui;
    Ui::endview end_ui;

    QApplication *app;
    QString currAnswer;
    QTimer timer;
    QList<frage> *quests;

    int currentQuest;
    int money;
};

#endif // CONTROLLER_H
