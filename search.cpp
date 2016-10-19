#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::on_cancelBtn_clicked()
{
    emit stop();
    this->accept();
}
