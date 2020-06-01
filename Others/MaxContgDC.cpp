/*
 * MaxContgDC.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>
using namespace std;

int MaxContigiousDC(int *A, int l, int r){
	int m = l + (r -l)/2;
	if(l == r)
		return (A[l] > 0 ? A[l] : 0);
	int leftMax = MaxContigiousDC(A, l, m);
	int rightMax = MaxContigiousDC(A, m+1, r);
	int leftBorderMax = 0;
	int rightBorderMax = 0;
	int lbc = 0, rbc = 0;
	//Calculate the left side sum from the mid
	for(int i=m; i>=l; i--){
		lbc  += A[i];
		if(lbc > leftBorderMax)
			leftBorderMax = lbc;
	}
	// Calculate the right border sum from the mid
	for(int i=m+1; i<=r; i++){
		rbc += A[i];
		if(rbc > rightBorderMax)
			rightBorderMax = rbc;
	}
	//Return the Max
	int max1 = max(max(leftMax, rightMax),(leftBorderMax+rightBorderMax));
	return (max1 > 0 ? max1 : 0);
}
int main(){
	//int A[] = {-2, 11, -4, 13, -5, 2};
	int A[] = {1,-3,4,-2,-1,6};
	int l = sizeof(A)/sizeof(A[0]);
	int ret = MaxContigiousDC(A, 0, l-1);
	cout << endl << "max contiguous sum is " << ret << endl ;
	return 0;
}



