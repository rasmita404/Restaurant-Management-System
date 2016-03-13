#include "employee_1.h"
#include "businesslayer.h"
#include "restaurant.h"
#include <vector>
using namespace std;
bool Manager_1::AddEmployee(QString cnic){
BusinessLayer bl;
if(bl.addEmployee(cnic)){
    return true;
}
return false;

}
void Manager_1::Add (QString n, QString c, int p,float s,QString t, QString ps, float h, float w)
{\
    BusinessLayer b;

    b.adde(n, c,p, s,t,ps,h, w);
}
void Manager_1::AddFood(QString n, double p, QString d, QString u, QString t){
    BusinessLayer b;
    b.addf(n,p, d,u,t);
}
void Manager_1::RemoveEmployee(QString cnic) {
    BusinessLayer b;
    b.rememp(cnic);
}
void Manager_1::RemoveFood(QString name) {
    BusinessLayer b;
    b.remfood(name);
}

float Manager_1::getSalary(){
    return 12.2;

}
QString Manager_1::getType(){
    return "FullTimeReceptionist";
}
Employee::Employee()
{

}
void Employee::setAttributes(QString n,QString c,QString t,int p,float s,QString pass,float r, float w)
{   name=n;
    CNIC=c;
    phone_no=p;
    type=t;
    salary=s;
    password=pass;
    rate=r;
    worked=w;

}
void Manager_1::RemoveDeal(QString n) {
    BusinessLayer b;
    b.remdeal(n);
}

void Manager_1::adddeal(QString n, double p, QString d) {
    BusinessLayer b;
    b.adddeal(n, p,d);
}

void Manager_1::adddealfood(QString n,  QString fn, int q ) {
    BusinessLayer b;
    b.addDfood(n, fn, q);
}
