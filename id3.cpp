/*
@file id3.cpp
@author Charles Jackson
date Jun 21, 2012
Find the largest prime factor of a composite number.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const long bignum = 600851475143;
	const long max_prime = sqrt(bignum);
	bool prime[max_prime];
	long curmax;
	for (int i = 0; i < max_prime; i++)
		prime[i] = true;	//assume every # is prime.
	for (int i = 2; i < max_prime; i++)
		if (prime[i] == true) {
			for (int j = 2; j < max_prime/i; j++)
				prime[j*i] = false;
		if (bignum % i == 0)
			curmax = i;
		}
	cout << curmax << endl;
	return 0;
}



