#include "restaurant.h"
#include <QList>
#include "ui_restaurant.h"
#include <memory>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QCheckBox>
#include <QDialog>
#include <QGraphicsPixmapItem>
#include <vector>
#include <iostream>
using namespace std;
Restaurant::Restaurant(QWidget *parent,Dialog* d) :
    QMainWindow(parent),
    ui(new Ui::Restaurant)
{
	myRateDialog=d;
    ui->setupUi(this);
    price=0;
    ui->addMembership->setVisible(false);
    ui->memberFeeNotice->setText("<font color='green'> Add Rs.1000 Membership fee in my bill</font>");
    ui->memberFeeNotice->setVisible(false);
    ui->warningMessage->setText("<font color='red'> Warning! This can not be unchecked.</font>");
    ui->warningMessage->setVisible(false);

	newCustomer=new Normal("1223445678891","Ali","6B, Model Town, Lahore","03214567890");
    QPalette palette = ui->menuDisplay->palette();
    palette.setBrush(QPalette::Highlight,QBrush(Qt::white));
    palette.setBrush(QPalette::HighlightedText,QBrush(Qt::black));
    ui->menuDisplay->setPalette(palette);

	if(newCustomer->isAMember())
		ui->getMembership->setEnabled(false);

	FoodItem* test=new MainCourse("Egg fried rice","Egg, Rice, Black pepper",270);
	FoodItem* test2=new MainCourse("Chicken Karahi","Toasted Chicken, Tomatoes, Green Chilli, Coriander, Black pepper, Mint, Olive oil, Mushrooms",220);
	Order testOrder;
	ItemWithAmount only(test2,2);
	testOrder.addItemWithAmount(only);
	(restaurantMenu.displayMenu()).emplace_back(test);
	restaurantMenu.displayMenu().emplace_back(test2);
	Deal newDeal("makeOne",780);
	newDeal.addItemWithAmount(only);
	ItemWithAmount testing(test,3);
	newDeal.addItemWithAmount(testing);
	restaurantMenu.getDealList().emplace_back(newDeal);
	testOrder.addDeal(newDeal);
	newCustomer->addOrder(testOrder);
	customerMenu=newCustomer->getMenu(restaurantMenu);
    

		 for(int i=0;i<customerMenu.displayMenu().size();++i)
		 {
			 ui->menuDisplay->insertRow(i);
			 QTableWidgetItem* checkBox=new QTableWidgetItem();
			 checkBox->setCheckState(Qt::Unchecked);
			 ui->menuDisplay->setItem(i,0,checkBox);
			  QTableWidgetItem* itemType=new QTableWidgetItem();
			  itemType->setText(QString::fromStdString(customerMenu.displayMenu()[i]->getType()));
			  ui->menuDisplay->setItem(i,1,itemType);
			 QTableWidgetItem* itemName=new QTableWidgetItem();
			 itemName->setText(QString::fromStdString(customerMenu.displayMenu()[i]->getName()));
			 ui->menuDisplay->setItem(i,2,itemName);
			 QTableWidgetItem* itemIngredients=new QTableWidgetItem();
			 itemIngredients->setText(QString::fromStdString(customerMenu.displayMenu()[i]->getIngredients()));
			 ui->menuDisplay->setItem(i,3,itemIngredients);
			 QTableWidgetItem* itemPrice=new QTableWidgetItem();
             itemPrice->setText(QString::number(customerMenu.displayMenu()[i]->getPrice()));
			 ui->menuDisplay->setItem(i,4,itemPrice);
			 QSpinBox* quantitySet=new QSpinBox();
			 quantitySet->setMinimum(1);
			 ui->menuDisplay->setCellWidget(i,5,quantitySet);
		 }
		 ui->menuDisplay->resizeColumnsToContents();
		 for(int i=0;i<customerMenu.getDealList().size();++i)
		 {
			 ui->dealDisplay->insertRow(i);
			 QTableWidgetItem* checkBox=new QTableWidgetItem();
			 checkBox->setCheckState(Qt::Unchecked);
			 ui->dealDisplay->setItem(i,0,checkBox);
			 QTableWidgetItem* dealName=new QTableWidgetItem();
			 dealName->setText(QString::fromStdString(customerMenu.getDealList()[i].getName()));
			 ui->dealDisplay->setItem(i,1,dealName);
			 QTableWidgetItem* dealItems=new QTableWidgetItem();
			 dealItems->setText(QString::fromStdString(customerMenu.getDealList()[i].getItemNames()));
			 ui->dealDisplay->setItem(i,2,dealItems);
			 QTableWidgetItem* dealPrice=new QTableWidgetItem();
             dealPrice->setText(QString::number((customerMenu.getDealList()[i].getPrice())));
			 ui->dealDisplay->setItem(i,3,dealPrice);
			 QSpinBox* quantitySet=new QSpinBox();
			 quantitySet->setMinimum(1);
			 ui->dealDisplay->setCellWidget(i,4,quantitySet);
		 }
		 ui->dealDisplay->resizeColumnsToContents();
		 QPixmap myPic("C:/Qt/Qt5.1.1/Tools/QtCreator/bin/RestaurantManagementSystem/restaurant.png");
		 ui->Picture->setPixmap(myPic);
	 }


