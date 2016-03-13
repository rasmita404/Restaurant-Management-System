#include "customer.h"
#include "order.h"
#include "reservation.h"
#include "itemwithamount.h"
using namespace std;
Customer::Customer()
{
}
Customer::Customer(string nm, int d, vector<Order> ord)
{
	name = nm;
	id = d;
	order = ord;
}