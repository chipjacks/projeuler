/*
@file id14.cpp
@author Charles Jackson
date Jun 26, 2012
The following iterative sequence is defined for the set of positive integers:
n ->  n/2 (n is even)
n -> 3n + 1 (n is odd)
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <climits>

using namespace std;

const int ONEMILL = 1000000;
vector<int> chainLength;
int nCalcMax = 0;

long calcLength (long n) {
	assert(n > 0);
	if (n == 1) {
		return 1;
	}else if (n < nCalcMax) {		//chain has already been computed and length recorded.
		return chainLength.at(n);
	}else if (n % 2 == 0) {			//n is even
		return calcLength(n/2) + 1;
	}else {
		assert(n < LONG_MAX/3 - 1);
		return calcLength(3*n + 1) + 1;
	}
}

int main() {
	int maxLength = 0;
	int maxLengthIndex;
	chainLength.push_back(0);		//fill 0 index in vector
	for (int i = 1; i < ONEMILL; i++) {
		chainLength.push_back(calcLength(i));
		if (chainLength.at(i) > maxLength) {
			maxLength = chainLength.at(i);
			maxLengthIndex = i;
		}
		nCalcMax = i;
	}
	cout << maxLengthIndex << endl;
	return 0;
}

/* RUNTIME
real	0m0.154s
user	0m0.135s
sys		0m0.008s
*/

