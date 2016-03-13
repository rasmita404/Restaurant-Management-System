#ifndef DEAL_H
#define DEAL_H
//#include "itemwithamount.h"
#include "fooditem.h"
#include <string>
#include<vector>
using namespace std;
class Deal
{
private:
    QString name;
    double price;
    vector<int> food_item;
    int Quantity;
    int id;
    bool isChecked;
public:
    Deal();
    void setIsChecked(bool flag){isChecked=flag;}
      bool getIsChecked(){return isChecked;}
    int getId(){return id;}
    void setId(int _id){id=_id;}
    void setName(QString n){name=n;}
    void setPrice(double p){price=p;}
    void addFoodId(int id){food_item.push_back(id);}
    QString getName(){return name;}
    void setQuantity(int q){Quantity=q;}
    double getPrice(){return price;}
    vector<int> getFoodId(){return food_item;}
     int getQuantity(){return Quantity;}
};

#endif // DEAL_H
