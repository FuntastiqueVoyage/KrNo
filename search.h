#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::Search *ui;

signals:
    void stop();

};

#endif // SEARCH_H
