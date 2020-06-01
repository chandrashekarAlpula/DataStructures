/*
 * StringMatchingAlgo.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<string.h>

int BruteForce(char T[], int n, char P[], int m){

	for(int i = 0; i < (n-m); i++){
		int j = 0;
		while(j < m && P[j] == T[i + j])
			j++;

		if(j == m)
			return i;
	}
	return -1;
}


int main(){

	char T[] = {"chandra shekhar"};
	int n = strlen(T);
	char P[] = {"phandra"};
	int m = strlen(P);

	int c = BruteForce(T, n, P, m);
	printf("\n String found at index %d \n", c);
	return 0;
}
