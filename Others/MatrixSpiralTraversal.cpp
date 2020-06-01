/*
 * MatrixSpiralTraversal.cpp
 *
 *  Created on: Dec 9, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>

#define N 4
using namespace std;

int main(){

	int matrix[N][N] ;
	int cnt =1;
	for(int i=0; i<N; i++)
		for(int j=0;j<N; j++)
			matrix[i][j] = cnt++;

	cout << endl << "Array elements " << endl ;
	//Initialize the array with numbers in sequential order
	for(int i=0; i<N; i++){
			for(int j=0;j<N; j++){
				cout <<matrix[i][j] << "\t" ;
			}
			cout << endl;
	}

	// ***** Actual logic from Here ********* //

	//Initializing with middle element
	int rowIdx = N/2;
	int colIdx = rowIdx;

	//Coloumn and row traversal counters
	int rowToTraverse = 1;
	int ColToTraverse = 1;

	// True means either right and down directions. False is left and up
	bool direction = true;
	cout << endl << "Spiral order O/P" << endl ;
	cout << matrix[rowIdx][colIdx] << " " ; // Print the middle one

	while(rowIdx >= 0 && colIdx < N){ // iterate till top right corner
		// Traverse right or left
		for(int i=1; i <= ColToTraverse; i++){
			if(direction){
				colIdx++; //Move right
			}else{
				colIdx--; // Move left
			}
			//Array bound check
			if(rowIdx < 0 || colIdx < 0 || rowIdx > N-1 || colIdx > N-1)
				return 0;

			cout << matrix[rowIdx][colIdx] << " " ;
		}
		ColToTraverse++;  // next time number of colomns traversed will be one extra.

		// now traverse down or up
		for(int i=1; i <= rowToTraverse; i++){
			//cout << matrix[rowIdx][colIdx] << "\t" ;
			if(direction){
				rowIdx++; //Move down
			}else{
				rowIdx--; //Move up
			}
			if(rowIdx < 0 || colIdx < 0 || rowIdx > N-1 || colIdx > N-1)
				return 0;

			cout << matrix[rowIdx][colIdx] << " " ;
		}
		rowToTraverse++;;

		//Reverse the direction
		direction = !direction;
	}
}



