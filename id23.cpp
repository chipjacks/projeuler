/*
@file id23.cpp
@author Charles Jackson
@created Jul 17, 2012
@description Find the sum of all the positive integers which cannot be written
as the sum of two abundant numbers.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<int> primes;	//filled with a list of primes, starting with 2.


//sieve of Eratosthenes, fills a vector with all the primes
//from 2 to max
void sieveOfErat(vector<int> &primes, const int max) {
	long sum = 0;
	bool prime[max];
	for (int i = 0; i < max; i++)
		prime[i] = true;	//assume every # is prime.
	for (int i = 2; i <= max; i++) {
		if (prime[i] == true) {
			for (int j = 2; j <= max/i; j++)
				prime[j*i] = false;
			primes.push_back(i);
			}
		}
}


//computes aliquot sum using prime factorization and multiplicative property of
//divisor function.
int aliquotSum(int x) {
	int sum = 1;	//immediately add 1 to sum since x*1 = x
	int termSum;	//for prime i (p), termSum = 1 + p + p^2 + ... + p^n,
	int div;				//where n is max power of p by which x is divisible.
	for (int i = 0; i < primes.size() && primes[i] <= x; i++) {
		termSum = 1;
		for (int j = 1; ((div = pow((double)primes[i], j)) <= x) && x % div == 0; j++) {
			termSum += div;
		}
		sum *= termSum;
	}
	return sum - x;
}


int main() {
	const int MAX = 20162;		//it is known that all numbers greater then 20,161
								//can be written as the sum of two abundant numbers.

	//generate list of primes, place in vector.
	const int maxprime = MAX;
	sieveOfErat(primes, maxprime);

	//mark all abundant numbers from 1 .. MAX
	bool isAbundant[MAX] = {0};
	for (int i = 1; i < MAX; i++) {
		if (!isAbundant[i]) {
			if (aliquotSum(i) > i) {
				isAbundant[i] = true;
				for (int mult = 2; i*mult < MAX; mult++) {	//any multiple of an abundant
					isAbundant[i*mult] = true;					//number is abundant.
				}
			}
		}
	}

	//fill vector with abundant numbers
	vector<int> abunNums;
	for (int i = 1; i < MAX; i++) {
		if (isAbundant[i]) {
			abunNums.push_back(i);
		}
	}

	//mark all numbers that are the sum of two abundant numbers and are less then MAX.
	bool isAbunSum[MAX] = {0};
	for (int i = 0; i < abunNums.size(); i++) {
		for (int j = 0; abunNums[i] + abunNums[j] < MAX; j++) {
			isAbunSum[abunNums[i] + abunNums[j]] = true;
		}
	}

	//sum up all numbers that aren't the sum of two abundant numbers.
	int sum = 0;
	for (int i = 1; i < MAX; i++) {
		if (!isAbunSum[i]) {
			sum += i;
		}
	}

	//report result
	cout << sum << endl;

	return 0;
}




