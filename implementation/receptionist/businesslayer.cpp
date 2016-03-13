#include "businesslayer.h"
#include "datalayer.h"
#include <QString>
void BusinessLayer::getMenu(vector<FoodItem*>*appetizer, vector<FoodItem *>*dessert, vector<FoodItem *>*italian , vector<FoodItem *>*chinese , vector<FoodItem *> *other, vector<Deal>*deal){
DataLayer d;
d.getMenu(appetizer,dessert,italian,chinese,other,deal);

}
void BusinessLayer::saveOrder(QString c_cnic, vector<QString>food_item,vector<double> food_item_price, vector<QString>_deal,vector<double> _deal_price){
DataLayer d;
d.saveOrder(c_cnic,food_item,food_item_price,_deal,_deal_price);
}

bool BusinessLayer::saveMenu(){
//authenticate data
//pass data to data layer;
    DataLayer d;
    if(d.saveMenu())
        return true;
    else
        return false;
}
bool BusinessLayer::checkCustomer(QString cnic){
    DataLayer d;
    if(d.checkCustomer(cnic)){
        return true;
    }
    else{
        return false;
    }
}
void BusinessLayer::addCustomer(QString cnic, QString n, QString p, QString a){
    DataLayer d;
    d.addCustomer(cnic,n,p,a);
}
/*int BusinessLayer::searchHall(Reservation o)
{
    QString Date=o.getDate();
    QString Time=o.getTime();
    DataLayer d;
    return d.searchHall(Date,Time);
}*/

bool BusinessLayer::allocateTable(Reservation r,int noc,QString cnic)
{
    DataLayer d;
    if(d.allocateTable(r.getDate(),r.getTime(),noc,cnic))
    {
        return true;
    }
    return false;
}

bool BusinessLayer::allocateHall(QString cnic,Reservation r)
{
    DataLayer d;
    if(d.allocateHall(cnic,r.getDate(),r.getTime()))
    {
        return true;
    }
    return false;
}

bool BusinessLayer::DineIn(int noc,QString cnic,QString w_cnic,QString date,QString time)
{
    DataLayer d;
    if(d.DineIn(noc,cnic,w_cnic,date,time))
    {
        return true;
    }
    return false;
}

bool BusinessLayer::retrieveCustomers(vector<Customer*> *cust)
{
    DataLayer d;
    if(d.retrieveCustomers(cust))
    {
        return true;
    }
    return false;
}
bool BusinessLayer::retrieveEmployee(vector<Employee*> *emp)
{
    DataLayer d;
    if(d.retrieveEmployees(emp))
    {
        return true;
    }
    return false;
}
bool BusinessLayer::retrieveHalls(vector<SittingArrangement*> *halls)
{
    DataLayer d;
    if(d.retrieveHalls(halls))
    {
        return true;
    }
    return false;
}
