#ifndef FOODITEM_H
#define FOODITEM_H

#include <QWidget>
#include "employee_1.h"
#include "menu.h"

namespace Ui {
class fooditem;
}

class fooditem : public QWidget
{
    Q_OBJECT

public:
    explicit fooditem(QWidget *parent = 0);
    ~fooditem();
   void add();
   void forremove(Menu );
   void edit(Menu);

private slots:
   void on_save_clicked();

   void on_remove_clicked();

   void on_flist_activated(const QModelIndex &index);

   void on_selecti_clicked();

   void on_flist_clicked(const QModelIndex &index);

private:
   bool act;
   int rs;
    Ui::fooditem *ui;
    Manager_1 m;
};

#endif // FOODITEM_H
