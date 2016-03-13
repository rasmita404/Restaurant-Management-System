
#include <iostream>
#include <vector>
#include <QString>
#include <fooditem_1.h>
#include <datalayer.h>

using namespace std;
Menu::Menu() {

}

void Menu::Add (QString n, float p,  QString d,QString u, QString t)
{
   FoodItem_1 ff;
    ff.set(n,p,d,u,t);
    items.push_back(ff);

}
void Menu::Remove(QString n)
{
      for (int i=0; i<items.size(); i++) {
          if (items[i].getname()==n){
              items.erase(items.begin()+i);
                break;
          }
      }
}
void Menu::Initialise() {
    DataLayer d;
    d.InitMenu(this);

}

void Menu::print() {
    for (int i=0; i<items.size(); i++) {
        cout<<items[i].getname().toStdString()<<"\t"<<items[i].getprice()<<"\t";
        cout<<items[i].getdetail().toStdString()<<"\t";
        cout<<items[i].getunits().toStdString()<<"\t";
        cout<<items[i].gettype().toStdString()<<endl;

    }
}
