#ifndef EMPLOYEE_1_H
#define EMPLOYEE_1_H


#include <QString>
#include<string>
#include <vector>
using namespace std;
class Restaurant;

class Employee_1
{
protected:
    QString name;
    QString CNIC;
    int phone_no;
    QString type;


public:

    virtual float getSalary() = 0;
    virtual QString getType() = 0;
};


class Manager_1 :public Employee_1
{
private:
    double Pay;

public:

    float getSalary();
   QString getType();
    bool AddEmployee(QString empCNIC);
    void Add(QString n, QString c, int p,float s,QString t, QString pw, float h, float w);
    void AddFood(QString n, double p, QString d, QString u, QString t);
    void RemoveFood(QString);
    void RemoveEmployee(QString);
    void RemoveDeal(QString);
    void getrest(Restaurant * hh);
    void adddeal(QString , double , QString );

    void adddealfood(QString ,  QString, int );
    //void AddItem(string itemName);
    //void RemoveItem();
    //void RemoveDeal();
    //void AddDeal(string dealName);


};

class Employee : Employee_1
{
    protected:
    float salary;
    QString password;
    float rate;
    float worked;
    //Restaurant *r;

    public:
    Employee();
    float getSalary() {return salary;}
    QString getType() {return type;}
    QString getName(){return name;}
    QString getCnic(){return CNIC;}
    QString getpassword() {return password;}
    float getrate() {return rate ; }
    float getworked() {return worked;}
    int getphone() {return phone_no;}

    void setAttributes(QString,QString,QString,int ,float ,QString,float, float);
};

/*
class Receptionist :public Employee{
public:
    virtual double getSalary() = 0;
    virtual EmployeeType getType() = 0;
    void receiveCall(string purpose);
    void allocateTable();
    void allocateWaiter(int table_no);
    void addCustomer(Customer obj);
    void sendDelivery(string address);

};
class FullTimeReceptionisit :public Receptionist
{
private:
    double fixedPay;
public:
    double getSalary();
    EmployeeType getType();


};
class PartTimeReceptionisit :public Receptionist
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    EmployeeType getType();


};
class Security :public Employee
{
public:
    double getSalary() = 0;
    EmployeeType getType() = 0;


};
class FullTimeSecurity :public Security
{
private:
    double fixedPay;
public:
    double getSalary();
    EmployeeType getType();


};
class PartTimeSecurity :public Security
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    EmployeeType getType();


};
class Waiter :public Employee
{
private:
    int warningCount;
    vector<Order*> order;
public:
    double getSalary() = 0;
    EmployeeType getType() = 0;
    void provideFood(int table_no);
    bool receiveBill(int amount);

};
class FullTimeWaiter :public Waiter
{
private:
    double fixedPay;
public:
    double getSalary();
    EmployeeType getType();


};
class PartTimeWaiter :public Waiter
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    EmployeeType getType();
};
*/
#endif // EMPLOYEE_1_H
