#ifndef FOODITEM_H
#define FOODITEM_H
enum Food{ Appetizer, Dessert, Chinese, Italian, Other };
#include <string>
using namespace std;
class FoodItem
{
private:
	string name;
	int price;
string type;
public:
	FoodItem()
	{

	}
	FoodItem operator=(const  FoodItem&f )
	{
		name = f.name;
		price = f.price;
		type = f.type;
		return*this;
	}
	FoodItem(string n, int p, string typ);
	string getnm()
	{
		return name;
	}
	int getoric()
	{
		return price;
	}

//	virtual Food getType() = 0;
};
class Appetizer :public FoodItem
{
public:
	Food getType();

};
class MainCourse :public FoodItem
{
public:
	Food getType();

};
class Chinese :public MainCourse
{

};
class Italian :public MainCourse
{

};
class Other :public MainCourse
{

};
class Dessert :public FoodItem
{
public:
	Food getType();
};
#endif // FOODITEM_H
