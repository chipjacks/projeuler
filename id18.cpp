/*
@file id18.cpp
@author Charles Jackson
date Jun 27, 2012
Find the maximum total from top to bottom of the triangle below:
*/

#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

const int SIZE = 16;

int triangle[SIZE][SIZE];

//recursively computes maxSum for smaller and smaller triangles.
int maxSum(int col, int row) {
	assert(col <= row && row < SIZE);
	cout << col << "\t" << row << endl;
	if (row == SIZE - 1) {	//base case, when at bottom of triangle (looking at a 1X1 triangle).
		return triangle[col][row];
	} else {
		int a, b;
		return triangle[col][row] + ((a = maxSum(col, row+1)) > (b = maxSum(col+1, row+1))? a : b);
	}
}

int main() {

	//read triangle in from file into array
	ifstream infile;
	infile.open("id18.txt");
	for (int y = 1; y < SIZE; y++)	//rows of triangle
		for (int x = 1; x <= y; x++) { //cols of triangle
			assert(infile);
			infile >> triangle[x][y];
		}

	//compute max sum
	cout << maxSum(1,1) << endl;

	return 0;
}

