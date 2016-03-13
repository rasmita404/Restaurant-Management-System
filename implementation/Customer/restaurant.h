#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QMainWindow>
#include <QModelIndex>
#include "menu.h"
#include "customer.h"
#include "RateDialog.h"
namespace Ui {
class Restaurant;
}

class Restaurant : public QMainWindow
{
    Q_OBJECT
public:
    explicit Restaurant(QWidget *parent = 0,Dialog *d=0);
    ~Restaurant();

public slots:
    void onPlaceOrderClicked();
    void onPayBillClicked();
    void onRateClicked();
    void onGetMembershipClicked();
    void activatePlaceOrder();
    void handleCheckBox(QModelIndex);
    void onAddMembershipChecked();
	void handleCheckBoxForDeal(QModelIndex);
	void GetDialogOutput(vector<int>&);

private slots:
    void on_rate_clicked();

private:
    Ui::Restaurant *ui;
    Dialog* myRateDialog;
    int price;
	Menu restaurantMenu;
	Menu customerMenu;
	Customer* newCustomer;
};

#endif // RESTAURANT_H
