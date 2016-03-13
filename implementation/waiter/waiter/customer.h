#ifndef CUSTOMER_H
#define CUSTOMER_H


#include <string>
#include <vector>
using namespace std;
class Order;
class Reservation;
class ItemWithAmount;
class Customer
{
private:
	int id;
	string name;
	string address;
	string phone_no;
	vector<Order> order;
	vector<Reservation*> reservation;
public:
	Customer();

	Customer(string nm, int d, vector<Order> ord);
	void placeOrder(vector<ItemWithAmount> itemList);
	bool getMembership();
	void payBill();
	void giveFeedback();

};
class Priority :public Customer
{
private:
	float discount;

};
class Normal :public Customer
{

};
#endif // CUSTOMER_H
