/*
 * BubbleSort.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

void PrintArrayElements(int *a, int len){

	printf("\n");
	for(int i=0; i < len; i++)
		printf("%u \t", a[i]);
	printf("\n");
}

void Swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
//Repeatedly comparing and adjust the elements then swap  if not ordered
void BubbleSort(int *A, int n){

	for(int i=0; i<n; i++){
		for(int j=0; j<(n-i-1); j++){
			if(A[j] > A[j+1]){
				Swap(A[j], A[j+1]);
			}
		}
	}
}

//Find the smallest or largest element and placing it in correct place
void SelectionSort(int *A, int n){

	int min = 0;
	for(int j=0; j<n; j++){
		min = j;
		for(int i = j+1; i<n; i++){
			if( A[i] < A[min] ){
				min = i;
			}
		}
		Swap(A[min], A[j]);
	}
}

//One element in each iteration is placed in its correct position
void InsertionSort(int *A, int n){
	int cnt = 0;
	cout << endl  << "In Insertion Sort" << endl;
	for(int i=1; i< n; i++){
		for(int j=i; j > 0; j--){
			cnt++;
			if(A[j-1] > A[j]){
				Swap(A[j-1], A[j]);
			}
		}
	}
	printf("\n Number of operations %d \n", cnt);

}

void InsertionSortModified(int A[], int n){
	int cnt = 0;
	for(int i = 1; i < n; i++){
		for(int j = i; (j > 0 && A[j-1] > A[j]); j--){
			swap(A[j-1], A[j]);
			cnt++;
		}
	}
	printf("\n Number of operations %d \n", cnt);

}
unsigned int Partition(int *A, int start, int end){

	int l = start-1 ;
	int r = end + 1;

	int piv = A[start];
	//printf("\n Left idx %d right idx %d piv elem %d\n", l, r, piv);
	while(1) {
		while(l < end && A[++l] <= piv);
		while(r > start && A[--r] > piv);
		//printf("\n Left idx %d right idx %d \n", l, r);
		if(l >= r){
			break;
		}
		else{
			Swap(A[l], A[r]);
		}
		//PrintArrayElements(A, end+1);
	}
	//printf("\n L is %d and r is %d", l , r);
	if(l >= r)
		Swap(A[r], A[start]);

	//PrintArrayElements(A, end+1);

	return r;

}

void QuickSort(int *A, int l, int r){

	if(l >= r)
		return;
	int _idx = Partition(A, l, r);// after partition, all the elements to the left of the pivot are less than
									// it and elements to the right are greater.
	//cout << endl << "Partition Idx " << _idx << endl;
	//exit(0);
	QuickSort(A, l, _idx-1);
	QuickSort(A, _idx+1, r);

}

int main(){

	int Arr[] = {9,8,7,6,5,4,3,2,1};
	//int Arr[] = {3,5,6,8,1,2,9};
	int size = (sizeof(Arr)/sizeof(Arr[0]));
	PrintArrayElements(Arr, size);
	//InsertionSort(Arr, size);
	//InsertionSortModified(Arr, size);
	QuickSort(Arr, 0, size-1);
	//printf("\n After Sorting");
	PrintArrayElements(Arr, size);
}



