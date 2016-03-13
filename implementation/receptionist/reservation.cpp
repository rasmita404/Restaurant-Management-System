#include "reservation.h"

Reservation::Reservation()
{

}

void Reservation::setAttribute(QString d,QString t)
{
    utilized=true;
    date=d;
    time=t;
}

QString Reservation::getDate()
{
    return date;
}

QString Reservation::getTime()
{
    return time;
}
