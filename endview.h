#ifndef ENDVIEW_H
#define ENDVIEW_H

#include <QWidget>

namespace Ui {
class endview;
}

class endview : public QWidget
{
    Q_OBJECT

public:
    explicit endview(QWidget *parent = 0);
    ~endview();

private:
    Ui::endview *ui;
};

#endif // ENDVIEW_H
