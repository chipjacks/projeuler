/*
@file id11.cpp
@author Charles Jackson
date Jun 23, 2012
What is the greatest product of four adjacent numbers in any direction
(up, down, left, right, or diagonally) in the 20x20 grid?
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream infile;
	infile.open("id11.txt");
	int grid[20][20];
	for (int y = 0; y < 20; y++)
		for (int x = 0; x < 20; x++)
			infile >> grid[x][y];

	int maxProd = 0;
	int prod = 1;
	cout << "horizontal: " << endl;
	for (int s = 0; s <= 16; s++) {		//check horizontal sets of 4.
		for (int r = 0; r < 20; r++) {
			prod = grid[s][r]*grid[s+1][r]*grid[s+2][r]*grid[s+3][r];
			if (prod > maxProd) {
				maxProd = prod;
				cout << s << "\t" << r << "\t" << prod << endl;
			}
		}
	}

	cout << "vertical: " << endl;
	for (int s = 0; s <= 16; s++) {		//check vertical sets of 4.
		for (int r = 0; r < 20; r++) {
			prod = grid[r][s]*grid[r][s+1]*grid[r][s+2]*grid[r][s+3];
			if (prod > maxProd) {
				maxProd = prod;
				cout << r << "\t" << s << "\t" << prod << endl;
			}
		}
	}

	cout << "slanting down: " << endl;
	for (int s = 0; s <= 16; s++) {		//check downward slanting sets of 4.
		for (int r = 0; r <= 16; r++) {
			prod = grid[r][s]*grid[r+1][s+1]*grid[r+2][s+2]*grid[r+3][s+3];
			if (prod > maxProd) {
				maxProd = prod;
				cout << r << "\t" << s << "\t" << prod << endl;
			}
		}
	}


	cout << "slanting up: " << endl;
	for (int s = 3; s <= 19; s++) {		//check upward slanting sets of 4.
		for (int r = 0; r <= 16; r++) {
			prod = grid[r][s]*grid[r+1][s-1]*grid[r+2][s-2]*grid[r+3][s-3];
			if (prod > maxProd) {
				maxProd = prod;
				cout << r << "\t" << s << "\t" << prod << endl;
			}
		}
	}

	return 0;
}

