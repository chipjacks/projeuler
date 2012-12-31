/*
@file id1.cpp
@author Charles Jackson
date Jun 21, 2012
Add all the natural numbers below one thousand that are multiples of 3 or 5.
*/

#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	for (int i = 0; i < 1000; i++){
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	cout << sum;
	return 0;
}
