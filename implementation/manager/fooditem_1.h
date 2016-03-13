#ifndef FOODITEM_1
#define FOODITEM_1

#include <QString>
#include <iostream>
#include <string>
using namespace std;
class FoodItem_1
{
private:

    QString name;
    float price;
    QString units;
    QString detail;
    QString type;

public:
    FoodItem_1();
    FoodItem_1(const FoodItem_1 & f);
    void set( QString n, float p,  QString d,QString u, QString t);

    QString getname();
    float getprice();
    QString getunits();
    QString getdetail();
    QString gettype();
};
struct ItemWithAmount
{
    FoodItem_1* item;
    int quantity;
};

#endif // FOODITEM_1

