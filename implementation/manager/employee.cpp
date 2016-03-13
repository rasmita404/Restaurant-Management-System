#include "employee.h"
#include "ui_employee.h"
#include <iostream>
#include <string>
#include "restaurant.h"
#include <QDoubleValidator>
#include <QMessageBox>
using namespace std;
employee::employee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employee)
{
   act=false;
    ui->setupUi(this);

    ui->salary->setValidator(new QDoubleValidator());
    ui->worked->setValidator(new QDoubleValidator());
   ui->rate->setValidator(new QDoubleValidator());
    ui->phone->setValidator(new QIntValidator());
 //   QObject::connect(ui->remove, SIGNAL(clicked()), &e,  SLOT(pattern1()));
}

employee::~employee()
{
    delete ui;
}

void employee::on_type_activated(const QString &arg1)
{

    if (arg1 =="Receptionist [Full Time]" || arg1=="Chef [Full Time]" || arg1=="Security [Full Time]" || arg1=="Waiter [Full Time]") {
      ui->parttime->setHidden(true);
    }
    else {ui->parttime->setHidden(false);}
    if(arg1=="Receptionist [Full Time]" || arg1=="Receptionist [Part Time]") {
        ui->password->setHidden(false);
        ui->passlabel->setHidden(false);
    }
    else {
        ui->password->setHidden(true);
        ui->passlabel->setHidden(true);
    }
}
void employee::pattern1()
{
   ui->remove->setHidden(true);
   ui->getsal->setHidden(true);
   ui->save->setHidden(false);
ui->emplist->setHidden(true);
ui->lablist->setHidden(true);
ui->edittype->setHidden(true);
ui->type->setHidden(false);
ui->selectitem->setHidden(true);
}
void employee::forsal (Restaurant rr) {
    ui->remove->setHidden(true);
    ui->save->setHidden(true);
    ui->getsal->setHidden(false);
    ui->emplist->setHidden(false);
    ui->lablist->setHidden(false);
    ui->selectitem->setHidden(false);
    int rcount=rr.employeelist.size();

    ui->edittype->setHidden(false);
    ui->type->setHidden(true);

    ui->emplist->setRowCount(rcount);

     for (int i=0; i<rcount;i++) {


     ui->emplist->setItem(i, 0,  new QTableWidgetItem(rr.employeelist[i]->getName()));
 //QString str=men.items[i].getprice().toString();

     ui->emplist->setItem(i, 3, new QTableWidgetItem(QString::number(rr.employeelist[i]->getphone())));
     ui->emplist->setItem(i, 1, new QTableWidgetItem(rr.employeelist[i]->getCnic()));
     ui->emplist->setItem(i, 2, new QTableWidgetItem(rr.employeelist[i]->getType()));
     ui->emplist->setItem(i, 4, new QTableWidgetItem(QString::number(rr.employeelist[i]->getSalary())));
     ui->emplist->setItem(i, 5, new QTableWidgetItem(rr.employeelist[i]->getpassword()));
     ui->emplist->setItem(i, 6, new QTableWidgetItem(QString::number(rr.employeelist[i]->getrate())));
     ui->emplist->setItem(i, 7, new QTableWidgetItem(QString::number(rr.employeelist[i]->getworked())));
    }
 ui->emplist->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
void employee::foredit(Restaurant rr) {
    ui->getsal->setHidden(true);
    ui->save->setHidden(false);
    ui->remove->setHidden(false);
    ui->emplist->setHidden(false);
    ui->lablist->setHidden(false);
    ui->edittype->setHidden(false);
    ui->type->setHidden(true);

   ui->selectitem->setHidden(false);
    int rcount=rr.employeelist.size();
    cout<<endl<<rcount<<endl;

     ui->emplist->setRowCount(rcount);

     for (int i=0; i<rcount;i++) {


     ui->emplist->setItem(i, 0,  new QTableWidgetItem(rr.employeelist[i]->getName()));
 //QString str=men.items[i].getprice().toString();

     ui->emplist->setItem(i, 3, new QTableWidgetItem(QString::number(rr.employeelist[i]->getphone())));
     ui->emplist->setItem(i, 1, new QTableWidgetItem(rr.employeelist[i]->getCnic()));
     ui->emplist->setItem(i, 2, new QTableWidgetItem(rr.employeelist[i]->getType()));
     ui->emplist->setItem(i, 4, new QTableWidgetItem(QString::number(rr.employeelist[i]->getSalary())));
     ui->emplist->setItem(i, 5, new QTableWidgetItem(rr.employeelist[i]->getpassword()));
     ui->emplist->setItem(i, 6, new QTableWidgetItem(QString::number(rr.employeelist[i]->getrate())));
     ui->emplist->setItem(i, 7, new QTableWidgetItem(QString::number(rr.employeelist[i]->getworked())));

     }
 ui->emplist->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void employee::on_save_clicked()
{
      QString Name=(ui->name->text());
      QString CNIC=(ui->cnic->text());
      int Phone=(ui->phone->text()).toInt();
      float Salary=(ui->salary->text()).toFloat();
      QString Type=(ui->type->currentText());
      QString Password=(ui->password->text());
      float Hourlyrate=(ui->rate->text()).toFloat();
      float Hourworked=(ui->worked->text()).toFloat();
    // cout<<endl<<Name<<endl<<CNIC<<endl<<Phone<<endl<<Salary<<endl<<Type<<endl<<Password;
    // cout<<endl<<Hourlyrate<<endl<<Hourworked<<endl;
      if (CNIC.trimmed().isEmpty()) {
          QMessageBox msg;
             msg.setText("CNIC cannot be null.");
          msg.exec();
      }
      else {
    m.Add(Name,CNIC,Phone,Salary,Type,Password,Hourlyrate,Hourworked);
    QMessageBox msg;
       msg.setText("Employee saved Successfully.");
    msg.exec();
      }
      ui->name->setText("");
      ui->cnic->setText("");
      ui->phone->setText("");
     ui->salary->setText("");
ui->edittype->setText("");
       ui->password->setText("");
       ui->rate->setText("");
       ui->worked->setText("");


}


void employee::on_remove_clicked()
{
    QString CNIC=(ui->cnic->text());
    if (CNIC.trimmed().isEmpty()) {
        QMessageBox msg;
           msg.setText("CNIC cannot be null.");
        msg.exec();
    }
    else {
    m.RemoveEmployee(CNIC);
     QMessageBox msg;
        msg.setText("Employee removed Successfully.");
     msg.exec();
     ui->name->setText("");
     ui->cnic->setText("");
     ui->phone->setText("");
    ui->salary->setText("");
 ui->edittype->setText("");
      ui->password->setText("");
      ui->rate->setText("");
      ui->worked->setText("");
      ui->emplist->removeRow(rs);
}
}
string removeSpace(string x)
{
    string temp="";
    for(int i=0;i<x.size();i++)
    {
        if(x[i]==' ' && x[i+1]==' ')
        {
            break;
        }
        temp+=x[i];
    }
    return temp;
}

void employee::on_selectitem_clicked()
{
  if(act==true) {
    int row=ui->emplist->currentIndex().row();
     rs=row;
     //cout<<row<<endl;
cout<<row<<endl;
     for (int i=0; i<8; i++) {
         QTableWidgetItem * item= ui->emplist->item(row, i);
         string qq=removeSpace(item->text().toStdString());
         QString q=QString ::fromStdString(qq);
    if (i==0) {

        //cout<<q.length()<<endl;
         ui->name->setText(q);
     }
 else if (i==1) {

         ui->cnic->setText(q);
    }
    else if (i==2) {
         ui->edittype->setText(q);
    }
    else if (i==3) {
       ui->phone->setText(q);
    }
    else if (i==4) {
        ui->salary->setText(q);
 }
    else if (i==5) {
        ui->password->setText(q);
 }
    else if (i==6) {
        ui->rate->setText(q);
 }
    else if (i==7) {
        ui->worked->setText(q);
 }

 }
}
  else {
      QMessageBox msg;
         msg.setText("Please Select Employee from the list.");
      msg.exec();
  }
}

void employee::on_getsal_clicked()
{
    float Hourlyrate=(ui->rate->text()).toFloat();
    float Hourworked=(ui->worked->text()).toFloat();
     float Salary=(ui->salary->text()).toFloat();
     float sal=Salary + (Hourworked*Hourlyrate);
     QString b = QString::number(sal);
QString text = "Total Salary is " + b;
     QMessageBox msg;
        msg.setText(text);
     msg.exec();
}

void employee::on_emplist_activated(const QModelIndex &index)
{

}

void employee::on_emplist_clicked(const QModelIndex &index)
{
    act=true;
}
