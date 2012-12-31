/*
 @file Date.h
 @author Charles Jackson
 @created Jul 25, 2012
 @description 
 */

#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Date {
public:
	Date();

	Date(int month, int day, int year);

	int day() const {return day_;};
	int month() const {return month_;};
	int year() const {return year_;};

	//Uses Zeller's Congruence to translate a date into a weekday.
	string weekday() const;

	void operator++(int); //postfix++ operator.

	bool operator==(Date d) const;

	bool operator!=(Date d) const {return !(operator==(d));};

	friend ostream& operator<< (ostream& os, Date d);

private:
	bool leapyear();
	bool isValid();

	unsigned int year_;
	unsigned int month_;
	unsigned int day_;

	enum weekday {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
	static string toWeekday[7];
	static int monthDays[12];
};

#endif /* DATE_H_ */
