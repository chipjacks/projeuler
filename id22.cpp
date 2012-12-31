/*
@file id22.cpp
@author Charles Jackson
@created Jul 7, 2012
@description What is the total of all the name scores in the file?
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool operator< (string a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (i >= b.size())
			return false;	//a is longer then b
		else if (a[i] == b[i])
			continue;
		else
			return a[i] < b[i];
	}
	return true;	//b is longer then a
}

void swap (vector<string> &A, int a, int b) {
	string temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

int partition (vector<string> &A, int p, int r) {
	string pivot = A.at(r);
	int j = p - 1;	//index of divider
	for (int i = p; i < r; i++) {
		if (A.at(i) < pivot) {
			j++;
			swap(A, i, j);
		}
	}
	j++;
	swap(A, j, r);
	return j;
}

void quicksort(vector<string>& A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int alphapos (char c) {
	return c - 'A' + 1;
}

int score (string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += alphapos(s[i]);
	}
	return sum;
}

int main() {

	//initialization
	vector<string> names;
	ifstream infile;
	infile.open("id22.txt");

	//fill the names array
	char trash = infile.get();
	string current;
	char delim = '"';
	while (infile) {
		getline(infile, current, delim);
		names.push_back(current);
		infile.get(trash).get(trash);
	}

	//Sort the array
	quicksort(names, 0, names.size() - 1);

	//total all the name scores
	int total = 0;
	for (int i = 0; i < names.size(); i++){
		total += score(names[i])*(i+1);
	}

	//report total
	cout << total << endl;

return 0;
}




