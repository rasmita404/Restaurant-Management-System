#ifndef CUSTOMER_H
#define CUSTOMER_H
//#include "order.h"
#include "reservation.h"
//#include "itemwithamount.h"
#include <string>
#include <QString>
#include <vector>
using namespace std;
class Customer
{
private:
    QString CNIC;
    QString name;
    QString address;
    QString phone_no;
   // vector<Order> order;
    vector<Reservation> reservation;
public:
    void setAttributes(QString,QString,QString,QString);
    QString getName();
    QString getCNIC();
    QString getAddress();
    QString getPhoneNo();
    //void placeOrder(vector<ItemWithAmount> itemList);
    bool getMembership();
    void payBill();
    void giveFeedback();

};
class Priority:public Customer
{
private:
    float discount;

};
class Normal:public Customer
{

};
#endif // CUSTOMER_H
