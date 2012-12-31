/*
@file id19.cpp
@author Charles Jackson
@created Jul 25, 2012
@description 
*/

#include "Date.h"

using std::cout;
using std::endl;

int main() {
	Date day(1, 1, 1901);
	Date end(12, 31, 2000);
	int sundayCount = 0;
	for (int i = 0; day != end; i++) {
//		cout << day << "\t" << day.weekday() << endl;
		day++;
		if (day.weekday() == "Sunday" && day.day() == 1)
			sundayCount++;
	}

	cout << sundayCount << endl;
	return 0;
}




