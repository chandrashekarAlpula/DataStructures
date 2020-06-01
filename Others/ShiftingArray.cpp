/*
 * ShiftingArray.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>

using namespace std;
int A[] = {1,3,5,7,2,4,6,8};
int mid = 4;
int size = 8;

void PrintAarray(){
	//cout << endl;
	for(int i=0; i<8; i++)
		cout << A[i] << "\t";
	cout << endl;
}
void BruteForceShuffle(){
	for(int i=1,j = mid; j < size; j++, i=  i +2){
		cout << "LL" << endl ;
		for(int k=j; k > i; k--){
			swap(A[k], A[k-1]);
			cout << "TT ";
			PrintAarray();
		}
	}
}

void DivideAndCon(){

}
int main(){
	PrintAarray();
	BruteForceShuffle();
	PrintAarray();

}



