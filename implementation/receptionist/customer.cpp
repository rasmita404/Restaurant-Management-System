#include "customer.h"

void Customer::setAttributes(QString cnic,QString n,QString ph,QString addr)
{
CNIC=cnic;
name=n;
phone_no=ph;
address=addr;
}
QString Customer::getCNIC(){
return CNIC;
}
QString Customer::getName(){
return name;
}
QString Customer::getAddress(){
return address;
}
QString Customer::getPhoneNo(){
return phone_no;
}


