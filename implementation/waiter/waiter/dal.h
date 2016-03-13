#include <QtGui>
#include <QtWidgets/QMainWindow>
#include "ui_waiter.h"
#include <QtCore/QCoreApplication>
#include<QWidget>
#include<ostream>
#include<iostream>
#include<QFile>
#include<QTime>
#include <stdio.h>
#include <QTextStream>
#include<QSqlDatabase>
#include<QSqlDriver>
#include <QSqlQuery>
#include <iostream>
#include<qmessagebox.h>
class dal
{
private:
	
public:
	dal()
	{
		
	}
	QSqlQuery getdata(QString qry)
	{
		

			QSqlQuery query(qry);
		
			return query;

		
	
	}
};