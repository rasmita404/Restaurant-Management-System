#ifndef DEAL_H
#define DEAL_H

#include <QWidget>
#include "employee_1.h"
#include "menu.h"

namespace Ui {
class Deal;
}

class Deal : public QWidget
{
    Q_OBJECT

public:
    explicit Deal(QWidget *parent = 0);
    ~Deal();
    void forremove();
    void foradd(Menu);
    void foredit();
    void retrvdeallist();


private slots:
    void on_save_clicked();

 //   void on_dlist_activated(const QModelIndex &index);

    void on_select_clicked();

    void on_remove_clicked();

    void on_add_clicked();

    void on_itemlist_clicked(const QModelIndex &index);

    void on_dlist_clicked(const QModelIndex &index);

private:
    bool act;
    int rs;
    Ui::Deal *ui;
    Manager_1 m;
};

#endif // DEAL_H
