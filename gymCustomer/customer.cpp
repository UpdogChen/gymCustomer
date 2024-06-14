#include "customer.h"

customer::customer(string Name, int Age) :name(Name), age(Age) {};
customer::customer() :name("-"), age(30) {};

student::student(string Name, int Age) :customer(Name, Age) {
	if (age > 25) {
		cout << "You are not a student. Please buy adult ticket.";
		exit(1);
	}
};
student::student() :customer() {
	cout << "Please enter your name: ";
	getline(cin,name);
	cout << "\nPlease enter your age: ";
	cin >> age;
	if (age > 25) {
		cout << "You are not a student. Please buy adult ticket.";
		exit(1);
	}

};
void student::print() const{
	cout << "Hello " << name << ", how many months do you want to buy for your gym month-pass ticket?\n";
	student s(name, age);
	cin >> s.time;
	cout << "Ok, this is your receipt.\n"
		<< "Name: " << name << endl
		<< "Ticket type: student ticket\n"
		<< "Time: " << s.time << " months\n"
		<< "total price is $" << s.showPrice() << endl;

}

double student::showPrice() {
	price = basicPrice * time* studentDiscount;
	return price;
}

senior::senior(string Name, int Age) :customer(Name, Age) {
	if (age < 65) {
		cout << "You are not a senior. Please buy adult ticket.";
		exit(1);
	}
};
senior::senior() :customer() {
	cout << "Please enter your name: ";
	getline(cin,name);
	cout << "\nPiease enter your age: ";
	cin >> age;
	if (age < 65) {
		cout << "You are not a senior. Please buy adult ticket.";
		exit(1);
	}

};
void senior::print() const {
	cout << "Hello " << name << ", how many months do you want to buy for your gym month-pass ticket?\n";
	senior s(name, age);
	cin >> s.time;
	cout << "Ok, this is your receipt.\n"
		<< "Name: " << name << endl
		<< "Ticket type: student ticket\n"
		<< "Time: " << s.time << " months\n"
		<< "total price is $" << s.showPrice() << endl;

}

double senior::showPrice() {
	price = basicPrice * time * seniorDiscount;
	return price;
}

adult::adult(string Name, int Age,char Type) :customer(Name, Age) ,type(Type){
	if ((age <= 25) || (age >= 65)) {
		cout << "You can choose to buy cheaper ticket type.";
		exit(1);
	}
};
adult::adult() :customer() {
	cout << "Please enter your name: ";
	getline(cin,name);
	cout << "\nPiease enter your age: ";
	cin >> age;
	if ((age <= 25) ||(age >=65)) {
		cout << "You can choose to buy cheaper ticket type.";
		exit(1);
	}
	cout << "What kind of ticket do you want to buy?(Y: year/ M: month)";
	cin >> type;
	if ((type != 'Y') && (type != 'M')) {
		cout << "I don't know what you mean. Goodbye.";
		exit(1);
	}
};
void adult::print() const {
	adult a(name, age, type);
	switch (type) {

	case 'M':
		cout << "Hello " << name << ", how many months do you want to buy for your gym month-pass ticket?\n";
		cin >> a.time;
		cout << "Ok, this is your receipt.\n"
			<< "Name: " << name << endl
			<< "Ticket type: student ticket\n"
			<< "Time: " << a.time << " months\n"
			<< "total price is $" << a.showMonthPrice() << endl;
		break;
	case 'Y':
		cout << "Hello " << name << ", how many years do you want to buy for your gym year-pass ticket?\n";
		cin >> a.time;
		cout << "Ok, this is your receipt.\n"
			<< "Name: " << name << endl
			<< "Ticket type: student ticket\n"
			<< "Time: " << a.time << " years\n"
			<< "total price is $" << a.showYearPrice() << endl;
		break;
	}
}

double adult::showMonthPrice() {
	price = basicPrice * time;
	return price;
}

double adult::showYearPrice() {
	price = basicPrice * time * 12 * adultYearDiscount;
	return price;
}