/*
 * MaxProfitJobSeq.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: chandra.shekhar
 */
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>

struct Job{
	char Id;
	int deadLine;
	int profit;
};

int min(int a, int b){
	return a <= b ? a : b;
}
bool Compare(Job a, Job b){
	return a.profit > b.profit;
}
void printArray(Job arr[], int n){
	std::cout<< std::endl;
	for(int i = 0; i < n; i++)
		printf("(Id:%c-Pro:%d)  ",arr[i].Id, arr[i].profit);


}

/*Maintain an array(say res[]) for maintaining the indexes of jobs.
 * Start with the highest priority job and put it in the corresponding place in the
 * resultant array(res) based on the deadline.repeat this for elements based on their priorities.
 */
void PrintJobScheduling(Job arr[], int n){
	std::sort(arr, arr+n, Compare);
	int res[n];
	for(int i = 0; i < n; i++)
		res[i] = -1;

	for(int i = 0; i < n; i++){
		// min is needed if the deadline is greater than n, so place it on the last index of res based on the availability.
		int j = min((arr[i].deadLine - 1), n);
		for(; j >= 0; j--){
			if(res[j] == -1){
				res[j] = i;
				break;
			}
		}

	}
	printf("\n");
	for(int i = 0; i < n; i++){
		if(res[i] != -1){
			printf("%c ", arr[res[i]].Id);
		}
	}
}

// Returns minimum number of platforms required
void printJobScheduling123(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of prfit
	std::sort(arr, arr+n, Compare);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i=0; i<n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i=0; i<n; i++)
	{
		// Find a free slot for this job (Note that we start
		// from the last possible slot)
		for (int j=min(n, arr[i].deadLine)-1; j>=0; j--)
		{
			// Free slot found
			if (slot[j]==false)
			{
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}
	printf("\n");
	// Print the result
	for (int i=0; i<n; i++)
	if (slot[i])
		printf("%c ", arr[result[i]].Id);
}


int main(){
	Job arr[] = { {'a', 4, 100}, {'b', 1, 19}, {'c', 2, 27},
			{'d', 1, 25}, {'e', 3, 15}};
	int n = sizeof(arr)/sizeof(arr[0]);
	//printArray(arr, n);
	//printJobScheduling123(arr, n);
	PrintJobScheduling(arr, n);
}




