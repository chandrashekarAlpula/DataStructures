/*
 * SegTree.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: chandra.shekhar
 */

#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 0X0FFFFFFF

int min(int a, int b){
	return (a <= b ? a : b);
}
void CreateSegTree(int A[], int SegT[], int low, int high, int pos){
	if(low == high){
		SegT[pos] = A[low];
		return;
	}
	int mid = (low + high) >> 1;//(a + b)/2
	CreateSegTree(A, SegT, low, mid, 2*pos + 1); // Create left sub tree
	CreateSegTree(A, SegT, mid+1, high, 2*pos + 2); // Create rght sub tree

	SegT[pos] = min(SegT[2*pos + 1], SegT[2*pos + 2]);

}

int QuerySegTree(int SegT[], int qlow, int qhigh, int low, int high, int pos){
	// Total overlap
	if(qlow <= low && qhigh >= high){
		printf("\nTotal overlap lowhigh[%d,%d] and qlowhigh[%d,%d], SegT[%d] %d", low,high, qlow,qhigh, pos, SegT[pos]);
		return SegT[pos];
	}
	// No overlap
	if(qlow > high || qhigh < low){
		printf("\nNo overlap lowhigh[%d,%d] and qlowhigh[%d,%d], pos %d, %d", low,high, qlow,qhigh, pos, INT_MAX);
		return INT_MAX;
	}

	//partial Overlap
	int mid = (low + high) >> 1;

	int min1 =  (min(QuerySegTree(SegT, qlow, qhigh, low, mid, 2*pos+1),
			QuerySegTree(SegT, qlow, qhigh, mid+1, high, 2*pos+2)));
	printf("\n min of %d and %d is %d\n ",(2*pos+1), (2*pos+2), min1);
	return min1;


}
void PrintArray(int A[], int n){
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d  ", A[i]);
	printf("\n");
}
int main(){

	int arr[] = {0, 2, -1, 0, 2, 4, -2};
	int len = sizeof(arr)/sizeof(arr[0]);
	PrintArray(arr, len);
	int SegT[15] ;
	CreateSegTree(arr, SegT, 0, len-1, 0);
	PrintArray(SegT, 15);
	int min = QuerySegTree(SegT, 4, 6, 0, len -1, 0);
	printf("\n Min %d \n", min);
	return 0;
}


