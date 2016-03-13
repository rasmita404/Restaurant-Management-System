#include "fooditem.h"

QString MainCourse::getType(){
    return "type";
}
QString Dessert::getType(){
    return type;
}
QString Appetizer::getType(){
    return type;
}
QString Italian::getType(){
return type;
}
QString Chinese::getType(){
return type;
}
QString Other::getType(){
return type;
}

FoodItem::FoodItem(){

}
Appetizer::Appetizer(int _id,QString n,QString _description,double p, QString _type){
    name=n;
    price=p;
    type=_type;
    id=_id;
    description=_description;
    Quantity=1;

}
Dessert::Dessert(int _id,QString n,QString _description,double p, QString _type){
    name=n;
    price=p;
    type=_type;
    id=_id;
    description=_description;
    Quantity=1;

}
Italian::Italian(int _id,QString n,QString _description,double p, QString _type){
    name=n;
    price=p;
    type=_type;
    id=_id;
    description=_description;
    Quantity=1;


}
Chinese::Chinese(int _id,QString n,QString _description,double p, QString _type){
    name=n;
    price=p;
    type=_type;
    id=_id;
    description=_description;
    Quantity=1;

}
Other::Other(int _id,QString n,QString _description,double p, QString _type){
    name=n;
    price=p;
    type=_type;
    id=_id;
    description=_description;
    Quantity=1;

}

