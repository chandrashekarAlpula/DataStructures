/*
 * test.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: chandra.shekhar
 */

#include<iostream>
#include<stdio.h>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

void Sort(int A[], int B[], int n){
	for(int i =1; i < n; i++){
		for(int j = i; j > 0 && A[j] < A[j-1]; j--){
			swap(A[j], A[j-1]);
			swap(B[j], B[j-1]);
		}
	}
}

void PrintArray(int A[], int B[], int n){
	cout << endl;
	for(int i = 0;  i < n; i++)
		printf("%d:%d ", A[i], B[i]);
}
void FindMaxChain(int A[], int B[], int n){
	int cnt = 1;
	int lastEnd = B[0];

	for(int i= 1; i < n; i++){
		if(A[i] > lastEnd){
			cnt++;
			lastEnd = B[i];
		}
	}
	cout << cnt;
}


int main(){

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int A[n];
		int B[n];

		for(int i = 0; i < n; i++){
			cin >> A[i];
			cin >> B[i];
		}
		Sort(A, B, n);
		//PrintArray(A, B, n);
		FindMaxChain(A, B, n);
	}
	return 0;

}
