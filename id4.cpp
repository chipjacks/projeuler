/*
@file id4.cpp
@author Charles Jackson
date Jun 21, 2012
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool is_pal(int i) {
	char buffer[30];
	snprintf(buffer, 30, "%d", i);
	int last;
	for (last = 0; buffer[last] != '\0'; last++) {};
	last--;
	int first = 0;
	while (first < last) {
		if (buffer[first] != buffer[last])
			return false;
		first++;
		last--;
	}
	return true;
}

bool is_mult(int i) {
	int min_guess = sqrt(i);
	int cur_guess = 999;
	while (cur_guess > min_guess) {
		if (i % cur_guess == 0)
			return true;
		cur_guess--;
	}
	return false;
}

int main() {
	const int max = 999*999;
	int cur = max;
	bool cont = true;
	while (cont) {
		cur--;
		cout << cur << "\n";
		if (is_pal(cur))
			if (is_mult(cur))
				cont = false;
	}
	cout << cur;

	return 0;
}



