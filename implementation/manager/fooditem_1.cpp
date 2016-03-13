
#include "Fooditem_1.h"
#include <iostream>
using namespace std;

FoodItem_1::FoodItem_1()
{
     name = detail = "";
    price = 0;
    units = "Full";
    type = "Other";
}

FoodItem_1::FoodItem_1(const FoodItem_1 & f) {
    set( f.name, f.price, f.units, f.detail, f.type);
}
void FoodItem_1::set( QString n, float p, QString d, QString u, QString t)
{

    name = n;
    price = p;
    units = u;
    detail = d;
    type = t;
}

QString FoodItem_1::getname()
{
    return name;
}
float FoodItem_1::getprice()
{
    return price;
}
QString FoodItem_1::getunits()
{
    return units;
}
QString FoodItem_1::getdetail() {
    return detail;
}
QString FoodItem_1::gettype() {
    return type;
}
