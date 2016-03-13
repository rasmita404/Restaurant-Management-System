#ifndef MENU
#define MENU

#include <iostream>
#include <vector>
#include <QString>
using namespace std;
#include "Fooditem_1.h"

class Menu {
friend class fooditem;
friend class Deal;
public:
    Menu();
   void  Add(QString n, float p,  QString d,QString u, QString t);
    void Remove(QString n);
    void Initialise();
    void print();

private:
vector<FoodItem_1> items;
};




#endif // MENU

