
#include "restaurant.h"
#include "businesslayer.h"
#include "employee_1.h"

Restaurant::Restaurant()
{
    BusinessLayer bl;
    //bl.retrieveCustomers(&customerlist);
    bl.retrieveEmployee(&employeelist);
    bl.retrieveWarning(&warn);
}

Restaurant::~Restaurant()
{
}

vector<Employee*> Restaurant::getEmployeeList(){
    return employeelist;
}
