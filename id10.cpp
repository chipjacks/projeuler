/*
@file id10.cpp
@author Charles Jackson
date Jun 23, 2012
Find the sum of all the primes below two million.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {		//sieve of Eratosthenes
	const int MAX = 2000001;
	long sum = 0;
	bool prime[MAX];
	for (int i = 0; i < MAX; i++)
		prime[i] = true;	//assume every # is prime.
	for (int i = 2; i <= MAX; i++) {
		if (prime[i] == true) {
			for (int j = 2; j < MAX/i; j++)
				prime[j*i] = false;
			sum += i;
			cout << i << "\t" << sum << endl;
			}
		}
	return 0;
}

