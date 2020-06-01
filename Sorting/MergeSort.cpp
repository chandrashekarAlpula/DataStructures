/*
 * MergeSort.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<iostream>

void Merge(int A[], int left, int mid, int right, int temp[]){

	int pos = left;
	int l1 = left;
	int l2 = mid + 1;
	//printf("\nL1:%d,L2:%d,mid:%d,right:%d", l1, l2, mid, right);
	while(l1 <= mid && l2 <= right){
		if(A[l1] <= A[l2])
			temp[pos++] = A[l1++];
		else
			temp[pos++] = A[l2++];
	}

	while(l1 <= mid)
		temp[pos++] = A[l1++];
	while(l2 <= right)
		temp[pos++]  = A[l2++];
	//Copy back the elements back to A array from temp
	//Since left and mid indexes are changed, we use right index to copy
	//printf("\n POS:SIZ %d,%d", pos,n);
	for(int i = left; i <= right; i++)
		A[i] = temp[i];
}

void MergeSort(int A[], int left, int right, int temp[]){
	if(left >= right)
		return;
	int mid = (left + right)/2;
	MergeSort(A, left, mid, temp);
	MergeSort(A, mid+1, right, temp);
	int n = (right-left)/2;
	Merge(A, left, mid, right, temp);

}

void printArray(int A[], int n){
	printf("\n");
	for(int i=0; i<n; i++)
		printf("%d ", A[i]);
}
//Driver program
int main(){

	int A[] = {9,8,7,6,5,1,2,3,4,11};
	//int A[] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
	int temp[100];
	int n = sizeof(A)/sizeof(A[0]);
	printArray(A, n);
	MergeSort(A, 0, (n-1), temp);
	printArray(A, n);
	printArray(temp, n);
}



