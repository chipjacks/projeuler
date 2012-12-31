/*
@file id12.cpp
@author Charles Jackson
date Jun 23, 2012
What is the value of the first triangle number to have over five hundred divisors?
*/

#include <iostream>
#include <cmath>

using namespace std;

int divCount (long n) {
	if (n % 2 != 0)		//lets assume we are looking for an even number.
		return 1;
	int count = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0)
			count++;
	}
	return 2*count;
}

int main() {
	long tno = 1;
	long i = 1;
	int count = 0;
	for ( ; count <= 500 ; i++) {
		tno += i;
		count = divCount(tno);
	}
	cout << i << endl;
	return 0;
}

