#include "questionview.h"
#include "ui_questionview.h"

QuestionView::QuestionView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionView)
{
    ui->setupUi(this);
}

QuestionView::~QuestionView()
{
    delete ui;
}