void Restaurant::onGetMembershipClicked()
{
    ui->addMembership->setVisible(true);
    ui->warningMessage->setVisible(true);
    ui->memberFeeNotice->setVisible(true);
}

void Restaurant::activatePlaceOrder()
{
	QItemSelectionModel* selectionModel1 = ui->menuDisplay->selectionModel();
	QItemSelectionModel* selectionModel2=ui->dealDisplay->selectionModel();
	QModelIndexList selected1 = selectionModel1->selectedRows(),selected2=selectionModel2->selectedRows();
    int count1=selected1.count();
	int count2=selected2.count();
    if(count1>0 || count2>0)
    {
        ui->placeOrder->setEnabled(true);
        ui->payBill->setEnabled(true);
    }
    else
    {
        ui->placeOrder->setEnabled(false);
        ui->payBill->setEnabled(false);
    }
}

void Restaurant::handleCheckBox(QModelIndex index)
{
    if(ui->menuDisplay->item(index.row(),0)->checkState()==(Qt::Checked))
        ui->menuDisplay->item(index.row(),0)->setCheckState(Qt::Unchecked);
    else
        ui->menuDisplay->item(index.row(),0)->setCheckState(Qt::Checked);
}

void Restaurant::handleCheckBoxForDeal(QModelIndex index)
{
    if(ui->dealDisplay->item(index.row(),0)->checkState()==(Qt::Checked))
        ui->dealDisplay->item(index.row(),0)->setCheckState(Qt::Unchecked);
    else
        ui->dealDisplay->item(index.row(),0)->setCheckState(Qt::Checked);
}

