#include "newgame.h"
#include "ui_newgame.h"

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::on_singleBtn_clicked()
{
    emit pressed(true);
    this->accept();
}

void NewGame::on_onlineBtn_clicked()
{
    emit pressed(false);
    this->accept();
}
