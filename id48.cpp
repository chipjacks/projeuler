/*
@file id48.cpp
@author Charles Jackson
@created Jul 20, 2012
@description Find the last ten digits of the series, 1^1 + 2^2 + ... + 1000^1000.
*/

#include <iostream>
#include <cmath>

using namespace std;

int myPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

long lastTen (long x) {
	return x % 10000000000;
}

long ithDig (long x, int i) {
	return (x % myPow(10,i)) - (x % myPow(10, i-1));
}

long multTenDig (long x, long y) {
	long result = 0;
	for (int j = 1; j <= 10; j++) {
		result += x * ithDig(y, j);
	}
	return result;
}

int main() {
	long p = 12345678901234567;
	long q = 98765432109876543;
	cout << multTenDig(432,117) << endl;

	return 0;
}




