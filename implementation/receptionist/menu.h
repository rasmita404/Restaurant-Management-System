#ifndef MENU_H
#define MENU_H

#include <QWidget>
//#include "mainwindow.h"

#include "deal.h"
#include <iostream>
#include<QCheckBox>
using namespace std;
class Quantity;
namespace Ui {
class Menu;
}
class Menu : public QWidget
{
    Q_OBJECT

public:
    bool closed;
    explicit Menu(QWidget *parent = 0);
    ~Menu();
    void displayMenu(vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*, vector<Deal>*);
    void setBill(int,QCheckBox*);
    void saveOrder(QString,vector<QString>,vector<double>,vector<QString>,vector<double>);
public slots:
    void onCustomerCnicSend(const QString &text);

    void cb_clicked(int);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::Menu *ui;
    QString customer_cnic;
    vector<FoodItem*> appetizer;
    vector<FoodItem*> dessert;
    vector<FoodItem*> italian;
    vector<FoodItem*> chinese;
    vector<FoodItem*> other;
    vector<Deal> deal;
    int count;//for number of checkboxes checked
    Quantity *quantity;

    //MainWindow main;
};

#endif // MENU_H
