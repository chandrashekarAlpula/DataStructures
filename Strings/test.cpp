/*
 * test.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
int *F;
void PrefixTable(char P[], int m){
	F = (int *)malloc(m*sizeof(int));
	int i = 0, j = 0;
	F[i++] = 0;

	while(j < m){
		if(P[i] == P[j])
			F[i++] = ++j;
		else if(j > 0)
			j = F[j-1];
		else
			F[i++] = 0;
	}
}

int KMP(char T[], int n, char P[], int m){

	PrefixTable(P,m);
	int i = 0, j = 0;
	int cnt = 0;
	while(j < m){
		cnt++;
		if(T[i] == P[j]){
			if(j == m -1){
				cout << endl << "Number of comparision " << cnt ;
				return i-j;
			}
			i++;
			j++;
		}else if(j > 0){
			j = F[j-1];
		}else{
			i++;
		}
	}
	cout << endl << "Number of comparision " << cnt ;
	return -1;
}
int main(){

	char T[] = "bacbabababacaca";
	int n = strlen(T) ;
	char P[] = "ababaca";
	int m = strlen(P);
	int x = KMP(T, n, P, m);
	printf("\n pattern matched at index %d \n", x);
	return 0;
}



