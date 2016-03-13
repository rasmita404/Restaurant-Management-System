#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menu.h"
#include "employee.h"
//#include "customer.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_refresh_clicked();

signals:
    void sendCustomerId(const QString &text);
private:
    Ui::MainWindow *ui;
    Menu *m;
    Receptionist *recep;
    Customer cust;
};

#endif // MAINWINDOW_H
