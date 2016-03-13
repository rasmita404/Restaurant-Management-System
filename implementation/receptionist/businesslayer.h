#ifndef BUSINESSLAYER_H
#define BUSINESSLAYER_H

#include <QString>
#include "reservation.h"
#include "employee.h"
#include <vector>

using namespace std;
class BusinessLayer
{
public:
   // BusinessLayer();
    bool saveMenu();
    bool checkCustomer(QString);
    void addCustomer(QString,QString,QString,QString);
    int searchHall(Reservation);
    bool allocateHall(QString,Reservation);
    bool allocateTable(Reservation r,int,QString);
    bool DineIn(int,QString,QString,QString,QString);
    bool retrieveCustomers(vector<Customer*>*);
    bool retrieveEmployee(vector<Employee*>*);
    bool retrieveHalls(vector<SittingArrangement*>*);
    void getMenu(vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*, vector<Deal>*);
    void saveOrder(QString,vector<QString>,vector<double>,vector<QString>,vector<double>);
};

#endif // BUSINESSLAYER_H
