#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class customer {
public:
	customer(string Name, int Age);
	customer();
	void setName(string Name);
	string getName() const;
	void setAge(int Age);
	int getAge() const;
	virtual void print() const;

private:
	string name;
	int age;
	int basicPrice = 1500;
};



#endif
