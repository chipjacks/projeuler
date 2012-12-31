/*
@file id16.cpp
@author Charles Jackson
@created Jun 27, 2012
@description What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <array>

using namespace std;

int main() {
	array <int, 350> total = {0};	//array to store the big number 2^1000.
	total[0] = 1;		//initialization
	int firsDig = 0;	//keeps track where first digit in array is.
	bool carryTheOne = 0;

	for (int i = 1; i <= 1000; i++){
		for (int j = 0; j <= firsDig; j++) {
			if (2*total[j] + carryTheOne > 9) {
				total[j] = (2*total[j] + carryTheOne) % 10;
				carryTheOne = 1;
			} else {
				total[j] = 2*total[j] + carryTheOne;
				carryTheOne = 0;
			}
			if (j == firsDig && carryTheOne)
				firsDig++;
		}
		for (int n = firsDig; n >= 0; n--) {
			cout << total[n];
		}
		cout << endl;
	}

	int sum = 0;
	for (int n = firsDig; n >= 0; n--) {
		sum += total[n];
	}

	cout << sum << endl;

	return 0;
}




