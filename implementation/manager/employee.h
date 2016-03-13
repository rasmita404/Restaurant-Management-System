#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QWidget>
#include "employee_1.h"
#include "restaurant.h"
namespace Ui {
class employee;
}

class employee : public QWidget
{
    Q_OBJECT

public:
    explicit employee(QWidget *parent = 0);
   void pattern1();
   void forsal(Restaurant);
   void foredit(Restaurant);
    ~employee();

private slots:
    void on_type_activated(const QString &arg1);


    void on_save_clicked();

    void on_remove_clicked();

    void on_selectitem_clicked();

    void on_getsal_clicked();

    void on_emplist_activated(const QModelIndex &index);

    void on_emplist_clicked(const QModelIndex &index);

private:
    bool act;
    int rs;
    Ui::employee *ui;
    Manager_1 m;
};

#endif // EMPLOYEE_H
