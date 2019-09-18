#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QWidget>
#include "controller.h"

namespace Ui {
class StartView;
}

class StartView : public QWidget
{
    Q_OBJECT

public:
    explicit StartView(QWidget *parent = 0);
    ~StartView();
    void setController(Controller *c);

private:
    Ui::StartView *ui;
    Controller *m_c;
};

#endif // STARTVIEW_H
