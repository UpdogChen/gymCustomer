#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class customer {
public:
	customer(string Name, int Age);
	customer();

protected:
	string name;
	int age;
	int basicPrice = 1500;
};

class student:customer{

public:
	student(string Name, int Age);
	student();
	void print() const;
private:
	int time;
	double price;
	double studentDiscount = 0.8;
	double showPrice();
};

class senior :customer {
public:
	senior(string Name, int Age);
	senior();
	void print() const;

private:
	int time=0;
	double price;
	double seniorDiscount = 0.75;
	double showPrice();
};

class adult :customer {
public:
	adult(string Name, int Age, char Type);
	adult();
	void print() const;

private:
	char type = 'x';
	int time;
	double price;
	double adultYearDiscount = 0.85;
	double showMonthPrice();
	double showYearPrice();
};


#endif
