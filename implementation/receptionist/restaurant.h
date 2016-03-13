#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<vector>
#include<string>
#include "employee.h"
#include <vector>
using namespace std;

class Restaurant
{
public:
    vector<Customer*> getCustomerList();
    vector<Employee*> getEmployeeList();
    vector<SittingArrangement*> getHallList();
    void addCustomer(Customer*);
    Restaurant();
    ~Restaurant();

private:
    //Ui::Restaurant *ui;
    string name;
    string address;
    string phone;
    vector<Employee*> employeelist;
    vector <SittingArrangement*> halllist;
    vector<Customer*> customerlist;
};

#endif // RESTAURANT_H
