#include "startview.h"
#include "ui_startview.h"

StartView::StartView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartView)

{
    ui->setupUi(this);

}

StartView::~StartView()
{
    delete ui;
}

void StartView::setController(Controller *c) {
    m_c = c;
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onStartButtonClicked()));
}





