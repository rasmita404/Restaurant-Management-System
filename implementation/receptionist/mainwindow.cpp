#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <time.h>
#include <QtSql>
#include <QtDebug>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    recep=new FullTimeReceptionisit();
    // m.closed=false;
      setWindowTitle(tr("Receptionist"));
    ui->setupUi(this);
    ui->groupBox->setHidden(true);
    ui->groupBox_2->setHidden(true);
    ui->groupBox_3->setHidden(true);
    ui->groupBox_4->setHidden(true);
    ui->groupBox_5->setHidden(true);
    m=new Menu();
    connect(this,&MainWindow::sendCustomerId,m,&Menu::onCustomerCnicSend);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete recep;
}

void MainWindow::on_pushButton_clicked()
{
    int new_len=ui->cnic->toPlainText().length();
    int i=0;
    for (;i<new_len;i++){
        if(ui->cnic->toPlainText()[i]<QLatin1Char('0')||ui->cnic->toPlainText()[i]>QLatin1Char('9')){
            break;
        }
    }
    if(!ui->cnic->toPlainText().isEmpty()&&ui->cnic->toPlainText().length()==13&&i==new_len){

        if(recep->customerPresent(ui->cnic->toPlainText()))
        {

            ui->cnic->setEnabled(false);
            ui->pushButton->setEnabled(false);
            ui->groupBox->setHidden(true);
            ui->groupBox_2->setHidden(false);
        }
        else
        {

            ui->pushButton->setEnabled(false);
            ui->cnic->setEnabled(false);
            ui->groupBox_2->setHidden(true);
            ui->groupBox->setHidden(false);
        }
    }

    else{
        QMessageBox msgBox;
        msgBox.setText("Invalid Cnic");
        msgBox.exec();
    }

}

void MainWindow::on_radioButton_clicked()
{
    ui->pushButton->setEnabled(false);

    ui->groupBox_4->setHidden(true);
    ui->groupBox_5->setHidden(true);
    ui->groupBox_3->setHidden(false);
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->groupBox_3->setHidden(true);
    ui->groupBox_5->setHidden(true);
    ui->groupBox_4->setHidden(false);
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->groupBox_3->setHidden(true);
    ui->groupBox_4->setHidden(true);
    ui->groupBox_5->setHidden(false);
}

void MainWindow::on_radioButton_4_clicked()
{
    delete m;
    m=new Menu();
     connect(this,&MainWindow::sendCustomerId,m,&Menu::onCustomerCnicSend);
    emit sendCustomerId(ui->cnic->toPlainText());
    m->show();
    //this->close();
    //if(m.closed){
    //this->show();
   // }
}

void MainWindow::on_radioButton_5_clicked()
{

    delete m;
    m=new Menu();
    connect(this,&MainWindow::sendCustomerId,m,&Menu::onCustomerCnicSend);
    emit sendCustomerId(ui->cnic->toPlainText());
    m->show();
    //this->close();
    //if(m.closed){
    //this->show();
    //}

}

void MainWindow::on_pushButton_2_clicked()
{
    cust.setAttributes(ui->cnic->toPlainText(),ui->name->toPlainText(),ui->phone_no->toPlainText(),ui->address->toPlainText());
    recep->addCustomer(cust);
    ui->pushButton->setEnabled(false);
    ui->cnic->setEnabled(false);
    ui->groupBox->setHidden(true);
    ui->groupBox_2->setHidden(false);

}

