#ifndef QUESTIONVIEW_H
#define QUESTIONVIEW_H

#include <QWidget>

namespace Ui {
class QuestionView;
}

class QuestionView : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionView(QWidget *parent = 0);
    ~QuestionView();

private:
    Ui::QuestionView *ui;
};

#endif // QUESTIONVIEW_H
