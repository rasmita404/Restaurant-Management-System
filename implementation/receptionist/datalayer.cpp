#include <QString>
#include<iostream>
#include <QtSql>
#include "datalayer.h"

using namespace std;
bool DataLayer::connectDB(){
    QString servername="dell-pc\\sqlexpress";
    QString dbname="practice";
     mydb = QSqlDatabase::addDatabase("QODBC");
    mydb.setConnectOptions();
    QString dsn=QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);
    mydb.setDatabaseName(dsn);
        if(mydb.open()){
            cout<<"Connection established"<<endl;
            return true;
        }

        else{
            cout<<"Connection not established"<<endl;
            return false;
        }

return false;
}
void DataLayer::closeDB(){
    mydb.close();
    //mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

bool DataLayer::saveMenu(){
/*if(connectDB(true)){

    QSqlQuery qry;
    qry.prepare("SELECT * FROM User where Username='"+username+"'and Password='"+password+"'");
    if(qry.exec()){
        int count=0;
        while(qry.next()){
            count++;
        }

    connectDB(false);
    return true;
 }
else{
return false;
}*/
    return true;
}
void DataLayer::getMenu(vector<FoodItem*>*appetizer,vector<FoodItem*>*dessert,vector<FoodItem*>*italian,vector<FoodItem*>*chinese,vector<FoodItem*>*other, vector<Deal>*deal){
    if(connectDB()){
        QSqlQuery qry;
        qry.prepare("Select* from Menu");
        if(qry.exec()){
            while(qry.next()){
                if(qry.value("_type")=="Appetizer"){
                    FoodItem*app=new Appetizer(qry.value("Id").toInt(),qry.value("Name").toString(),qry.value("_Description").toString(),qry.value("Price").toDouble(),qry.value("_type").toString());
                appetizer->push_back(app);
                }
                else if(qry.value("_type")=="Dessert"){
                    FoodItem*dess=new Dessert(qry.value("Id").toInt(),qry.value("Name").toString(),qry.value("_Description").toString(),qry.value("Price").toDouble(),qry.value("_type").toString());
                dessert->push_back(dess);
                }
                else if(qry.value("_type")=="Italian"){
                    FoodItem*itl=new Italian(qry.value("Id").toInt(),qry.value("Name").toString(),qry.value("_Description").toString(),qry.value("Price").toDouble(),qry.value("_type").toString());
                italian->push_back(itl);
                }
                else if(qry.value("_type")=="Chinese"){
                    FoodItem*chn=new Chinese(qry.value("Id").toInt(),qry.value("Name").toString(),qry.value("_Description").toString(),qry.value("Price").toDouble(),qry.value("_type").toString());
                chinese->push_back(chn);
                }
                else if(qry.value("_type")=="Other"){
                    FoodItem*oth=new Other(qry.value("Id").toInt(),qry.value("Name").toString(),qry.value("_Description").toString(),qry.value("Price").toDouble(),qry.value("_type").toString());
                other->push_back(oth);
                }
            }
            cout<<"Menu Query executed"<<endl;
        }
        else{
            cout<<"Menu Query not executed"<<endl;
        }

        QSqlQuery deal_query;
        deal_query.prepare("select distinct name,price from Deal");
        if(deal_query.exec()){
            cout<<"exec"<<endl;
            int counter=appetizer->size()+dessert->size()+italian->size()+chinese->size()+other->size()+1;
            while(deal_query.next()){
                Deal temp_deal;
                temp_deal.setId(counter);
                temp_deal.setName(deal_query.value("name").toString());
                temp_deal.setPrice(deal_query.value("price").toDouble());
                QSqlQuery deal_query_1;
                deal_query_1.prepare("select *from Deal where name='"+temp_deal.getName()+"'");
                if(deal_query_1.exec()){
                    while(deal_query_1.next()){
                        temp_deal.addFoodId(deal_query_1.value("food_id").toInt());


                    }

                }
                deal->push_back(temp_deal);
                counter++;
            }
        }
        else{

            cout<<"not exec"<<endl;
        }

        closeDB();
    }
}
bool DataLayer::checkCustomer(QString cnic){
    if(connectDB()){

        QSqlQuery qry;
        qry.prepare("SELECT * FROM Customer where CNIC='"+cnic+"'");
        qry.exec();
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count>0){
            closeDB();
            return true;
        }
        closeDB();
    }
    return false;
}
void DataLayer::addCustomer(QString cnic, QString n, QString p, QString a){
    if(connectDB()){

       QSqlQuery qry;
       qry.prepare("INSERT INTO Customer (CNIC, Name, Phone_no,_Address)VALUES ('"+cnic+"', '"+n+"', '"+p+"','"+a+"')");
       qry.exec();
       closeDB();
    }
}
int DataLayer::searchHall(QString d,QString t)
{
    if(connectDB()){

       QSqlQuery qry;
       qry.prepare("EXEC searchHall @time = '"+t+"', @date = '"+d+"';");
       qry.exec();
       if(!qry.next())
       {
           return 0;
       }
       else
       {
           int hall=qry.value(0).toInt();
           return hall;
       }
       closeDB();
    }
    return false;
}
bool DataLayer::allocateHall(QString cnic,QString date,QString time)
{
    if(connectDB())
    {
       QSqlQuery qry;

       qry.prepare("Select * from [dbo].[Hall] left outer join Reservation on Id=hall_id where hall_id is null");
       if(qry.exec())
       {
           cout<<"Successfully ran"<<endl;
           if(qry.next()){
                QSqlRecord record = qry.record();
                int idIndex = record.indexOf("id");
                int hall_id=qry.value(idIndex).toInt();
                qry.prepare("INSERT INTO Reservation (_date,_time,hall_id,customer_id) "
                                "VALUES (:_date, :_time, :table_id,:customer_id)");
                qry.bindValue(":_date", date);
                qry.bindValue(":_time", time);
                qry.bindValue(":table_id",hall_id);
                qry.bindValue(":customer_id",cnic);
                if(qry.exec()){
                    return true;
                }
                return false;
            }
            else{
                qry.prepare("select *from [dbo].[Hall] left outer join Reservation on Id=hall_id where _date!=:_date or _time!=:_time");
                qry.bindValue(":_date", date);
                qry.bindValue(":_time", time);
                if(qry.exec()){
                    bool added=false;
                    while(qry.next()){
                        QSqlRecord record = qry.record();
                        int idIndex = record.indexOf("id");
                        int hall_id=qry.value(idIndex).toInt();
                        QSqlQuery qry_1;
                        qry_1.prepare("select* from Reservation where _date=:_d and _time=:_t and hall_id=:_h_id");
                        qry_1.bindValue(":_d", date);
                        qry_1.bindValue(":_t", time);
                        qry_1.bindValue(":_h_id",hall_id);
                        if(qry_1.exec()){
                           // cout<<"Successfully ran 2"<<endl;
                        }
                        //if not already allocated to current table_id in current date and time
                        if(!qry_1.next()){

                            qry.prepare("INSERT INTO Reservation (_date, _time, hall_id,customer_id) "
                                            "VALUES (:_date, :_time, :hall_id,:customer_id)");
                              qry.bindValue(":_date", date);
                              qry.bindValue(":_time", time);
                              qry.bindValue(":hall_id",hall_id);
                              qry.bindValue(":customer_id",cnic);
                              if(qry.exec()){
                                  added=true;
                                  break;
                              }
                            }
                        }
                    if(added){
                        return true;
                    }
                    return false;
                }
                return false;
           }
           return false;
       }
       else
       {
           cout<<"Hall Query didn't run"<<endl;
           return false;
       }
       closeDB();
    }
    return false;
}
bool DataLayer::allocateTable(QString date, QString time, int noc,QString cnic){
    if(connectDB())
    {
       QSqlQuery qry;

       qry.prepare("Select * from [dbo].[Table] left outer join Reservation_Table on Id=table_id where no_of_customers=:_noc and table_id is null");
       qry.bindValue(":_noc", noc);
       if(qry.exec())
       {
           cout<<"Successfully ran"<<endl;
           if(qry.next()){
                QSqlRecord record = qry.record();
                int idIndex = record.indexOf("id");
                 int table_id=qry.value(idIndex).toInt();
               qry.prepare("INSERT INTO Reservation_Table (_date, _time, table_id,customer_id) "
                                "VALUES (:_date, :_time, :table_id,:customer_id)");
                  qry.bindValue(":_date", date);
                  qry.bindValue(":_time", time);
                  qry.bindValue(":table_id",table_id);
                  qry.bindValue(":customer_id",cnic);
                  if(qry.exec()){
                     return true;
                  }
                  return false;
           }
           else{
                qry.prepare("select *from [dbo].[Table] left outer join Reservation_Table on Id=table_id where no_of_customers=:_noc and( _date!=:_date or _time!=:_time)");
                qry.bindValue(":_noc", noc);
                qry.bindValue(":_date", date);
                qry.bindValue(":_time", time);
                if(qry.exec()){
                    bool added=false;
                    while(qry.next()){
                        QSqlRecord record = qry.record();
                        int idIndex = record.indexOf("id");
                         int table_id=qry.value(idIndex).toInt();
                        QSqlQuery qry_1;
                        qry_1.prepare("select* from Reservation_Table where _date=:_d and _time=:_t and table_id=:_t_id");
                        qry_1.bindValue(":_d", date);
                        qry_1.bindValue(":_t", time);
                        qry_1.bindValue(":_t_id",table_id);
                        if(qry_1.exec()){
                           // cout<<"Successfully ran 2"<<endl;
                        }
                        //if not already allocated to current table_id in current date and time
                        if(!qry_1.next()){

                            qry.prepare("INSERT INTO Reservation_Table (_date, _time, table_id,customer_id) "
                                            "VALUES (:_date, :_time, :table_id,:customer_id)");
                              qry.bindValue(":_date", date);
                              qry.bindValue(":_time", time);
                              qry.bindValue(":table_id",table_id);
                              qry.bindValue(":customer_id",cnic);
                              if(qry.exec()){
                                  added=true;
                                  break;
                              }
                            }
                        }
                    if(added){
                        return true;
                    }
                    return false;
                }
                return false;


           }
           return false;
       }
       else
       {
           cout<<"whoops"<<endl;
           return false;
       }


       closeDB();
    }
return false;

}

