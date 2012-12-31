/*
@file id2.cpp
@author Charles Jackson
date Jun 21, 2012
By considering the terms in the Fibonacci sequence whose values do
not exceed four million, find the sum of the even-valued terms.
*/

#include <iostream>
#include <climits>

using namespace std;

long long next(long long &prev, long long &cur){
	long long next = prev + cur;
	prev = cur;
	cur = next;
	return next;
}

int main() {
	long long sum = 0;
	long long prev = 0;
	long long cur = 1;
	while(next(prev, cur) <= 4000000) {
		cout << cur << endl;
		if (cur % 2 == 0)
			sum += cur;
	}
	cout << sum << endl;
	return 0;
}
