#include "fooditem.h"
#include "ui_fooditem.h"
#include <QMessageBox>
#include <vector>
#include <QString>
#include <string>
using namespace std;

fooditem::fooditem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fooditem)
{
    act=false;
    ui->setupUi(this);
     ui->price->setValidator(new QDoubleValidator());
}
void fooditem::add() {
    ui->remove->setHidden(true);
    ui->save->setHidden(false);
    ui->lunit->setHidden(true);
    ui->ltype->setHidden(true);
    ui->ctype->setHidden(false);
    ui->cunit->setHidden(false);
    ui->flist->setHidden(true);
    ui->foodlist->setHidden(true);
     ui->selecti->setHidden(true);
}
void fooditem::edit(Menu men) {
    ui->remove->setHidden(true);
    ui->save->setHidden(false);
    ui->lunit->setHidden(true);
    ui->ltype->setHidden(true);
    ui->ctype->setHidden(false);
    ui->cunit->setHidden(false);
    ui->flist->setHidden(false);
    ui->foodlist->setHidden(false);
    ui->selecti->setHidden(false);

    int rcount=men.items.size();
    cout<<endl<<rcount<<endl;

     ui->flist->setRowCount(rcount);

     for (int i=0; i<rcount;i++) {


     ui->flist->setItem(i, 0,  new QTableWidgetItem(men.items[i].getname()));
 //QString str=men.items[i].getprice().toString();

     ui->flist->setItem(i, 1, new QTableWidgetItem(QString::number(men.items[i].getprice())));
     ui->flist->setItem(i, 2, new QTableWidgetItem(men.items[i].getdetail()));
     ui->flist->setItem(i, 3, new QTableWidgetItem(men.items[i].getunits()));
 ui->flist->setItem(i, 4, new QTableWidgetItem(men.items[i].gettype()));
 }
 ui->flist->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
void fooditem::forremove(Menu men) {
    ui->remove->setHidden(false);
    ui->save->setHidden(true);
    ui->lunit->setHidden(false);
    ui->ltype->setHidden(false);
    ui->ctype->setHidden(true);
    ui->cunit->setHidden(true);
    ui->flist->setHidden(false);
    ui->foodlist->setHidden(false);

    ui->selecti->setHidden(false);
   int rcount=men.items.size();
   cout<<endl<<rcount<<endl;

    ui->flist->setRowCount(rcount);

    for (int i=0; i<rcount;i++) {


    ui->flist->setItem(i, 0,  new QTableWidgetItem(men.items[i].getname()));
//QString str=men.items[i].getprice().toString();

    ui->flist->setItem(i, 1, new QTableWidgetItem(QString::number(men.items[i].getprice())));
    ui->flist->setItem(i, 2, new QTableWidgetItem(men.items[i].getdetail()));
    ui->flist->setItem(i, 3, new QTableWidgetItem(men.items[i].getunits()));
ui->flist->setItem(i, 4, new QTableWidgetItem(men.items[i].gettype()));
}
ui->flist->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

fooditem::~fooditem()
{
    delete ui;
}

void fooditem::on_save_clicked()
{
    QString Name=(ui->name->text());
    double Price=(ui->price->text()).toDouble();
    QString Detail=(ui->detail->text());
    QString Unit=(ui->cunit->currentText());
    QString Type=(ui->ctype->currentText());


    if (Name.trimmed().isEmpty()) {
        QMessageBox msg;
           msg.setText("Name cannot be null.");
        msg.exec();
    }

    else {
  m.AddFood(Name,Price,Detail,Unit,Type);
  QMessageBox msg;
     msg.setText("Food Item saved Successfully.");
  msg.exec();
}

    ui->name->setText("");
        ui->price->setText("");
        ui->detail->setText("");
}

void fooditem::on_remove_clicked()
{QString Name=ui->name->text();
    m.RemoveFood(Name);
    ui->name->setText("");
        ui->price->setText("");
        ui->detail->setText("");
    QMessageBox msg;
       msg.setText("Food Item removed Successfully.");
    msg.exec();
ui->flist->removeRow(rs);
}

void fooditem::on_flist_activated(const QModelIndex &index)
{
    cout<<"hello"<<endl;
    int rows=ui->flist->currentIndex().row();
   cout<<rows<<endl;

}

string removeSpaces(string x)
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

void fooditem::on_selecti_clicked()
{
    if (act==true) {
            int row=ui->flist->currentIndex().row();
    rs=row;
    for (int i=0; i<5; i++) {
        QTableWidgetItem * item= ui->flist->item(row, i);
        string qq=removeSpaces(item->text().toStdString());
        QString q=QString ::fromStdString(qq);
   if (i==0) {

       cout<<q.length()<<endl;
        ui->name->setText(q);
    }
else if (i==1) {

        ui->price->setText(q);
   }
   else if (i==2) {
        ui->detail->setText(q);
   }
   else if (i==3) {
      ui->lunit->setText(q);
   }
   else if (i==4) {
       ui->ltype->setText(q);
}
}
}
    else {
        QMessageBox msg;
           msg.setText("Please Select Food item from the list.");
        msg.exec();
    }
}

void fooditem::on_flist_clicked(const QModelIndex &index)
{
    act=true;
}