bool DataLayer::DineIn(int noc,QString cnic,QString w_cnic,QString date,QString time)
{
    if(connectDB())
    {
        QSqlQuery qry;
        qry.prepare("Select * from [dbo].[Table] left outer join Reservation_Table on Id=table_id where no_of_customers=:_noc and table_id is null");
        qry.bindValue(":_noc", noc);
        if(qry.exec())
        {
            cout<<"Successfully ran"<<endl;
            if(qry.next()){
                 QSqlRecord record = qry.record();
                 int idIndex = record.indexOf("id");
                  int table_id=qry.value(idIndex).toInt();
                qry.prepare("INSERT INTO Reservation_Table (waiter_cnic,table_id,customer_id,_date,_time) "
                                 "VALUES (:_waiter_cnic, :_table_id,:_customer_id,:_date,:_time)");
                   qry.bindValue(":_date", date);
                   qry.bindValue(":_time", time);
                   qry.bindValue(":_table_id",table_id);
                   qry.bindValue(":_customer_id",cnic);
                   qry.bindValue(":_waiter_cnic",w_cnic);
                   if(qry.exec()){
                      return true;
                   }
                   return false;
            }
            else{
                 qry.prepare("select *from [dbo].[Table] left outer join Reservation_Table on Id=table_id where no_of_customers=:_noc and (_date!=:_date or _time!=:_time)");
                 qry.bindValue(":_noc", noc);
                 qry.bindValue(":_date", date);
                 qry.bindValue(":_time", time);
                 if(qry.exec()){
                     bool added=false;
                     while(qry.next()){
                         QSqlRecord record = qry.record();
                         int idIndex = record.indexOf("id");
                          int table_id=qry.value(idIndex).toInt();
                         QSqlQuery qry_1;
                         qry_1.prepare("select* from Reservation_Table where _date=:_d and  _time=:_t and table_id=:_t_id");
                         qry_1.bindValue(":_d", date);
                         qry_1.bindValue(":_t", time);
                         qry_1.bindValue(":_t_id",table_id);
                         if(qry_1.exec()){
                            // cout<<"Successfully ran 2"<<endl;
                         }
                         //if not already allocated to current table_id in current date and time
                         if(!qry_1.next()){

                             qry.prepare("INSERT INTO Reservation_Table (_date, _time, table_id,customer_id,waiter_cnic) "
                                             "VALUES (:_date, :_time, :table_id,:customer_id,:w_cnic)");
                               qry.bindValue(":_date", date);
                               qry.bindValue(":_time", time);
                               qry.bindValue(":table_id",table_id);
                               qry.bindValue(":customer_id",cnic);
                               qry.bindValue(":w_cnic",w_cnic);
                               if(qry.exec()){
                                   added=true;
                                   break;
                               }
                             }
                         }
                     if(added){
                         return true;
                     }
                     return false;
                 }
                 return false;


            }
            return false;
        }
        else
        {
            cout<<"whoops"<<endl;
            return false;
        }


        closeDB();
    }
    return false;
}
bool DataLayer::retrieveCustomers(vector<Customer*> *cust)
{
    if(connectDB())
    {
        QSqlQuery qry;
        qry.prepare("Select * from Customer");
        if(qry.exec())
        {
            while(qry.next())
            {
                Customer *c=new Customer();
                c->setAttributes(qry.value("CNIC").toString(),qry.value("Name").toString(),qry.value("Phone_no").toString(),qry.value("_Address").toString());
                cust->push_back(c);
            }
            return true;
        }
        closeDB();
    }
    return false;
}

