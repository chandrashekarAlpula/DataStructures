/*
 * EvenOddSorting.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>
//#include<cstdlib>
using namespace std;

void EventOddSort(int *A, int n){
	int l = 0, h = n-1;

	while(l < h){
		while(A[l]%2 == 0 && l < h)
			l++;
		while(A[h]%2 == 1 && l < h)
			h--;

		swap(A[l++], A[h--]);
	}
	printf("low is %d and high is %d", l, h);
}

int main(){

	//int A[] = {12,34,45,9,8,90,3};
	int A[] = {1,3,5,7,2,4,6,8};
	int len = sizeof(A)/sizeof(A[0]);
	printf("Before Sorting \n");
	for(int i=0; i<len; i++)
		printf("%d\t", A[i]);
	printf("\n");

	EventOddSort(A, len);

	printf("After Sorting \n");
	for(int i=0; i<len; i++)
		printf("%d\t", A[i]);
	printf("\n");

	return 0;
}
