/*
 @file Date.cpp
 @author Charles Jackson
 @created Jul 25, 2012
 @description 
 */

#include "Date.h"
#include <cassert>

string Date::toWeekday[] = {"Monday", "Tuesday", "Wednesday", "Thursday",
						"Friday", "Saturday", "Sunday"};

int Date::monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	year_ = 1900;
	month_ = 1;
	day_ = 1;
}

Date::Date(int month, int day, int year) {
	assert (year >= 1900 && year <= 3000);
	year_ = year;
	assert (month >= 1 && month <= 12);
	month_ = month;
	assert (day >= 1 && day <= 31);
	day_ = day;
}

string Date::weekday() const {
	int m;
	int y;
	int q;
	int h;
	 if (month_ <= 2) {
		 m = month_ + 12;
		 y = year_ - 1;
		 q = day_;
	 } else {
		 m = month_;
		 y = year_;
		 q = day_;
	 }
	 h = (q + 13*(m+1)/5 + y + y/4 + 6*(y/100) + y/400) % 7;
	 if (h < 2)
		 return toWeekday[h + 5];
	 else
		 return toWeekday[h - 2];	//Monday = 0, not Saturday = 0.
}

bool Date::operator==(Date d) const {
	return (day_ == d.day() && month_ == d.month() && year_ == d.year());
}

ostream& operator<< (ostream& os, Date d) {
	os << d.month_ << "/" << d.day_ << "/" << d.year_;
	return os;
}

bool Date::leapyear() {
	return (year_ % 4 == 0 && (year_ % 100 != 0 || year_ % 400 == 0));
}

bool Date::

void Date::operator++(int i = 0) {
	if ((day_ == 28 || day_ == 29) && month_ == 2) { //February
		if (leapyear()) {
			if (day_ == 28)
				day_++;
			else {
				month_++;
				day_ = 1;
			}
		} else {	//not leapyear, so day = 28.
			month_++;
			day_ = 1;
		}
	} else if (day_ == 30 && (month_ == 9 || month_ == 4 || month_ == 6
				|| month_ == 11)) {	//Sept, April, June and Nov have 30 days
		month_++;
		day_ = 1;
	} else if (day_ == 31) {
		if (month_ == 12) {
			year_++;
			day_ = 1;
			month_ = 1;
		} else {
			day_ = 1;
			month_++;
		}
	}else
		day_++;
}
