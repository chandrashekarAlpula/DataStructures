/*
 * Grouping012s.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>

using namespace std;

void swap(int A[],int i, int j){
	int tmp = A[i];
	A[i] = A[j];
	A[j]  = tmp;
}

void PrintA(int A[]){
	printf("\n");
	for(int i=0; i<12; i++){
		printf("%d \t", A[i]);
	}
}
int main(){

	int A[] = {0,1,1,0,1,2,1,2,0,0,0,1};
	int l=0, m=0;
	int h = 11;
	PrintA(A);
	while(m <= h){

		switch(A[m]){
		case 0 :
			swap(A, l, m);
			l++;
			m++;

			break;
		case 1:
			m++;
			break;
		case 2:
			swap(A, m, h);
			h--;
			break;
		default:
			printf("\n Invalid Input returning ");
			break;
		}


	}
	PrintA(A);
}
