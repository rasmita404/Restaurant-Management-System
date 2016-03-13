#ifndef SITTINGARRANGEMENT
#define SITTINGARRANGEMENT
#include<iostream>
#include<vector>
#include<string>
#include <QMainWindow>
#include "table.h"
using namespace std;
namespace Ui {
class SittingArrangement;
}

class SittingArrangement : public QMainWindow
{
    Q_OBJECT

public:
    //virtual void foo()=0;//added to make class pure virtual
    SittingArrangement();
    ~SittingArrangement();
    void setAttributes(int,QString);
    void addTable(int,QString);

private:
    vector<Table*> table;
    QString type;
};

class OpenAir:public SittingArrangement
{

};
//hall is abstract
class Hall:public SittingArrangement
{
private:
    int id;
    QString type;
    bool isReserve;
public:

};
class Formal:public Hall
{

};
//informal is abstract
class Informal:public Hall
{

};

class Meeting:public Informal
{

};
class Ceremony:public Informal
{

};

#endif // SITTINGARRANGEMENT

