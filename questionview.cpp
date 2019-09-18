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

void QuestionView::setController(Controller *c) {
    m_c = c;
    //connect(ui->AnswerA, SIGNAL(clicked()), m_c, SLOT(onAnswerAClicked()));
}
