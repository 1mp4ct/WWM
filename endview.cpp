#include "endview.h"
#include "ui_endview.h"

endview::endview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::endview)
{
    ui->setupUi(this);
}

endview::~endview()
{
    delete ui;
}
