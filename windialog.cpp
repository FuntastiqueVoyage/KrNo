#include "windialog.h"
#include "ui_windialog.h"

WinDialog::WinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
    connect(ui->okBtn,SIGNAL(clicked()),this,SLOT(ok()));
}

void WinDialog::ok()
{
    emit closed();
    this->accept();
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::setWhoWin(bool ww)
{
    if(ww)
    {
        ui->whoWinLabel->setText("X win!");
    }
    else
    {
        ui->whoWinLabel->setText("O win!");
    }
}
