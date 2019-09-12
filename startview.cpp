#include "startview.h"
#include "ui_startview.h"

StartView::StartView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartView)
{
    ui->setupUi(this);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(onStartButtonClicked()));
}

StartView::~StartView()
{
    delete ui;
}



