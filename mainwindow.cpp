#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *btns[9] = {ui->btn1, ui->btn2, ui->btn3, ui->btn4, ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn9};
        for(short i = 0; i < 9; ++i)
        {
            v[i]=false;
            buttons[i] = btns[i];
            buttons[i]->setEnabled(false);
            connect(buttons[i], SIGNAL(clicked()), SLOT(gBtnClicked()));
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame()
{
    this->show();
}

void MainWindow::youGo(bool ws)
{
    //qDebug()<<"i go "<<ws;
    whoStep=ws;
    for(short i = 0; i < 9; i++)
    {
        if(!v[i])
        {
            buttons[i]->setEnabled(true);
            //qDebug()<<"i go "<<i;
        }
    }
    if(whoStep)
    {
        ui->whoStepLabel->setText("You step(X)");
    }
    else
    {
        ui->whoStepLabel->setText("You step(O)");
    }
}

void MainWindow::youWin()
{
    qDebug()<<"win";
    WinDialog *wd = new WinDialog();
    connect(wd, SIGNAL(closed()), this , SLOT (reset()));
    wd->show();
}

void MainWindow::youWin(bool ww)
{
    qDebug()<<"win";
    WinDialog *wd = new WinDialog();
    connect(wd, SIGNAL(closed()), this , SLOT (reset()));
    wd->setWhoWin(ww);
    wd->show();
}

void MainWindow::youLose()
{
    LoseDialog *ld = new LoseDialog();
    connect(ld, SIGNAL(closed()), this , SLOT (reset()));
    ld->show();
}

void MainWindow::enemyGo(short i , bool ws)
{
    v[i]=true;
    QString pressedStyle = "#btn";
            pressedStyle +=QString::number(i+1);
            pressedStyle +="{background-image: url(:/";
    if(ws)
    {
        pressedStyle += "X.png);background-color:transparent;}";
    }
    else
    {
        pressedStyle += "O.png);background-color:transparent;}";
    }
    buttons[i]->setStyleSheet(pressedStyle);
}

void MainWindow::gBtnClicked()
{
    QPushButton *btn = ((QPushButton*)sender());
    short k = 0;
    for(short i = 0; i < 9; i++)
    {
        ui->whoStepLabel->setText("Waiting");
        if(buttons[i] == btn)
        {
            QString pressedStyle = "#btn";
                    pressedStyle +=QString::number(i+1);
                    pressedStyle +="{background-image: url(:/";
            if(whoStep)
            {
                pressedStyle += "X.png);background-color:transparent;}";
                whoStep = false;
            }
            else
            {
                pressedStyle += "O.png);background-color:transparent;}";
                whoStep = true;
            }
            buttons[i]->setStyleSheet(pressedStyle);
            v[i]=true;
            k=i;
        }
        buttons[i]->setEnabled(false);
    }
    emit step(k);
}

void MainWindow::setScore(short x , short o)
{
    ui->oSLabel->setText(QString::number(o));
    ui->xSLabel->setText(QString::number(x));
}

void MainWindow::reset()
{
    for (short i=0;i<9;i++)
    {
        v[i]=0;
        QString pressedStyle = "#btn";
                pressedStyle +=QString::number(i+1);
                pressedStyle +="{background-image: url(:/btnClear.png); background-color:transparent;}";
                pressedStyle += "#btn";
                pressedStyle +=QString::number(i+1);
                pressedStyle +=":hover {background-image: url(:/btnHover.png); background-color:transparent;}";
                buttons[i]->setStyleSheet(pressedStyle);
    }
    youGo(true);
}

void MainWindow::on_closeBtn_clicked()
{
    emit goTiMenu();
    this->close();
}
