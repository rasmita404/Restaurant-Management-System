#ifndef DATALAYER_H
#define DATALAYER_H

#include <QString>
#include <QtSql>
#include <vector>
#include "employee.h"
using namespace std;
class DataLayer
{
private:
    QSqlDatabase mydb;
    bool connectDB();
    void closeDB();

public:
    //DataLayer();
    bool saveMenu();
    bool checkCustomer(QString);
    int searchHall(QString,QString);
    void addCustomer(QString,QString,QString,QString);
    bool allocateHall(QString,QString,QString);
    bool allocateTable(QString,QString,int,QString);
    bool DineIn(int,QString,QString,QString,QString);
    void getMenu(vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*,vector<FoodItem*>*, vector<Deal>*);
    bool retrieveCustomers(vector<Customer*>*);
    bool retrieveEmployees(vector<Employee*>*);
    bool retrieveHalls(vector<SittingArrangement*>*);
    void saveOrder(QString,vector<QString>,vector<double>,vector<QString>,vector<double>);
};

#endif // DATALAYER_H
