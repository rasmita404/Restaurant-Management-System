#include "restaurant.h"
#include "businesslayer.h"
//#include "employee.h"
//#include "ui_restaurant.h"

Restaurant::Restaurant()
{
    BusinessLayer bl;
    bl.retrieveCustomers(&customerlist);
    bl.retrieveEmployee(&employeelist);
    bl.retrieveHalls(&halllist);
}

void Restaurant::addCustomer(Customer* c)
{
    customerlist.push_back(c);
}

Restaurant::~Restaurant()
{

}
vector<Employee*> Restaurant::getEmployeeList(){
    return employeelist;
}
vector<Customer*> Restaurant::getCustomerList()
{
    return customerlist;
}
