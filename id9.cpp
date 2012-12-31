/*
@file id8.cpp
@author Charles Jackson
date Jun 23, 2012
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {	//uses Euclid's formula to generate pythagorean triples.
	int m, n;
	bool found = false;
	for (m = 1; m <= 500, !found; m++)
		for (n = 1; n <= m; n++)
			if (2*m*m + 2*m*n == 1000) {
				cout << "found it! m = " << m << " n = " << n << endl;
				found = true;
				break;
			}
}
