#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "customer.h"
#include "deal.h"
#include "sitting_arrangement.h"

#include<string>
#include <vector>
using namespace std;
enum EmployeeType { Manager, AssistantManager, FullTimeReceptionisit, PartTimeReceptionist, FullTimeWaiter, PartTimeWaiter, FullTimeSecurity, PartTimeSecurity };


class Employee
{
private:
	string name;
	string CNIC;
	string phone_no;
	EmployeeType type;

public:
	virtual double getSalary() = 0;
	virtual EmployeeType getType() = 0;
};

class FullTimeOnly :public Employee
{
private:
	double fixedPay;
public:
	virtual double getSalary();
	virtual EmployeeType getType();

};
class ManagingStaff :public FullTimeOnly
{
private:
	double managingPay;
public:
	double getSalary();
	EmployeeType getType();
};
class Chef :public FullTimeOnly
{
private:
	int warningCount;
public:
	double getSalary();
	EmployeeType getType();
	void cookFood();

};
class Manager :public ManagingStaff
{
private:
	double extraPay;
	vector<FoodItem*> food_item;
	vector<Deal*> deal;
public:

	double getSalary();
	EmployeeType getType();
	void manageEmployee(string empCNIC);
	void manageItem(string itemName);
	void manageDeal(string dealName);


};
class AssistantManager :public ManagingStaff
{
private:
	SittingArrangement* sitting_arrangement;
	vector<Ceremony*> ceremony;
public:
	double getSalary();
	EmployeeType getType();
	float checkRating();
	void requestManager(string employee);

};
class Receptionist :public Employee{
public:
	virtual double getSalary() = 0;
	virtual EmployeeType getType() = 0;
	void receiveCall(string purpose);
	void allocateTable();
	void allocateWaiter(int table_no);
	void addCustomer(Customer obj);
	void sendDelivery(string address);

};
class FullTimeReceptionisit :public Receptionist
{
private:
	double fixedPay;
public:
	double getSalary();
	EmployeeType getType();


};
class PartTimeReceptionisit :public Receptionist
{
private:
	int ratePerHour;
	int hours;
public:
	double getSalary();
	EmployeeType getType();


};
class Security :public Employee
{
public:
	double getSalary() = 0;
	EmployeeType getType() = 0;


};
class FullTimeSecurity :public Security
{
private:
	double fixedPay;
public:
	double getSalary();
	EmployeeType getType();


};
class PartTimeSecurity :public Security
{
private:
	int ratePerHour;
	int hours;
public:
	double getSalary();
	EmployeeType getType();


};
class Waiter :public Employee
{
private:
	int warningCount;
	vector<Order*> order;
public:
	double getSalary() = 0;
	EmployeeType getType() = 0;
	void provideFood(int table_no);
	bool receiveBill(int amount);

};
class FullTimeWaiter :public Waiter
{
private:
	double fixedPay;
public:
	double getSalary();
	EmployeeType getType();


};
class PartTimeWaiter :public Waiter
{
private:
	int ratePerHour;
	int hours;
public:
	double getSalary();
	EmployeeType getType();
};

#endif // EMPLOYEE_H