bool DataLayer::retrieveEmployees(vector<Employee*> *emp)
{
    if(connectDB())
    {
        QSqlQuery qry;
        Employee *e;
        qry.prepare("select * from Employee");
        if(qry.exec())
        {
            while(qry.next())
            {
                if(qry.value("_Type").toString()=="waiter")
                {
                    e=new FullTimeWaiter();

                    QString cnic=qry.value("CNIC").toString();
                    QString name=qry.value("Name").toString();
                    QString type=qry.value("type").toString();
                    QString phone_no=qry.value("Phone_no").toString();
                    QSqlQuery query;
                    query.prepare("select * from Waiter where CNIC='"+cnic+"'");
                    if(query.exec())
                    {
                        query.next();
                        e->setAttributes(name,cnic,phone_no,type,qry.value("Warning_Count").toInt());
                        emp->push_back(e);
                    }
                }
            }
            return true;
        }
        closeDB();
    }
    return false;
}

bool DataLayer::retrieveHalls(vector<SittingArrangement*>*halls)
{
    if(connectDB())
    {
        QSqlQuery qry;
        qry.prepare("Select * from Hall");
        if(qry.exec())
        {
            SittingArrangement *a;
            while(qry.next())
            {
                QString type=qry.value("_Type").toString();
                int id=qry.value("Id").toInt();
                int table_id=qry.value("table_id").toInt();
                a=new Hall();
                QString table_res;
                QSqlQuery tble;
                tble.prepare("Select * from [dbo].[Table] where id="+QString::number(table_id)+"");
                tble.exec();
                a->setAttributes(id,type);
                while(tble.next())
                {
                    if(tble.value("id").toInt()==id)
                    {
                        table_res=tble.value("isReserved").toString();
                        a->addTable(table_id,table_res);
                    }
                }
                halls->push_back(a);
            }
            return true;
        }
        else
        {
            cout<<"Query not executed"<<endl;
        }
        closeDB();
    }
    return false;
}
void DataLayer::saveOrder(QString c_cnic, vector<QString>food_item,vector<double>food_item_price, vector<QString>_deal,vector<double>_deal_price){
    if(connectDB()){
        for(int i=0;i<food_item.size();i++){
            QSqlQuery qry;
            qry.prepare("insert into _Order values('"+c_cnic+"','"+food_item[i]+"',:price,'No')");
            qry.bindValue(":price",food_item_price[i]);
            if(qry.exec()){

            }
        }
        for(int i=0;i<_deal.size();i++){
            QSqlQuery qry;
            qry.prepare("insert into _Order values('"+c_cnic+"','"+_deal[i]+"',:price,'Yes')");
            qry.bindValue(":price",_deal_price[i]);
            if(qry.exec()){

            }
        }


        closeDB();
    }

}
