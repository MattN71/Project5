/*
*  This Class will manage a date object
*
*  Programmer: Matt Nicklas
*  Date: April 24, 2017
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include <iostream>
#include "Date.h"

//Default constructor, sets date to 1/1/2017
Date::Date() {
	this->month = 1;
	this->day = 1;
	this->year = 2017;
}

//Parameterized constructor, checks if given parameters are valid, and updates them. or else, they are set to the same
//default values from the default constructor
Date::Date(int month, int day, int year) {
	if (month <= 12 && month >=1) {
		this->month = month;
	} else {
		this->month = 1;
	}

	if (day >= 1 && day <= 31) {
		this->day = day;
	} else {
		this->day = 1;
	}

	if (year > 0) {
		this->year = year;
	} else {
		this->year = 2017;
	}
}

//Returns month
int Date::getMonth() const {
	return this->month;
}

//Returns Day		
int Date::getDay() const {
	return this->day;
}

//Returns year
int Date::getYear() const {
	return this->year;
}

//Checks validity of month, and updates it if it is valid
void Date::setMonth(int newMonth) {
	if (newMonth >= 1 && newMonth <= 12) {
		this->month = newMonth;
	}
}

//Checks validity of day, and updates it if it is valid		
void Date::setDay(int newDay) {
	if (newDay >= 1 && newDay <= 31) {
		this->day = newDay;
	}
}
//Checks validity of year, and updates it if it is valid
void Date::setYear(int newYear) {
	if (newYear >= 1) {
		this->year = newYear;
	}
}

//Prints out date with formatting. Adds leading 0s to day and month if less than 10
void Date::printDate(std::ostream &out) const {
	if (this->month < 10) {
		out << "0" << this->month;
	} else {
		out << this->month;
	}
	
	out << "/";
	
	if (this->day < 10) {
		out << "0" << this->day;
	} else {
		out << this->day;
	}
	
	out << "/";
	out << this->year << std::endl;
}