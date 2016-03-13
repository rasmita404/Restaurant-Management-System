#ifndef DEAL_H
#define DEAL_H
#include "itemwithamount.h"
#include <string>
using namespace std;
class Deal
{
private:
	string name;
	int price;
	vector<ItemWithAmount> item_with_amount;
public:
	Deal();
};

#endif // DEAL_H
