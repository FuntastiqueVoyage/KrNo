#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <windialog.h>
#include <losedialog.h>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void newGame();
    void youGo(bool);
    void youWin();
    void youLose();
    void enemyGo(short,bool);
    void reset();
    void setScore(short,short);
    void youWin(bool);
signals:
    void goTiMenu();
    void step(short);

private:
    Ui::MainWindow *ui;
    bool v[9];
    QPushButton *buttons[9];
    bool whoStep;


private slots:
    void gBtnClicked();
    void on_closeBtn_clicked();
};

#endif // MAINWINDOW_H