void MainWindow::on_pushButton_3_clicked()
{

    bool invalid_date=0;
    bool invalid_time=0;
    int date_length=ui->Date->toPlainText().length();
    int time_length=ui->Time->toPlainText().length();
    //checking date format which is dd-mm-yyyy
    if(date_length==10){
        int i=0;
                if(ui->Date->toPlainText()[i]<QLatin1Char('0')||ui->Date->toPlainText()[i]>QLatin1Char('9')){
                    invalid_date=true;
                }
                else if(ui->Date->toPlainText()[i+1]<QLatin1Char('0')||ui->Date->toPlainText()[i+1]>QLatin1Char('9')){
                    invalid_date=true;
                }
                else if(ui->Date->toPlainText()[i+2]!=QLatin1Char('-')){
                    invalid_date=true;
                }
                else if(ui->Date->toPlainText()[i+3]<QLatin1Char('0')||ui->Date->toPlainText()[i+3]>QLatin1Char('9')){
                    invalid_date=true;
                }
                else if(ui->Date->toPlainText()[i+4]<QLatin1Char('0')||ui->Date->toPlainText()[i+4]>QLatin1Char('9')){
                    invalid_date=true;
                }
                else if(ui->Date->toPlainText()[i+5]!=QLatin1Char('-')){
                    invalid_date=true;
                }
                else if(ui->Date->toPlainText()[i+6]<QLatin1Char('0')||ui->Date->toPlainText()[i+6]>QLatin1Char('9')){
                    invalid_date=true;
                }else if(ui->Date->toPlainText()[i+7]<QLatin1Char('0')||ui->Date->toPlainText()[i+7]>QLatin1Char('9')){
                    invalid_date=true;
                }else if(ui->Date->toPlainText()[i+8]<QLatin1Char('0')||ui->Date->toPlainText()[i+8]>QLatin1Char('9')){
                    invalid_date=true;
                }else if(ui->Date->toPlainText()[i+9]<QLatin1Char('0')||ui->Date->toPlainText()[i+9]>QLatin1Char('9')){
                    invalid_date=true;
                }
                if(invalid_date){
                    QMessageBox msg;
                    msg.setText("Invalid Date!! \n Date Format is dd-mm-yyyy");
                    msg.exec();

                }
                if(time_length==8){
                    i=0;
                    if(ui->Time->toPlainText()[i]<QLatin1Char('0')||ui->Time->toPlainText()[i]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    else if(ui->Time->toPlainText()[i+1]<QLatin1Char('0')||ui->Time->toPlainText()[i+1]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    else if(ui->Time->toPlainText()[i+2]!=QLatin1Char(':')){
                        invalid_time=true;
                    }
                    else if(ui->Time->toPlainText()[i+3]<QLatin1Char('0')||ui->Time->toPlainText()[i+3]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    else if(ui->Time->toPlainText()[i+4]<QLatin1Char('0')||ui->Time->toPlainText()[i+4]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    else if(ui->Time->toPlainText()[i+5]!=QLatin1Char(':')){
                        invalid_time=true;
                    }
                    else if(ui->Time->toPlainText()[i+6]<QLatin1Char('0')||ui->Time->toPlainText()[i+6]>QLatin1Char('9')){
                        invalid_time=true;
                    }else if(ui->Time->toPlainText()[i+7]<QLatin1Char('0')||ui->Time->toPlainText()[i+7]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    if(invalid_time){
                        QMessageBox msg;
                        msg.setText("Invalid Time!! \n Time Format is hh:mm:ss all in integers\n in 24 hours format");
                        msg.exec();

                    }
                    if(!invalid_date&&!invalid_time){

                        Reservation res;
                        res.setAttribute(ui->Date->toPlainText(),ui->Time->toPlainText());
                        if(recep->allocateHall(ui->cnic->toPlainText(),res)){
                        QMessageBox msg;
                        msg.setText("Hall Reserved!!");
                        msg.exec();
                        }
                        else{
                            QMessageBox msg;
                            msg.setText("Hall not available or unable to add!!");
                            msg.exec();

                        }

                    }

                }
                else{
                    QMessageBox msg;
                    msg.setText("Invalid Time!! \n Time Format is hh-mm-ss all in integers\n in 24 hours format");
                    msg.exec();

                }


     }
    else{
        QMessageBox msg;
        msg.setText("Invalid Date!! \n Date Format is dd-mm-yyyy all in integers");
        msg.exec();
    }


}

void MainWindow::on_pushButton_4_clicked()
{
    bool invalid_date=0;
    bool invalid_time=0;
    int date_length=ui->date_1->toPlainText().length();
    int time_length=ui->time_1->toPlainText().length();
    //checking date format which is dd-mm-yyyy
    if(date_length==10){
        int i=0;
                if(ui->date_1->toPlainText()[i]<QLatin1Char('0')||ui->date_1->toPlainText()[i]>QLatin1Char('9')){
                    invalid_date=true;
                }
                else if(ui->date_1->toPlainText()[i+1]<QLatin1Char('0')||ui->date_1->toPlainText()[i+1]>QLatin1Char('9')){
                    invalid_date=true;
                }
                else if(ui->date_1->toPlainText()[i+2]!=QLatin1Char('-')){
                    invalid_date=true;
                }
                else if(ui->date_1->toPlainText()[i+3]<QLatin1Char('0')||ui->date_1->toPlainText()[i+3]>QLatin1Char('9')){
                    invalid_date=true;
                }
                else if(ui->date_1->toPlainText()[i+4]<QLatin1Char('0')||ui->date_1->toPlainText()[i+4]>QLatin1Char('9')){
                    invalid_date=true;
                }
                else if(ui->date_1->toPlainText()[i+5]!=QLatin1Char('-')){
                    invalid_date=true;
                }
                else if(ui->date_1->toPlainText()[i+6]<QLatin1Char('0')||ui->date_1->toPlainText()[i+6]>QLatin1Char('9')){
                    invalid_date=true;
                }else if(ui->date_1->toPlainText()[i+7]<QLatin1Char('0')||ui->date_1->toPlainText()[i+7]>QLatin1Char('9')){
                    invalid_date=true;
                }else if(ui->date_1->toPlainText()[i+8]<QLatin1Char('0')||ui->date_1->toPlainText()[i+8]>QLatin1Char('9')){
                    invalid_date=true;
                }else if(ui->date_1->toPlainText()[i+9]<QLatin1Char('0')||ui->date_1->toPlainText()[i+9]>QLatin1Char('9')){
                    invalid_date=true;
                }
                if(invalid_date){
                    QMessageBox msg;
                    msg.setText("Invalid Date!! \n Date Format is dd-mm-yyyy");
                    msg.exec();

                }
                if(time_length==8){
                    i=0;
                    if(ui->time_1->toPlainText()[i]<QLatin1Char('0')||ui->time_1->toPlainText()[i]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    else if(ui->time_1->toPlainText()[i+1]<QLatin1Char('0')||ui->time_1->toPlainText()[i+1]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    else if(ui->time_1->toPlainText()[i+2]!=QLatin1Char(':')){
                        invalid_time=true;
                    }
                    else if(ui->time_1->toPlainText()[i+3]<QLatin1Char('0')||ui->time_1->toPlainText()[i+3]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    else if(ui->time_1->toPlainText()[i+4]<QLatin1Char('0')||ui->time_1->toPlainText()[i+4]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    else if(ui->time_1->toPlainText()[i+5]!=QLatin1Char(':')){
                        invalid_time=true;
                    }
                    else if(ui->time_1->toPlainText()[i+6]<QLatin1Char('0')||ui->time_1->toPlainText()[i+6]>QLatin1Char('9')){
                        invalid_time=true;
                    }else if(ui->time_1->toPlainText()[i+7]<QLatin1Char('0')||ui->time_1->toPlainText()[i+7]>QLatin1Char('9')){
                        invalid_time=true;
                    }
                    if(invalid_time){
                        QMessageBox msg;
                        msg.setText("Invalid Time!! \n Time Format is hh:mm:ss all in integers\n in 24 hours format");
                        msg.exec();
                    }
                    bool invalid_noc=0;
                    for(int i=0;i<ui->n_o_c->toPlainText().length();i++){
                        if(ui->n_o_c->toPlainText()[i]<QLatin1Char('0')||ui->n_o_c->toPlainText()[i]>QLatin1Char('9')){
                            QMessageBox msg;
                            msg.setText("Number of Customers should be in numeric");
                            msg.exec();

                            invalid_noc=true;
                            break;
                        }

                    }
                    if(!invalid_date&&!invalid_time&&!invalid_noc){
                          int noc=ui->n_o_c->toPlainText().toInt();

                        Reservation res;
                        res.setAttribute(ui->date_1->toPlainText(),ui->time_1->toPlainText());
                        if(recep->allocateTable(res,noc,ui->cnic->toPlainText())){
                            QMessageBox msg;
                            msg.setText("Table Allocated");
                            msg.exec();

                        }
                        else{
                            QMessageBox msg;
                            msg.setText("Table Not Available or failed to allocate");
                            msg.exec();

                        }
                        //recep->allocateTable(ui->cnic->toPlainText(),res);
                        //QMessageBox msg;
                        //msg.setText("Table Reserved!!");
                        //msg.exec();
                    }

                }
                else{
                    QMessageBox msg;
                    msg.setText("Invalid Time!! \n Time Format is hh-mm-ss all in integers\n in 24 hours format");
                    msg.exec();

                }


     }
    else{
        QMessageBox msg;
        msg.setText("Invalid Date!! \n Date Format is dd-mm-yyyy all in integers");
        msg.exec();
    }


}

void MainWindow::on_pushButton_5_clicked()
{

    bool invalid_noc=0;
    for(int i=0;i<ui->noc_1->toPlainText().length();i++){
        if(ui->noc_1->toPlainText()[i]<QLatin1Char('0')||ui->n_o_c->toPlainText()[i]>QLatin1Char('9')){
            QMessageBox msg;
            msg.setText("Number of Customers should be in numeric");
            msg.exec();

            invalid_noc=true;
            break;
        }
    }
    if(!invalid_noc){
        srand (time(NULL));
        //int index=rand()%recep->getWaiter().size();
        int noc=ui->noc_1->toPlainText().toInt();
        //QString::fromStdString(recep->getWaiter()[index]->getCnic())
        if(recep->DineIn(noc,ui->cnic->toPlainText(),"1234567890123")){
            QMessageBox msg;
            msg.setText("Table and Waiter Alloted");
            msg.exec();

        }
        else{
            QMessageBox msg;
            msg.setText("Table not available");
            msg.exec();
        }
    }
}

void MainWindow::on_refresh_clicked()
{
    ui->Date->setText("");
    ui->date_1->setText("");
    ui->name->setText("");
    ui->noc_1->setText("");
    ui->n_o_c->setText("");
    ui->phone_no->setText("");
    ui->time_1->setText("");
    ui->Time->setText("");
    ui->address->setText("");
    ui->cnic->setText("");
    recep=new FullTimeReceptionisit();
    // m.closed=false;
    setWindowTitle(tr("Receptionist"));
    //ui->setupUi(this);
    ui->groupBox->setHidden(true);
    ui->groupBox_2->setHidden(true);
    ui->groupBox_3->setHidden(true);
    ui->groupBox_4->setHidden(true);
    ui->groupBox_5->setHidden(true);
    ui->cnic->setText("");
    if(!ui->cnic->isEnabled()){
        ui->cnic->setEnabled(true);

    }
    if(!ui->pushButton->isEnabled()){
        ui->pushButton->setEnabled(true);
    }
    m=new Menu();
    connect(this,&MainWindow::sendCustomerId,m,&Menu::onCustomerCnicSend);
}
