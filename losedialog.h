#ifndef LOSEDIALOG_H
#define LOSEDIALOG_H

#include <QDialog>

namespace Ui {
class LoseDialog;
}

class LoseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoseDialog(QWidget *parent = 0);
    ~LoseDialog();

private:
    Ui::LoseDialog *ui;
private slots:
    void ok();
signals:
    void closed();
};

#endif // LOSEDIALOG_H
