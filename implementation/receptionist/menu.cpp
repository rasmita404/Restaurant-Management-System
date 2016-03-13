#include "menu.h"
#include "ui_menu.h"
#include <string>
#include <QCheckBox>
#include <QComboBox>
#include <QtGui>
#include "businesslayer.h"
#include "quantity.h"
#include <QMessageBox>
#include <QtDebug>

void Menu::displayMenu(vector<FoodItem*>*appetizer,vector<FoodItem*>*dessert,vector<FoodItem*>*italian,vector<FoodItem*>*chinese,vector<FoodItem*>*other, vector<Deal>*deal){
BusinessLayer bl;
bl.getMenu(appetizer,dessert,italian,chinese,other,deal);

}

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{

    //cout<<"ctor csasd"<<endl;
    displayMenu(&appetizer,&dessert,&italian,&chinese,&other,&deal);
    closed=true;
    ui->setupUi(this);
    quantity=new Quantity();
    while (ui->Appetizer->rowCount() > 0)
    {
        ui->Appetizer->removeRow(0);
    }
    while (ui->Dessert->rowCount() > 0)
    {
        ui->Dessert->removeRow(0);
    }
    while (ui->Italian->rowCount() > 0)
    {
        ui->Italian->removeRow(0);
    }
    while (ui->Chinese->rowCount() > 0)
    {
        ui->Chinese->removeRow(0);
    }
    while (ui->Other->rowCount() > 0)
    {
        ui->Other->removeRow(0);
    }
    while (ui->Deals->rowCount() > 0)
    {
        ui->Deals->removeRow(0);
    }

    count=0;
    setWindowTitle(tr("Menu"));

    ui->Appetizer->setRowCount(appetizer.size());
    ui->Appetizer->setColumnCount(4);
    ui->Appetizer->setWordWrap(true);
    ui->Appetizer->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->Appetizer->setHorizontalHeaderItem(1,new QTableWidgetItem("Item"));
    ui->Appetizer->setHorizontalHeaderItem(2,new QTableWidgetItem("Description"));
    ui->Appetizer->setHorizontalHeaderItem(3,new QTableWidgetItem("Price in Rs"));

    ui->Dessert->setRowCount(dessert.size());
    ui->Dessert->setColumnCount(4);
    ui->Dessert->setWordWrap(true);
    ui->Dessert->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->Dessert->setHorizontalHeaderItem(1,new QTableWidgetItem("Item"));
    ui->Dessert->setHorizontalHeaderItem(2,new QTableWidgetItem("Description"));
    ui->Dessert->setHorizontalHeaderItem(3,new QTableWidgetItem("Price in Rs"));

    ui->Italian->setRowCount(italian.size());
    ui->Italian->setColumnCount(4);
    ui->Italian->setWordWrap(true);
    ui->Italian->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->Italian->setHorizontalHeaderItem(1,new QTableWidgetItem("Item"));
    ui->Italian->setHorizontalHeaderItem(2,new QTableWidgetItem("Description"));
    ui->Italian->setHorizontalHeaderItem(3,new QTableWidgetItem("Price in Rs"));

    ui->Chinese->setRowCount(chinese.size());
    ui->Chinese->setColumnCount(4);
    ui->Chinese->setWordWrap(true);
    ui->Chinese->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->Chinese->setHorizontalHeaderItem(1,new QTableWidgetItem("Item"));
    ui->Chinese->setHorizontalHeaderItem(2,new QTableWidgetItem("Description"));
    ui->Chinese->setHorizontalHeaderItem(3,new QTableWidgetItem("Price in Rs"));


    ui->Other->setRowCount(other.size());
    ui->Other->setColumnCount(4);
    ui->Other->setWordWrap(true);
    ui->Other->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->Other->setHorizontalHeaderItem(1,new QTableWidgetItem("Item"));
    ui->Other->setHorizontalHeaderItem(2,new QTableWidgetItem("Description"));
    ui->Other->setHorizontalHeaderItem(3,new QTableWidgetItem("Price in Rs"));

    ui->Deals->setRowCount(deal.size());
    ui->Deals->setColumnCount(4);
    ui->Deals->setWordWrap(true);
    ui->Deals->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->Deals->setHorizontalHeaderItem(1,new QTableWidgetItem("Name"));
    ui->Deals->setHorizontalHeaderItem(2,new QTableWidgetItem("Items"));
    ui->Deals->setHorizontalHeaderItem(3,new QTableWidgetItem("Price in Rs"));



    for(int i=0; i<ui->Appetizer->rowCount(); i++)
       {

           ui->Appetizer->setRowHeight( i, 40 );
           for(int j=0; j<ui->Appetizer->columnCount(); j++)
           {

               if(j>0){
               ui->Appetizer->setColumnWidth( j, 150 );

               }
               else{

                   ui->Appetizer->setColumnWidth( j, 15 );

               }
               QTableWidgetItem *pCell = ui->Appetizer->item(i, j);
               if(!pCell)
               {
                   pCell = new QTableWidgetItem;
                   pCell->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);


                   QCheckBox *check=new QCheckBox();
                   check->setText("");
                   check->setChecked(false);
                   check->setObjectName(QString::number(appetizer[i]->getId()));
                   connect(check, SIGNAL(stateChanged(int)), this, SLOT(cb_clicked(int)));

                   if(j==0){
                       ui->Appetizer->setCellWidget(i,j,check);

                   }
                   else{
                   ui->Appetizer->setItem(i, j, pCell);
                   }
               }
               if(j==1){
               pCell->setText(appetizer[i]->getName());
               }
               else if(j==2){
                   pCell->setText(appetizer[i]->getDescription());

               }
               else if(j==3){

                   pCell->setText(QString::number(appetizer[i]->getPrice()));
               }

           }
       }
       for(int i=0; i<ui->Dessert->rowCount(); i++)
       {

           ui->Dessert->setRowHeight( i, 40 );



           for(int j=0; j<ui->Dessert->columnCount(); j++)
           {

               if(j>0){
               ui->Dessert->setColumnWidth( j, 150 );

               }
               else{

                   ui->Dessert->setColumnWidth( j, 15 );

               }


               QTableWidgetItem *pCell = ui->Dessert->item(i, j);
               if(!pCell)
               {
                   pCell = new QTableWidgetItem;
                   pCell->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                   QCheckBox *check=new QCheckBox();
                   check->setText("");
                   check->setChecked(false);
                   check->setObjectName(QString::number(dessert[i]->getId()));
                   connect(check, SIGNAL(stateChanged(int)), this, SLOT(cb_clicked(int)));

                   if(j==0){
                       ui->Dessert->setCellWidget(i,j,check);

                   }
                   else{
                   ui->Dessert->setItem(i, j, pCell);
                   }
               }
               if(j==1){
               pCell->setText(dessert[i]->getName());
               }
               else if(j==2){
                   pCell->setText(dessert[i]->getDescription());

               }
               else if(j==3){

                   pCell->setText(QString::number(dessert[i]->getPrice()));
               }

           }
       }

       for(int i=0; i<ui->Italian->rowCount(); i++)
       {

           ui->Italian->setRowHeight( i, 40 );



           for(int j=0; j<ui->Italian->columnCount(); j++)
           {

               if(j>0){
               ui->Italian->setColumnWidth( j, 150 );

               }
               else{

                   ui->Italian->setColumnWidth( j, 15 );

               }


               QTableWidgetItem *pCell = ui->Italian->item(i, j);
               if(!pCell)
               {
                   pCell = new QTableWidgetItem;
                   pCell->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                   QCheckBox *check=new QCheckBox();
                   check->setText("");
                   check->setChecked(false);
                   check->setObjectName(QString::number(italian[i]->getId()));
                   connect(check, SIGNAL(stateChanged(int)), this, SLOT(cb_clicked(int)));

                   if(j==0){
                       ui->Italian->setCellWidget(i,j,check);

                   }
                   else{
                   ui->Italian->setItem(i, j, pCell);
                   }
               }
               if(j==1){
               pCell->setText(italian[i]->getName());
               }
               else if(j==2){
                   pCell->setText(italian[i]->getDescription());

               }
               else if(j==3){

                   pCell->setText(QString::number(italian[i]->getPrice()));
               }

           }
       }
       for(int i=0; i<ui->Chinese->rowCount(); i++)
       {

           ui->Chinese->setRowHeight( i, 40 );



           for(int j=0; j<ui->Chinese->columnCount(); j++)
           {

               if(j>0){
               ui->Chinese->setColumnWidth( j, 150 );

               }
               else{

                   ui->Chinese->setColumnWidth( j, 15 );

               }


               QTableWidgetItem *pCell = ui->Chinese->item(i, j);
               if(!pCell)
               {
                   pCell = new QTableWidgetItem;
                   pCell->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                   QCheckBox *check=new QCheckBox();
                   check->setText("");
                   check->setChecked(false);
                   check->setObjectName(QString::number(chinese[i]->getId()));
                   connect(check, SIGNAL(stateChanged(int)), this, SLOT(cb_clicked(int)));

                   if(j==0){
                       ui->Chinese->setCellWidget(i,j,check);

                   }
                   else{
                   ui->Chinese->setItem(i, j, pCell);
                   }
               }
               if(j==1){
               pCell->setText(chinese[i]->getName());
               }
               else if(j==2){
                   pCell->setText(chinese[i]->getDescription());

               }
               else if(j==3){

                   pCell->setText(QString::number(chinese[i]->getPrice()));
               }
           }
       }
       for(int i=0; i<ui->Other->rowCount(); i++)
       {

           ui->Other->setRowHeight( i, 40 );



           for(int j=0; j<ui->Other->columnCount(); j++)
           {

               if(j>0){
               ui->Other->setColumnWidth( j, 150 );

               }
               else{

                   ui->Other->setColumnWidth( j, 15 );

               }


               QTableWidgetItem *pCell = ui->Other->item(i, j);
               if(!pCell)
               {
                   pCell = new QTableWidgetItem;
                   pCell->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                   QCheckBox *check=new QCheckBox();
                   check->setText("");
                   check->setChecked(false);
                   check->setObjectName(QString::number(other[i]->getId()));
                   connect(check, SIGNAL(stateChanged(int)), this, SLOT(cb_clicked(int)));


                   if(j==0){
                       ui->Other->setCellWidget(i,j,check);

                   }
                   else{
                   ui->Other->setItem(i, j, pCell);
                   }
               }
               if(j==1){
               pCell->setText(other[i]->getName());
               }
               else if(j==2){
                   pCell->setText(other[i]->getDescription());

               }
               else if(j==3){

                   pCell->setText(QString::number(other[i]->getPrice()));
               }
           }
       }

       for(int i=0; i<ui->Deals->rowCount(); i++)
       {

               ui->Deals->setRowHeight( i, 40 );

           for(int j=0; j<ui->Deals->columnCount(); j++)
           {

               if(j>0){
               ui->Deals->setColumnWidth( j, 150 );

               }
               else{

                   ui->Deals->setColumnWidth( j, 15 );

               }


               QTableWidgetItem *pCell = ui->Deals->item(i, j);
               if(!pCell)
               {
                   pCell = new QTableWidgetItem;
                   pCell->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                   QCheckBox *check=new QCheckBox();
                   check->setText("");
                   check->setChecked(false);
                   check->setObjectName(QString::number(deal[i].getId()));
                   connect(check, SIGNAL(stateChanged(int)), this, SLOT(cb_clicked(int)));


                   if(j==0){
                       ui->Deals->setCellWidget(i,j,check);

                   }
                   else{
                   ui->Deals->setItem(i, j, pCell);
                   }
               }
               if(j==1){
               pCell->setText(deal[i].getName());
               }
               else if(j==2){
                   QComboBox *comboBox = new QComboBox;

                   for(int k=0;k<deal[i].getFoodId().size();k++){
                       bool added=0;
                       for(int m=0;m<appetizer.size();m++){
                            if(appetizer[m]->getId()==deal[i].getFoodId()[k]){
                                 added=true;
                                 comboBox->addItem(tr(appetizer[m]->getName().toStdString().c_str()));
                                 break;
                            }
                           }
                            if(!added){
                                for(int m=0;m<dessert.size();m++){
                                     if(dessert[m]->getId()==deal[i].getFoodId()[k]){
                                          added=true;
                                          comboBox->addItem(tr(dessert[m]->getName().toStdString().c_str()));
                                          break;
                                     }
                                }

                            }
                            if(!added){
                                for(int m=0;m<chinese.size();m++){
                                     if(chinese[m]->getId()==deal[i].getFoodId()[k]){
                                          added=true;
                                          comboBox->addItem(tr(chinese[m]->getName().toStdString().c_str()));
                                          break;
                                     }
                                }

                            }
                            if(!added){
                                for(int m=0;m<italian.size();m++){
                                     if(italian[m]->getId()==deal[i].getFoodId()[k]){
                                          added=true;
                                          comboBox->addItem(tr(italian[m]->getName().toStdString().c_str()));
                                          break;
                                     }
                                }

                            }
                            if(!added){
                                for(int m=0;m<other.size();m++){
                                     if(other[m]->getId()==deal[i].getFoodId()[k]){
                                          added=true;
                                          comboBox->addItem(tr(other[m]->getName().toStdString().c_str()));
                                          break;
                                     }
                                }

                            }

                   }
                   ui->Deals->setCellWidget(i, j, comboBox);


               }
               else if(j==3){

                   pCell->setText(QString::number(deal[i].getPrice()));
               }
           }
    }

}

