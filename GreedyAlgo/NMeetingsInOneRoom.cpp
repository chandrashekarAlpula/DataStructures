/*
 * NMeetingsInOneRoom.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>

using namespace std;

bool isPrint = false;
#define FOR(k,n) for(int i = k; i< n; i++)

struct MeetData{
	int time;
	int id;
	bool isStart;

	MeetData(){
		time = 0;
		id = 0;
		isStart = false;
	}
	void Print(){
		printf("%d:%d:%c ", id, time, (isStart == true?'S':'F'));
	}
};

void PrintArray(MeetData A[], int n){
	if(!isPrint)
		return;
	cout << endl;
	for(int i = 0; i < n; i++){
		A[i].Print();
	}
}
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int Sort(MeetData A[], MeetData B[], int n){
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0 && A[j].time < A[j-1].time; j--){
			swap(A[j], A[j-1]);
			swap(B[j], B[j-1]);
		}
	}
}
void FindMeeting(MeetData S[], MeetData F[], int n){
	int lastEndTime = F[0].time;
	cout << F[0].id << " ";
	for(int i = 1; i < n; i++){
		if(S[i].time > lastEndTime){
			cout << F[i].id << " ";
			lastEndTime = F[i].time;
		}
	}

}

int main(){

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		MeetData S[n];
		MeetData F[n];
		for(int i = 0; i < n; i++){
			cin >> S[i].time;
			S[i].id = i+1;
			S[i].isStart =  true;
		}
		for(int i = 0; i < n; i++){
			cin >> F[i].time;
			F[i].id = i+1;
			F[i].isStart =  false;
		}
		PrintArray(S, n);
		PrintArray(F, n);
		Sort(F, S, n);
		PrintArray(S, n);
		PrintArray(F, n);
		FindMeeting(S, F, n);
		cout << endl;
	}
}

/*
 * Example:

Input:

2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252

Output:

1 2 4 5
6 7 1
*/

 */
