/*
 * MinPlatform.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: chandra.shekhar
 */

#include<iostream>
#include<stdio.h>

using namespace std;

bool print = false;

struct ArrDep{
	int id;
	int time;
	bool isArrival;

	ArrDep(int _id, int _tm, bool _isArr){
		id = _id;
		time = _tm;
		isArrival = _isArr;
	}

	ArrDep(){
		id =0;
		time = 0 ;
		isArrival = false;
	}

	void Print(){
		printf("%d:%d:%c ", id, time, isArrival?'A':'D');
	}
};


void Print(ArrDep A[], int n){
	if(!print)
		return ;
	cout << endl;
	for(int i = 0; i < n; i++)
		A[i].Print();
}

void swap(ArrDep &a, ArrDep &b){
	ArrDep temp;
	temp = a;
	a = b;
	b = temp;
}

void Sort(ArrDep A[], int n){
	for(int i = 1; i < n; i++){
		for(int j = i;  j > 0 && A[j].time < A[j-1].time; j--)
			swap(A[j], A[j-1]);
	}
}

int FindMinPlatforms(ArrDep A[], ArrDep D[], int n){
	int i = 1, j =0;
	int pltCnt = 1;
	int minPltCnt = 1;
	while(i < n && j < n){
		if(A[i].time < D[j].time){
			pltCnt++;
			i++;
			if(pltCnt > minPltCnt)
				minPltCnt = pltCnt;
		}else if(A[i].time == D[j].time && A[i].id == D[j].id){
			//Consider first arrival  and them departure
			i++;
			pltCnt++;
			if(pltCnt > minPltCnt)
				minPltCnt = pltCnt;

			pltCnt--;
			j++;
		}else{
			pltCnt--;
			j++;
		}
	}
	return minPltCnt;
}

int main(){

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		ArrDep A[n];
		ArrDep D[n];
		int x;
		for(int i = 0; i < n; i++){
			cin >> x;
			A[i].id = i;
			A[i].time = x;
			A[i].isArrival = true;
		}
		for(int i = 0; i < n; i++){
			cin >> x;
			D[i].id = i;
			D[i].time = x;
			D[i].isArrival = false;
		}
		Print(A, n);
		Print(D, n);

		Sort(A, n);
		Sort(D, n);

		Print(A, n);
		Print(D, n);
		int minCnt = FindMinPlatforms(A, D, n);
		cout << minCnt;
		cout << endl;
	}
	return 0;
}


