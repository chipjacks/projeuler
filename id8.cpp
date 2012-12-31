/*
@file id8.cpp
@author Charles Jackson
date Jun 21, 2012
Find the greatest product of five consecutive digits in the 1000-digit number.
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main() {
	ifstream infile;
	infile.open("id7.txt");
	string number;
	char current;
	while (infile >> current)
		number.push_back(current);
	int start = 0;
	int end = start + 4;
	int prod = 1;
	for (int i = start; i < end; i++)	//initialize product.
		prod *= (number[i] - '0');
	int max_prod = 0;
	for ( ; end <= 1000; end++, start++) {
		prod *= (number[end] - '0');
		cout << prod << endl;
		if (prod > max_prod) {
			max_prod = prod;
			cout << "\t" << max_prod << endl;
		}
		if (number[start] == '0') {
			prod = 1;
			for (int i = start+1; i <= end; i++)	//re-initialize product.
				prod *= (number[i] - '0');
		} else
			prod /= (number[start] - '0');
	}
	return 0;
}

