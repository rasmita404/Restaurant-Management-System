/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *cnic;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_5;
    QTextEdit *address;
    QLabel *label_3;
    QTextEdit *name;
    QTextEdit *phone_no;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QGroupBox *groupBox_3;
    QTextEdit *Time;
    QLabel *label_2;
    QTextEdit *Date;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_4;
    QTextEdit *textEdit_7;
    QLabel *label_7;
    QTextEdit *textEdit_8;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QTextEdit *textEdit_9;
    QLabel *label_9;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_5;
    QTextEdit *textEdit_12;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(539, 455);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cnic = new QTextEdit(centralWidget);
        cnic->setObjectName(QStringLiteral("cnic"));
        cnic->setEnabled(true);
        cnic->setGeometry(QRect(170, 40, 201, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 40, 81, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(130, 80, 311, 201));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 130, 81, 31));
        label_5->setMaximumSize(QSize(81, 31));
        label_5->setFont(font);
        address = new QTextEdit(groupBox);
        address->setObjectName(QStringLiteral("address"));
        address->setEnabled(true);
        address->setGeometry(QRect(90, 130, 201, 31));
        address->setMaximumSize(QSize(201, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 80, 81, 31));
        label_3->setMaximumSize(QSize(81, 31));
        label_3->setFont(font);
        name = new QTextEdit(groupBox);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(90, 30, 201, 31));
        name->setMaximumSize(QSize(201, 31));
        phone_no = new QTextEdit(groupBox);
        phone_no->setObjectName(QStringLiteral("phone_no"));
        phone_no->setGeometry(QRect(90, 80, 201, 31));
        phone_no->setMaximumSize(QSize(201, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 30, 81, 31));
        label_4->setMaximumSize(QSize(81, 31));
        label_4->setFont(font);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 170, 75, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 40, 91, 31));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 511, 41));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 10, 121, 17));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 10, 131, 17));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(280, 10, 82, 17));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(350, 10, 82, 17));
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(440, 10, 82, 17));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(60, 190, 431, 151));
        Time = new QTextEdit(groupBox_3);
        Time->setObjectName(QStringLiteral("Time"));
        Time->setGeometry(QRect(170, 70, 201, 31));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 70, 81, 31));
        label_2->setFont(font);
        Date = new QTextEdit(groupBox_3);
        Date->setObjectName(QStringLiteral("Date"));
        Date->setGeometry(QRect(170, 20, 201, 31));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 20, 81, 31));
        label_6->setFont(font);
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 120, 75, 23));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(50, 190, 451, 191));
        textEdit_7 = new QTextEdit(groupBox_4);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setGeometry(QRect(170, 70, 201, 31));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 70, 81, 31));
        label_7->setFont(font);
        textEdit_8 = new QTextEdit(groupBox_4);
        textEdit_8->setObjectName(QStringLiteral("textEdit_8"));
        textEdit_8->setGeometry(QRect(170, 20, 201, 31));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 20, 81, 31));
        label_8->setFont(font);
        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(334, 160, 81, 23));
        textEdit_9 = new QTextEdit(groupBox_4);
        textEdit_9->setObjectName(QStringLiteral("textEdit_9"));
        textEdit_9->setGeometry(QRect(170, 120, 201, 31));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 120, 151, 31));
        QFont font1;
        font1.setPointSize(11);
        label_9->setFont(font1);
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(50, 190, 461, 111));
        pushButton_5 = new QPushButton(groupBox_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(284, 80, 131, 23));
        textEdit_12 = new QTextEdit(groupBox_5);
        textEdit_12->setObjectName(QStringLiteral("textEdit_12"));
        textEdit_12->setGeometry(QRect(170, 30, 201, 31));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 30, 151, 31));
        label_12->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 539, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Receptionist", 0));
        cnic->setPlaceholderText(QApplication::translate("MainWindow", "Enter CNIC", 0));
        label->setText(QApplication::translate("MainWindow", "CNIC", 0));
        groupBox->setTitle(QString());
        label_5->setText(QApplication::translate("MainWindow", "Address", 0));
        address->setPlaceholderText(QApplication::translate("MainWindow", "Enter Address", 0));
        label_3->setText(QApplication::translate("MainWindow", "Phone", 0));
        name->setPlaceholderText(QApplication::translate("MainWindow", "Enter Name", 0));
        phone_no->setPlaceholderText(QApplication::translate("MainWindow", "Enter Phone No", 0));
        label_4->setText(QApplication::translate("MainWindow", "Name", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Enter", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Enter", 0));
        groupBox_2->setTitle(QString());
        radioButton->setText(QApplication::translate("MainWindow", "Reservation For Hall", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "Reservation For Table", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "Dine In", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "Take Away", 0));
        radioButton_5->setText(QApplication::translate("MainWindow", "Delivery", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Reserve Hall", 0));
        label_2->setText(QApplication::translate("MainWindow", "Time", 0));
        label_6->setText(QApplication::translate("MainWindow", "Date", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Reserve Hall", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Reserve Table", 0));
        label_7->setText(QApplication::translate("MainWindow", "Time", 0));
        label_8->setText(QApplication::translate("MainWindow", "Date", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Reserve Table", 0));
        label_9->setText(QApplication::translate("MainWindow", "Number of Customers", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Dine In", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Allocate Table and Waiter", 0));
        label_12->setText(QApplication::translate("MainWindow", "Number of Customers", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
