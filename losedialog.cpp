#include "losedialog.h"
#include "ui_losedialog.h"

LoseDialog::LoseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoseDialog)
{
    ui->setupUi(this);
    connect(ui->okBtn,SIGNAL(clicked()),this,SLOT(ok()));
}


void LoseDialog::ok()
{
    emit closed();
    this->accept();
}


LoseDialog::~LoseDialog()
{
    delete ui;
}
