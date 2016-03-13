#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;
class Reservation
{
private:
	string date;
	string time;
	bool utilized;
public:
	Reservation();
};

#endif // RESERVATION_H
