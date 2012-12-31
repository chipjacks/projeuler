/*
@file id5.cpp
@author Charles Jackson
date Jun 22, 2012
What is the smallest positive number that is evenly divisible by all
of the numbers from 1 to 20?
*/

#include <iostream>

using namespace std;

int main() {
	long cur;
	bool cont = true;
	for (cur = 380; cont; cur += 380) {
		cout << cur << "\t";
		for (int div = 18; div >= 11; div--) {
			if (cur % div != 0)
				break;
			else if (div == 11)
				cont = false;
			cout << div << "\t";
		}
		cout << endl;
	}
	return 0;
}
