/*
 * ActivitySelectionProblem.cpp
 *
 *  Created on: Jan 18, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>

using namespace std;

void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void MySort(int A[], int B[], int n){
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0 && A[j] < A[j-1] ; j--){
			swap(A[j], A[j-1]);
			swap(B[j], B[j-1]);
		}
	}
}

void PrintArray(int A[], int n){
	cout <<endl ;
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
}
void ActivitySelctAlgo(int s[], int f[], int n){
	//start[]  =  {1, 3, 0, 5, 8, 5};
    //finish[] =  {2, 4, 6, 7, 9, 9};
	int cnt = 1;
	int lastFinishIdx = 0;
	for(int i = 1; i < n; i++){
		//cout << endl << i << "," << s[i] << "," << lastFinishIdx << endl;
		if(s[i] > lastFinishIdx){
			lastFinishIdx = f[i];
			//cout << "Incr" << endl ;
			cnt++;
		}
	}
	cout << endl << "Number of activities selcted are " << cnt << endl;
}
int main(){

	int s[] = {0, 5, 1, 5, 8, 3};
	int f[] = {6, 9, 2, 7, 9, 4};

	int n = sizeof(s)/sizeof(s[0]);
	//PrintArray(s, n);
	//PrintArray(f, n);

	MySort(f, s, n);

	cout << endl << "After sorting based on finish times";
	PrintArray(s, n);
	PrintArray(f, n);
	ActivitySelctAlgo(s, f, n);

	return 0;
}



