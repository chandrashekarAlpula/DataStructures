/*
 * Order01And2s.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>

using namespace std;

void OrderTheNumbers(int A[], int n){
	int l = 0, m = 0, h = n-1;
	while(m <= h){
		switch(A[m]){
			case 0:
				swap(A[l++], A[m++]);
				break;
			case 1:
				m++;
				break;
			case 2:
				swap(A[m], A[h--]);
				break;
			default:
				cout << endl << "Wrong numbers" << endl ;
		}

	}

}

int main(){

	int A[] = {0,1,1,0,1,2,1,2,0,0,0,1};
	int l = sizeof(A)/sizeof(A[0]);

	printf("Before Sorting \n");
		for(int i=0; i<l; i++)
			printf("%d\t", A[i]);
		printf("\n");

		OrderTheNumbers(A, l);

		printf("After Sorting \n");
		for(int i=0; i<l; i++)
			printf("%d\t", A[i]);
		printf("\n");

}



