/*
@file id7.cpp
@author Charles Jackson
date Jun 21, 2012
What is the 10,001st prime number?
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {		//sieve of Eratosthenes
	const int MAX = 117000;
	int count;
	bool prime[MAX];
	for (int i = 0; i < MAX; i++)
		prime[i] = true;	//assume every # is prime.
	for (int i = 2; i < MAX; i++)
		if (prime[i] == true) {
			for (int j = 2; j < MAX/i; j++)
				prime[j*i] = false;
			count++;
			if (count == 10001) {
				cout << "prime found!  " << i;
				break;
			}
		}
	return 0;
}

