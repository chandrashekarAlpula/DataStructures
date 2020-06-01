/*
 * MinCostMatrix.cpp
 *
 *  Created on: Jul 30, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<string>

using namespace std;
#define ROW 3
#define COL 3
int Cost[ROW][COL];
int minCost( int x, int y){
	return (x <= y ? x : y);
}

template <size_t row, size_t col>
void printMat(int (&mat)[row][col]){
	for(int i=0; i<row; i++){
		cout << endl;
		for(int j=0; j<col; j++)
			cout << " " << mat[i][j] ;
	}
	cout << endl;
}

template<size_t row, size_t col>
void FindMinCost(int (&mat)[row][col]){

	if(row < 0 && col < 0){
		return;
	}
	Cost[0][0] = mat[0][0];

	for(int i=1; i < COL; i++)
		Cost[0][i] =  Cost[0][i-1] + mat[0][i];

	for(int i=1; i < ROW; i++)
		Cost[i][0]  = Cost[i-1][0] + mat[i][0];

	//printMat(Cost);
		//return;

	for(int i=1; i<row; i++)
		for(int j=1; j<col; j++)
			Cost[i][j] = minCost(minCost(Cost[i][j-1], Cost[i-1][j]) , Cost[i-1][j-1]) + mat[i][j];
}
int main(){

	int mat[ROW][COL] = {{1,2,3}, {4,5,6}, {1,2,3}};

	cout << endl << " Matrix elements " << endl;


	printMat(mat);
	FindMinCost(mat);
	printMat(Cost);

	return 0;
}

