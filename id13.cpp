/*
@file id13.cpp
@author Charles Jackson
date Jun 23, 2012
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	double sum = 0;
	double current;
	ifstream infile;
	infile.open("id13.txt");
	cout.precision(12);
	while (infile >> current) {
		sum += current;
		cout << sum << endl;
	}
	cout << sum;
	return 0;
}
