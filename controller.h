#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QApplication>

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(QApplication *app);
    void startGame();
public slots:
    void onStartButtonClicked();

private:
    QApplication *app;
    StartView *startView;
    QuestionView *questView;


};

#endif // CONTROLLER_H
