#ifndef WINDIALOG_H
#define WINDIALOG_H

#include <QDialog>

namespace Ui {
class WinDialog;
}

class WinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinDialog(QWidget *parent = 0);
    ~WinDialog();
    void setWhoWin(bool);

private:
    Ui::WinDialog *ui;
private slots:
    void ok();
signals:
    void closed();
};

#endif // WINDIALOG_H
