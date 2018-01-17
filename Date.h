//Header file for date class

#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
	private:
		int month;
		int day;
		int year;
	public:
		Date();
		Date(int month, int day, int year);
		int getMonth() const;
		int getDay() const;
		int getYear() const;
		void setMonth(int newMonth);
		void setDay(int newDay);
		void setYear(int newYear);
		void printDate(std::ostream &out) const;
};


#endif /* DATE_H */