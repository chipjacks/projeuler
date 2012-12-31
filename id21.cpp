/*
@file id21.cpp
@author Charles Jackson
@created Jul 8, 2012
@description Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include <vector>
#include <cmath>	//for sqrt()

using namespace std;

vector<int> primes;

////sieve of Eratosthenes, fills a vector with all the primes
////from 2 to max
//void sieveOfErat(vector<int> &primes, const int max) {
//	long sum = 0;
//	bool prime[max];
//	for (int i = 0; i < max; i++)
//		prime[i] = true;	//assume every # is prime.
//	for (int i = 2; i <= max; i++) {
//		if (prime[i] == true) {
//			for (int j = 2; j <= max/i; j++)
//				prime[j*i] = false;
//			primes.push_back(i);
//			}
//		}
//}

int divSum(int x) {
	int sum = 1;	//immediately add 1 to sum since x*1 = x
	for (int j = 2; j <= sqrt(x); j++) {
		if (x % j == 0) {
			sum += j + (x/j);
		}
	}
	return sum;
}

int main() {
	const int MAX = 10000;

//	//generate list of primes, place in vector.
//	const int maxprime = sqrt(MAX);
//	sieveOfErat(primes, maxprime);

	//calculate sum of divisors for all numbers 1 .. 10000, place in array.
	int divSums[MAX + 1];
	for (int num = 2; num <= MAX; num++) {
		divSums[num] = divSum(num);
	}

	//look for amicable pairs, sum them.
	int sum = 0;
	for (int n = 1; n <= MAX; n++) {
		if (divSums[n] < n)
			if (divSums[divSums[n]] == n) {
				cout << n << endl;
				sum += n + divSums[n];
			}
	}

	//report sum.
	cout << sum << endl;


	return 0;
}




