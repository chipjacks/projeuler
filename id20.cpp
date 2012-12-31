/*
@file id20.cpp
@author Charles Jackson
@created Jul 19, 2012
@description Find the sum of the digits in the number 100!
@compile g++ id20.cpp -lgmp
*/

#include <iostream>
#include <gmp.h>

using namespace std;

int main() {
	 mpz_t total;
	 mpz_init(total);
	 mpz_set_ui(total, 1);

	 for (int i = 100; i > 1; i--) {
		 mpz_mul_si(total, total, i);
	 }

	 char final[mpz_sizeinbase (total, 10) + 2];

	 mpz_get_str(final, 10, total);

	 int sum = 0;
	 for (int i = 0; final[i]; i++){
		 sum += final[i] - '0';
	 }

	 cout << sum << endl;

	return 0;
}




