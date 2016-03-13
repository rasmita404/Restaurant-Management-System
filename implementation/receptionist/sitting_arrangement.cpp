#include "sitting_arrangement.h"
//#include "ui_seating_arrangement.ui"

SittingArrangement::SittingArrangement()
{

}

SittingArrangement::~SittingArrangement()
{

}


void SittingArrangement::setAttributes(int id,QString t)
{
    type=t;
}

void SittingArrangement::addTable(int table_no,QString res)
{
    bool flag;
    if(res=="0")
        flag=true;
    else
        flag=false;

    Table *tble=new Table(table_no,flag);
    table.push_back(tble);
}
