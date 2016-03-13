#ifndef FOODITEM_H
#define FOODITEM_H
//enum Food{Appetizer,Dessert,Chinese,Italian,Other};
#include <string>
#include <QString>
using namespace std;
class FoodItem
{
protected:
    int id;
    QString name;
    double price;
    QString type;
    QString description;
    int Quantity;
    bool isChecked;
public:
    FoodItem();
    QString getName(){return name;}
    double getPrice(){return price;}
    QString getDescription(){return description;}
    int getId(){return id;}
    void setQuantity(int q){Quantity=q;}
    int getQuantity(){return Quantity;}
    virtual QString getType()=0;
    void setIsChecked(bool flag){isChecked=flag;}
    bool getIsChecked(){return isChecked;}
};
class Appetizer:public FoodItem
{
public:
    Appetizer(int _id,QString n,QString _description,double p,QString _type );

    QString getType();

};
class MainCourse:public FoodItem
{
public:
   virtual QString getType();

};
class Chinese:public MainCourse
{
public:
    Chinese(int _id,QString n,QString _description,double p,QString _type );
QString getType();

};
class Italian:public MainCourse
{
public:
    Italian(int _id,QString n,QString _description,double p,QString _type );
QString getType();

};
class Other:public MainCourse
{
public:
    Other(int _id,QString n,QString _description,double p,QString _type );
QString getType();
};
class Dessert:public FoodItem
{
public:
   Dessert(int _id,QString n,QString _description,double p,QString _type );

   QString getType();
};
#endif // FOODITEM_H
