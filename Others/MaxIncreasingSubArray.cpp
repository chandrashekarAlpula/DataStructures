/*
 * MaxIncreasingSubArray.cpp
 *
 *  Created on: Dec 9, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>

using namespace std;

int MaxInscreaseSubArray(int arr[], int n){
	int maxSum = 0;
	int sum = arr[0];
	maxSum = sum;
	for(int i=1; i<n; i++){
		if(arr[i] >= arr[i-1]){
			sum += arr[i];
		}else{
			sum = arr[i];
		}
		if(sum > maxSum)
			maxSum = sum;
	}
	return maxSum;
}
int main(){

	int arr[] = {2,5,6,3,2,1,8};
	int sum = MaxInscreaseSubArray(arr, (sizeof(arr)/sizeof(arr[0])));
	cout << endl << "Max sum is " << sum << endl;
	return 0;
}