void Restaurant::onPlaceOrderClicked()
{
	ui->rate->setEnabled(true);
    QItemSelectionModel* selectionModel1 = ui->menuDisplay->selectionModel();
    QModelIndexList selected1 = selectionModel1->selectedRows();
	Order newOrder;
	FoodItem* selectedFood;
    int count1=selected1.count();
    for(int i=0;i<count1;++i)
    {
        QModelIndex index=selected1.at(i);
        if(ui->menuDisplay->item(index.row(),0)->checkState()==(Qt::Checked))
        {
			QSpinBox* takeQuantity=(QSpinBox*)ui->menuDisplay->cellWidget(index.row(),5);
			int p=takeQuantity->value();
			price+=(ui->menuDisplay->item(index.row(),4)->text().toInt() * p);
			if(ui->menuDisplay->item(index.row(),1)->text()=="Appetizer")
				selectedFood=new Appetizer(ui->menuDisplay->item(index.row(),2)->text().toStdString(),ui->menuDisplay->item(index.row(),3)->text().toStdString(),ui->menuDisplay->item(index.row(),4)->text().toInt());
			else if(ui->menuDisplay->item(index.row(),1)->text()=="MainCourse")
				selectedFood=new MainCourse(ui->menuDisplay->item(index.row(),2)->text().toStdString(),ui->menuDisplay->item(index.row(),3)->text().toStdString(),ui->menuDisplay->item(index.row(),4)->text().toInt());
			else if(ui->menuDisplay->item(index.row(),1)->text()=="Dessert")
				selectedFood=new Dessert(ui->menuDisplay->item(index.row(),2)->text().toStdString(),ui->menuDisplay->item(index.row(),3)->text().toStdString(),ui->menuDisplay->item(index.row(),4)->text().toInt());
            ItemWithAmount myItem(selectedFood,p);
           newOrder.addItemWithAmount(myItem);
        }
    }
	QItemSelectionModel* selectionModel2 = ui->dealDisplay->selectionModel();
    QModelIndexList selected2 = selectionModel2->selectedRows();
	//Deal selectedDeal;
    int count2=selected2.count();
    for(int i=0;i<count2;++i)
    {
        QModelIndex index=selected2.at(i);
        if(ui->dealDisplay->item(index.row(),0)->checkState()==(Qt::Checked))
        {
			QSpinBox* takeQuantity=(QSpinBox*)ui->dealDisplay->cellWidget(index.row(),4);
			int p=takeQuantity->value();
			price+=(ui->dealDisplay->item(index.row(),3)->text().toInt() * p);
			Deal selectedDeal(ui->dealDisplay->item(index.row(),1)->text().toStdString(),ui->dealDisplay->item(index.row(),3)->text().toInt());
			for(int j=0;j<customerMenu.getDealList().size();++j)
			{
				if(selectedDeal==customerMenu.getDealList()[j])
				{
					selectedDeal=customerMenu.getDealList()[j];
				}
			}
            newOrder.addDeal(selectedDeal);
        }
    }
    QString r="Total: Rs.";
    ui->billAmount->setText((QString)r.append(QString::number(price)));
	newCustomer->addOrder(newOrder);

	
		for(int  i=0;i<newOrder.getItemList().size();++i)
		{
			string myQ="INSERT INTO dbo._Order VALUES (";
			myQ.append(newCustomer->getCNIC());
			myQ.append(", ");
			myQ.append(newOrder.getItemList()[i].getFoodItem()->getName());
			myQ.append(", ");
            myQ.append(std::to_string((long double)(newOrder.getItemList()[i].getQuantity())));
			myQ.append(", null");
		//	query.exec(myQ);
		}

	
    ui->billAmount->setVisible(true);

}
void Restaurant::onRateClicked()
{
    QString m="Karahi";
	myRateDialog=new Dialog(0,newCustomer->getLatestOrder());
	connect(myRateDialog, SIGNAL(accepted()), this, SLOT(GetDialogOutput()));
	myRateDialog->show();
	vector<int> feedback;
	GetDialogOutput(feedback);
	newCustomer->giveFeedbackForOrder(feedback);
	newCustomer->giveFeedbackForWaiter(feedback[0]);
    ui->rate->setEnabled(false);

}

void Restaurant::GetDialogOutput(vector<int>& v)
{
	v=myRateDialog->getRating();
}

void Restaurant::onAddMembershipChecked()
{
    ui->addMembership->setEnabled(false);
	ui->getMembership->setEnabled(false);
    price+=1000;
    QString r="Total: Rs.";
    ui->billAmount->setText((QString)r.append(QString::number(price)));
	newCustomer->getMembership(newCustomer);
}

void Restaurant::onPayBillClicked()
{
    ui->billAmount->setText(QString("Rs 220"));
	newCustomer->payBill(newCustomer);
    ui->billAmount->setHidden(true);

}

Restaurant::~Restaurant()
{
    delete ui;
}

void Restaurant::on_rate_clicked()
{

}