Menu::~Menu()
{
    delete ui;
}
void Menu::onCustomerCnicSend(const QString &text){
ui->customer_cnic_1->setText(text);
}

void Menu::on_pushButton_3_clicked()
{
    //main.show();
    //this->close();
}

void Menu::on_pushButton_clicked()
{

    closed=true;
    this->close();
}
void Menu::saveOrder(QString c_cnic, vector<QString>food_item,vector<double> food_item_price, vector<QString> _deal,vector<double> _deal_price){
BusinessLayer bl;
bl.saveOrder(c_cnic,food_item,food_item_price,_deal,_deal_price);

}

void Menu::on_commandLinkButton_clicked()
{
    QString c_cnic=ui->customer_cnic_1->text();
    vector<QString> food_item;
    vector<QString> _deal;
    vector<double>_deal_price;
    vector<double>food_item_price;

    if(count!=0)
    {
        for(int i=0;i<appetizer.size();i++){
            if(appetizer[i]->getIsChecked()==true){
                food_item.push_back(appetizer[i]->getName());
                food_item_price.push_back(appetizer[i]->getPrice()*appetizer[i]->getQuantity());
            }
        }
        for(int i=0;i<dessert.size();i++){
            if(dessert[i]->getIsChecked()==true){
                food_item.push_back(dessert[i]->getName());
                food_item_price.push_back(dessert[i]->getPrice()*dessert[i]->getQuantity());
            }
        }
        for(int i=0;i<italian.size();i++){
            if(italian[i]->getIsChecked()==true){
                food_item.push_back(italian[i]->getName());
                food_item_price.push_back(italian[i]->getPrice()*italian[i]->getQuantity());
            }
        }
        for(int i=0;i<chinese.size();i++){
            if(chinese[i]->getIsChecked()==true){
                food_item.push_back(chinese[i]->getName());
                food_item_price.push_back(chinese[i]->getPrice()*chinese[i]->getQuantity());
            }
        }
        for(int i=0;i<other.size();i++){
            if(other[i]->getIsChecked()==true){
                food_item.push_back(other[i]->getName());
                food_item_price.push_back(other[i]->getPrice()*other[i]->getQuantity());
            }
        }
        for(int i=0;i<deal.size();i++){
            if(deal[i].getIsChecked()==true){
                _deal.push_back(deal[i].getName());
                _deal_price.push_back(deal[i].getPrice()*deal[i].getQuantity());
            }
        }
        saveOrder(c_cnic,food_item,food_item_price,_deal,_deal_price);

        QMessageBox msg;
        msg.setText("Order Placed");
        msg.exec();
        this->close();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Please select at least one item");
        msg.exec();
    }
}
void Menu::cb_clicked(int state)
{
    bool changed=0;
    QObject *signalSender = sender();
    QCheckBox *cb = static_cast<QCheckBox*>(signalSender);
    if(state)
    {
        count++;
        ui->scrollArea->setDisabled(true);
            for(int i=0;i<appetizer.size();i++){
                if(appetizer[i]->getId()==cb->objectName().toInt()){
                    quantity->setItemName(appetizer[i]->getName(),this,cb);
                    changed=true;
                    break;

                }

            }
            if(!changed){
                for(int i=0;i<dessert.size();i++){
                    if(dessert[i]->getId()==cb->objectName().toInt()){
                    quantity->setItemName(dessert[i]->getName(),this,cb);
                    changed=true;
                    break;
                    }
                }
            }
            if(!changed){
                for(int i=0;i<italian.size();i++){
                  if(italian[i]->getId()==cb->objectName().toInt()){
                    quantity->setItemName(italian[i]->getName(),this,cb);
                    changed=true;
                    break;
                  }


                }
            }
            if(!changed){
                for(int i=0;i<chinese.size();i++){
                  if(chinese[i]->getId()==cb->objectName().toInt()){
                    quantity->setItemName(chinese[i]->getName(),this,cb);
                    changed=true;
                    break;
                  }


                }
            }
            if(!changed){
                for(int i=0;i<other.size();i++){
                 if(other[i]->getId()==cb->objectName().toInt()){
                    quantity->setItemName(other[i]->getName(),this,cb);
                    changed=true;
                    break;
                 }


                }
            }
            if(!changed){
                for(int i=0;i<deal.size();i++){
                 if(deal[i].getId()==cb->objectName().toInt()){
                    quantity->setItemName(deal[i].getName(),this,cb);
                    changed=true;
                    break;
                 }


                }
            }
            quantity->show();
          }
            else
            {

        count--;
                        for(int i=0;i<appetizer.size();i++){
                            if(appetizer[i]->getId()==cb->objectName().toInt()){
                                appetizer[i]->setIsChecked(false);
                                double current_bill=ui->Bill->text().toDouble();
                                current_bill-=appetizer[i]->getPrice()*appetizer[i]->getQuantity();
                                ui->Bill->setText(QString::number(current_bill));
                                changed=true;
                                break;


                            }

                        }
                        if(!changed){
                            for(int i=0;i<dessert.size();i++){
                                if(dessert[i]->getId()==cb->objectName().toInt()){
                                dessert[i]->setIsChecked(false);
                                    double current_bill=ui->Bill->text().toDouble();
                                current_bill-=dessert[i]->getPrice()*dessert[i]->getQuantity();
                                ui->Bill->setText(QString::number(current_bill));
                                changed=true;
                                break;
                                }
                            }
                        }
                        if(!changed){
                            for(int i=0;i<italian.size();i++){
                              if(italian[i]->getId()==cb->objectName().toInt()){
                                 italian[i]->setIsChecked(false);
                                double current_bill=ui->Bill->text().toDouble();
                                current_bill-=italian[i]->getPrice()*italian[i]->getQuantity();
                                ui->Bill->setText(QString::number(current_bill));
                                changed=true;
                                break;
                              }


                            }
                        }
                        if(!changed){
                            for(int i=0;i<chinese.size();i++){
                              if(chinese[i]->getId()==cb->objectName().toInt()){
                                 chinese[i]->setIsChecked(false);
                                double current_bill=ui->Bill->text().toDouble();
                                current_bill-=chinese[i]->getPrice()*chinese[i]->getQuantity();
                                ui->Bill->setText(QString::number(current_bill));
                                changed=true;
                                break;
                              }


                            }
                        }
                        if(!changed){
                            for(int i=0;i<other.size();i++){
                             if(other[i]->getId()==cb->objectName().toInt()){
                                other[i]->setIsChecked(false);
                                double current_bill=ui->Bill->text().toDouble();
                                current_bill-=other[i]->getPrice()*other[i]->getQuantity();
                                ui->Bill->setText(QString::number(current_bill));
                                changed=true;
                                break;
                             }


                            }
                        }
                        if(!changed){
                            for(int i=0;i<deal.size();i++){
                             if(deal[i].getId()==cb->objectName().toInt()){
                                deal[i].setIsChecked(false);
                                double current_bill=ui->Bill->text().toDouble();
                                current_bill-=deal[i].getPrice()*deal[i].getQuantity();
                                ui->Bill->setText(QString::number(current_bill));
                                changed=true;
                                break;
                             }


                            }
                        }
           }
}
void Menu::setBill(int q,QCheckBox* cb){
    bool changed=0;
    double current_bill=ui->Bill->text().toDouble();
    double value_to_add=0;
    ui->scrollArea->setDisabled(false);
        for(int i=0;i<appetizer.size();i++){
            if(appetizer[i]->getId()==cb->objectName().toInt()){
                appetizer[i]->setQuantity(q);
                appetizer[i]->setIsChecked(true);
                value_to_add=appetizer[i]->getPrice()*appetizer[i]->getQuantity();
                changed=true;
                break;
            }

        }
        if(!changed){
            for(int i=0;i<dessert.size();i++){
                if(dessert[i]->getId()==cb->objectName().toInt()){
                    dessert[i]->setQuantity(q);
                    dessert[i]->setIsChecked(true);
                value_to_add=dessert[i]->getPrice()*dessert[i]->getQuantity();
                changed=true;
                break;
                }
            }
        }
        if(!changed){
            for(int i=0;i<italian.size();i++){
              if(italian[i]->getId()==cb->objectName().toInt()){
                  italian[i]->setQuantity(q);
                  italian[i]->setIsChecked(true);
                value_to_add=italian[i]->getPrice()*italian[i]->getQuantity();
                changed=true;
                break;
              }


            }
        }
        if(!changed){
            for(int i=0;i<chinese.size();i++){
              if(chinese[i]->getId()==cb->objectName().toInt()){
                  chinese[i]->setQuantity(q);
                  chinese[i]->setIsChecked(true);
                value_to_add=chinese[i]->getPrice()*chinese[i]->getQuantity();
                changed=true;
                break;
              }


            }
        }
        if(!changed){
            for(int i=0;i<other.size();i++){
             if(other[i]->getId()==cb->objectName().toInt()){
                 other[i]->setQuantity(q);
                 other[i]->setIsChecked(true);
                value_to_add=other[i]->getPrice()*other[i]->getQuantity();
                changed=true;
                break;
             }


            }
        }
        if(!changed){
            for(int i=0;i<deal.size();i++){
             if(deal[i].getId()==cb->objectName().toInt()){
                 deal[i].setQuantity(q);
                 deal[i].setIsChecked(true);
                value_to_add=deal[i].getPrice()*deal[i].getQuantity();
                changed=true;
                break;
             }


            }
        }
current_bill+=value_to_add;
ui->Bill->setText(QString::number(current_bill));

}
