/*
 * FrequencyCtr.cpp
 *
 *  Created on: Aug 18, 2016
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

/* This Function prints the number of occurrences of each number in a given array
 * maintain the counters at their corresponding indices with negative values.
 */
void FrequencyCounter(int A[], int n){
	int idx = 0;
	while(idx < n){
		int posIdx = A[idx] - 1;
		if(A[idx] > 0 && A[posIdx] > 0){
			int tmp = A[idx];
			A[idx] = A[posIdx];
			A[posIdx] = tmp;
			A[posIdx] = -1;
			continue;
		}
		if(A[idx] > 0){
			A[posIdx]--;
			A[idx] = 0;
			idx++;
		}
		else{
			idx++;
		}

	}
	cout << endl << "Frequencies " << endl ;
	for(int i=0; i< n; i++)
		printf(" %d \t %d \n", i+1 , abs(A[i]));
}
int main(){

	int A[] = {10,10,9,4,2,4,5,2,3,2,1};

	int aSize = sizeof(A)/sizeof(A[0]);
	cout << endl << "Array size is " << aSize  << endl;
	FrequencyCounter(A, aSize);
}



