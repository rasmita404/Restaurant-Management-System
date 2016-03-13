#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
using namespace std;
class Reservation
{
private:
    QString date;
    QString time;
    bool utilized;
public:
    Reservation();
    void setAttribute(QString,QString);
    QString getDate();
    QString getTime();
};

#endif // RESERVATION_H
