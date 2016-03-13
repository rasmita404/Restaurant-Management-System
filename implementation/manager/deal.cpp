#include "deal.h"
#include "ui_deal.h"
#include"datalayer.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "employee_1.h"
Deal::Deal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deal)
{
act=false;
    ui->setupUi(this);

}

Deal::~Deal()
{
    delete ui;
}
void Deal::foradd(Menu men) {
    ui->remove->setHidden(true);
    ui->save->setHidden(false);
    ui->deallist->setHidden(true);
    ui->dlist->setHidden(true);
    ui->select->setHidden(true);
    ui->flist->setHidden(true);
    ui->foodlist->setHidden(true);
    ui->hl->setHidden(false);
    ui->items->setHidden(false);
ui->itemlist->setHidden(false);
    int rcount=men.items.size();
    cout<<endl<<rcount<<endl;

     ui->itemlist->setRowCount(rcount);

     for (int i=0; i<rcount;i++) {


     ui->itemlist->setItem(i, 0,  new QTableWidgetItem(men.items[i].getname()));
 //QString str=men.items[i].getprice().toString();

     ui->itemlist->setItem(i, 1, new QTableWidgetItem(QString::number(men.items[i].getprice())));
     ui->itemlist->setItem(i, 2, new QTableWidgetItem(men.items[i].getdetail()));
     ui->itemlist->setItem(i, 3, new QTableWidgetItem(men.items[i].getunits()));
 ui->itemlist->setItem(i, 4, new QTableWidgetItem(men.items[i].gettype()));
 }
 ui->itemlist->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void Deal::retrvdeallist()
{
    DataLayer d;
 QSqlQuery q=   d.retrvdeal();
int cnt= q.numRowsAffected();
 int i=0;
    ui->dlist->setRowCount(cnt);

 while(q.next())
 {
     QString name=q.value(0).toString();
     QString price=q.value(1).toString();
     QString detail=q.value(2).toString();
     ui->dlist->setItem(i,0,new QTableWidgetItem(name));
     ui->dlist->setItem(i,1,new QTableWidgetItem(price));
     ui->dlist->setItem(i,2,new QTableWidgetItem(detail));
     ++i;
 }
 ui->dlist->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Deal::foredit() {
    ui->remove->setHidden(true);
    ui->save->setHidden(false);

    ui->deallist->setHidden(false);
    ui->dlist->setHidden(false);
}
void Deal::forremove() {
    ui->remove->setHidden(false);
    ui->save->setHidden(true);

    ui->deallist->setHidden(false);
    ui->dlist->setHidden(false);
ui->itemlist->setHidden(true);
    ui->select->setHidden(false);

    ui->flist->setHidden(false);
    ui->foodlist->setHidden(false);
    ui->hl->setHidden(true);

    ui->items->setHidden(true);
}


void Deal::on_save_clicked()
{
    QString Name=(ui->name->text());
    double Price=(ui->price->text()).toDouble();
    QString Detail=(ui->detail->text());

    m.adddeal(Name, Price , Detail);

    ui->name->setText("");
    ui->price->setText("");
    ui->detail->setText("");
    ui->iname->setText("");
    ui->quantity->setText("");
}






void Deal::on_select_clicked()
{
    if (act==true) {
        int row=ui->dlist->currentIndex().row();
        rs=row;
        QTableWidgetItem * item1= ui->dlist->item(row, 1);
      QString qq=item1->text();
      ui->price->setText(qq);
      QTableWidgetItem * item2= ui->dlist->item(row, 2);
    QString qqq=item2->text();
    ui->detail->setText(qqq);



        QTableWidgetItem * item= ui->dlist->item(row, 0);
      QString q1=item->text();
      ui->name->setText(q1);
      DataLayer d;
      int i=0;
   QSqlQuery q=   d.retrvfooditemfordeal(q1);
   ui->flist->setRowCount(q.numRowsAffected());
   while(q.next())
   {

       QString name=q.value(1).toString();
       QString quant=q.value(2).toString();
       ui->flist->setItem(i,0,new QTableWidgetItem(name));
       ui->flist->setItem(i,1,new QTableWidgetItem(quant));

       ++i;
   }


}
    else {
        QMessageBox msg;
           msg.setText("Please Select Deal from the list.");
        msg.exec();
    }
}
void Deal::on_remove_clicked()
{
    QString Name=ui->name->text();

    m.RemoveDeal(Name);
        QMessageBox msg;
           msg.setText("Deal removed Successfully.");
        msg.exec();
        ui->name->setText("");
        ui->price->setText("");
        ui->detail->setText("");
ui->flist->setRowCount(0);
ui->dlist->removeRow(rs);
}

void Deal::on_add_clicked()
{
    QString Name=(ui->name->text());
    QString FName=ui->iname->text();
    int Quantity=(ui->quantity->text()).toInt();
    ui->iname->setText("");
        ui->quantity->setText("");
    m.adddealfood(Name, FName , Quantity);
}

void Deal::on_itemlist_clicked(const QModelIndex &index)
{

}

void Deal::on_dlist_clicked(const QModelIndex &index)
{
     act=true;
}
