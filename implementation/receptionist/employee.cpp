#include "employee.h"
#include "businesslayer.h"
#include "restaurant.h"
bool Receptionist::customerPresent(QString CNIC)
{
    for(int i=0;i<r->getCustomerList().size();i++)
    {
        if(r->getCustomerList()[i]->getCNIC()==CNIC)
        {
            return true;
        }
    }
    return false;
}

Employee::Employee()
{

}

Receptionist::Receptionist()
{
    r=new Restaurant();
}

vector<Employee*> Receptionist::getWaiter()
{
    return r->getEmployeeList();
}

void Receptionist::addCustomer(Customer obj)
{
    BusinessLayer bl;
    bl.addCustomer(obj.getCNIC(),obj.getName(),obj.getPhoneNo(),obj.getAddress());
    r->addCustomer(&obj);
}

double FullTimeReceptionisit::getSalary()
{
    return 12.3;
}

double PartTimeReceptionisit::getSalary()
{
    return 12.3;
}

string PartTimeReceptionisit::getType()
{
    return "PartTime Receptionist";
}

string FullTimeReceptionisit::getType()
{
    return "FullTime Receptionist";
}

double FullTimeWaiter::getSalary()
{
    return 12.3;
}

double PartTimeWaiter::getSalary()
{
    return 12.3;
}
string PartTimeWaiter::getType()
{
    return "PartTime Waiter";
}

string FullTimeWaiter::getType()
{
    return "FullTime Waiter";
}

bool Receptionist::allocateTable(Reservation r,int noc,QString cnic)
{
    BusinessLayer bl;
    if(bl.allocateTable(r,noc,cnic))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Receptionist::allocateHall(QString cnic,Reservation r)
{
    BusinessLayer bl;
    //int hall_id=bl.searchHall(r);
    if(bl.allocateHall(cnic,r))
    {
        return true;
    }
    return false;
}

bool Receptionist::DineIn(int num,QString cnic,QString w_cnic)
{
    BusinessLayer bl;
    string datetime=currentDateTime();
    string date="----------";
    string time="--------";
    bool flag=false;
    int j=0;
    for(int i=0;i<datetime.length();i++)
    {
        if(datetime[i]=='.')
        {
            i++;
            flag=true;
        }
        if(flag==false)
        {
            date[i]=datetime[i];
        }
        else if(flag==true)
        {
            time[j]=datetime[i];
            j++;
        }
    }
    if(bl.DineIn(num,cnic,w_cnic,QString::fromStdString(date),QString::fromStdString(time)))
    {
        return true;
    }
    return false;
}

void Employee::setAttributes(QString n,QString cnic,QString p,QString t,int x=0)
{
    name=n.toStdString();
    CNIC=cnic.toStdString();
    phone_no=p.toStdString();
    //type=t.toStdString();
}

void Waiter::setAttributes(QString n,QString cnic,QString p,QString t,int w)
{
    Employee::setAttributes(n,cnic,p,t);
    warningCount=w;
}

string Receptionist::currentDateTime()
{
       time_t     now = time(0);
       struct tm  tstruct;
       char       buf[80];
       tstruct = *localtime(&now);
       strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &tstruct);

       return buf;
}
