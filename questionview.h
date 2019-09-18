#ifndef QUESTIONVIEW_H
#define QUESTIONVIEW_H

#include <QWidget>
#include "controller.h"

namespace Ui {
class QuestionView;
}

class QuestionView : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionView(QWidget *parent = 0);
    ~QuestionView();
    void setController(Controller *c);

private:
    Ui::QuestionView *ui;
    Controller *m_c;
};

#endif // QUESTIONVIEW_H
