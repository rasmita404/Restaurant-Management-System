#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "customer.h"
//#include "deal.h"
#include <time.h>
#include "sitting_arrangement.h"
#include<string>
#include <QString>
#include <vector>
#include <iostream>
#include "deal.h"
//#include "restaurant.h"
using namespace std;
//enum string { Manager,AssistantManager,FullTimeReceptionist,PartTimeReceptionist,FullTimeWaiter,PartTimeWaiter,FullTimeSecurity,PartTimeSecurity };

class Restaurant;

class Employee
{
    protected:
    string name;
    string CNIC;
    string phone_no;
    string type;
    Restaurant *r;

    public:
    Employee();
    virtual double getSalary()=0;
    virtual string getType()=0;
    string getName(){return name;}
    string getCnic(){return CNIC;}
    virtual void setAttributes(QString,QString,QString,QString,int);
};

class Receptionist:public Employee{
    string currentDateTime();
public:
    Receptionist();
    virtual double getSalary()=0;
    virtual string getType()=0;
    void receiveCall(string purpose);
    void allocateWaiter(int table_no);
    bool customerPresent(QString CNIC);
    void addCustomer(Customer obj);
    void sendDelivery(string address);
    bool allocateTable(Reservation r,int noc,QString);
    bool allocateHall(QString cnic,Reservation r);
    bool DineIn(int,QString,QString);
    vector<Employee*> getWaiter();
};
class FullTimeReceptionisit:public Receptionist
{
private:
    double fixedPay;
public:
    double getSalary();
    string getType();
};
class PartTimeReceptionisit:public Receptionist
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    string getType();
};
class Waiter:public Employee
{
private:
int warningCount;
//vector<Order*> order;
public:
    virtual double getSalary()=0;
    virtual string getType()=0;
    //void provideFood(int table_no);
    //bool receiveBill(int amount);
    void setAttributes(QString,QString,QString,QString,int);
};
class FullTimeWaiter:public Waiter
{
private:
    double fixedPay;
public:
    double getSalary();
    string getType();


};
class PartTimeWaiter:public Waiter
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    string getType();
};
/*
class FullTimeOnly:public Employee
{
private:
    double fixedPay;
public:
    virtual double getSalary();
    virtual string getType();

};
class ManagingStaff:public FullTimeOnly
{
private:
    double managingPay;
public:
    double getSalary();
    string getType();
};
class Chef:public FullTimeOnly
{
private:
    int warningCount;
public:
    double getSalary();
   string getType();
    void cookFood();

};
class Manager:public ManagingStaff
{
private:
double extraPay;
vector<FoodItem*> food_item;
vector<Deal*> deal;
public:

    double getSalary();
    string getType();
    void manageEmployee(string empCNIC);
    void manageItem(string itemName);
    void manageDeal(string dealName);


};
class AssistantManager:public ManagingStaff
{
private:
    SittingArrangement* sitting_arrangement;
    vector<Ceremony*> ceremony;
public:
    double getSalary();
    string getType();
    float checkRating();
    void requestManager(string employee);

};

class Security:public Employee
{
public:
    double getSalary()=0;
    string getType()=0;


};
class FullTimeSecurity:public Security
{
private:
    double fixedPay;
public:
    double getSalary();
    string getType();


};
class PartTimeSecurity:public Security
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    string getType();


};
*/

/*
*/

#endif // EMPLOYEE_H
