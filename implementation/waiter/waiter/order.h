#ifndef ORDER_H
#define ORDER_H
#include"fooditem.h"
class FoodItem;
class Order
{
private:
	FoodItem f;
	int amount;
public:
	Order(FoodItem fo,int amo);
	int calcuateBill();
	FoodItem getfood()
	{
		return f;
	}
	int getamnt()
	{
		return amount;
	}
};

#endif // ORDER_H
