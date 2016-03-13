#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<vector>
#include<string>
//#include "employee_1.h"
#include <vector>
#include "warning.h"
using namespace std;
class Employee;
class Restaurant
{
public:
    friend class employee;

   // vector<Customer*> getCustomerList();
    vector<Employee*> getEmployeeList();
     vector<Employee *> employeelist;
vector<Warning *> warn;
    Restaurant();
    ~Restaurant();

private:
    //Ui::Restaurant *ui;
    string name;
    string address;
    string phone;


    //vector <SittingArrangement*> hallist;
    //vector<Customer*> customerlist;

};

#endif // RESTAURANT_H
