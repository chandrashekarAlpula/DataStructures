/*
 * test.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: chandra.shekhar
 */

#include<iostream>
#include<stdio.h>
using namespace std;

struct JobDet{
	int id;
	int time;
	int profit;

	JobDet(){
		id = 0;
		time = 0;
		profit = 0;
	}
	void Print(){
		printf("%d:%d:%d ", id,time, profit);
	}
};
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

void Sort(JobDet A[], int n){
	for(int i =1; i < n; i++){
		for(int j = i; j>0 && A[j].profit > A[j-1].profit; j--)
			swap(A[j], A[j-1]);
	}
}

void PrintArray(JobDet A[], int n){
	cout << endl;
	for(int i = 0;  i < n; i++)
		A[i].Print();
	cout << endl;
}

void FindMaxProfit(JobDet A[], int n, int maxDeadLine){


	//in temp index is the deadline and value is the profit
	int temp[maxDeadLine];
	for(int i =0; i< maxDeadLine; i++){
		temp[i] = -1;
	}
	int profit =0;
	int cnt = 0;
	//temp[A[0].time] = A[0].profit;

	for(int i = 0; i < n; i++){
		/*cout << endl;
		for(int i= 0;i < n; i++)
			printf("%d ", temp[i]);*/

		if(A[i].profit > temp[A[i].time]){
			//printf("\n i:%d  A[i].profit:%d A[i].time:%d temp[A[i].time]:%d", i, A[i].profit, A[i].time, temp[A[i].time]);
			profit += A[i].profit;
			cnt++;
			temp[A[i].time] = A[i].profit;
			continue;
		}

		for(int j = A[i].time-1 ; j >=0; j --){

			if(A[i].profit > temp[j]){
				//printf("\n i:%d j:%d A[i].profit:%d temp[j]:%d", i,j, A[i].profit, temp[j]);
				profit += A[i].profit;
				cnt++;
				temp[j] = A[i].profit;
				break;
			}
		}
	}
	//cout<< "I is 0 "<< " Profit is " << profit << endl;

	cout << cnt << " " << profit;
	cout << endl;
}
int main(){

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		JobDet A[n];
		int maxDeadLine = 0;
		for(int i = 0; i < n; i++){
			cin >> A[i].id >> A[i].time >> A[i].profit;
			A[i].time--;
			if(A[i].time > maxDeadLine)
				maxDeadLine = A[i].time;
		}
		if(n > maxDeadLine)
			maxDeadLine = n;

		Sort(A, n);
		PrintArray(A, n);
		FindMaxProfit(A, n, maxDeadLine);
	}
	return 0;

}
