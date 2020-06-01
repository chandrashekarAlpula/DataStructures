/*
 * KPMAlgo.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *F;
void PrefixTable(char P[], int m){
	int i = 1, j =0;
	while(i < m){
		if(P[i] == P[j]){
			F[i++] = ++j;
		}else if(j > 0){
			j = F[j-1];
		}else{
			i++;
			F[i] = 0;
		}
	}
}

int KMP(char T[], int n, char P[], int m){
	F = (int *)malloc(m * sizeof(int));
	for(int k = 0; k<m; k++)
		F[k] = 0;
	PrefixTable(P, m);
	int i = 0, j = 0;
	while(i < n){
		if(T[i] == P[j]){
			if(j == m-1)
				return i - j;
			else{
				i++;
				j++;
			}
		}else  if(j > 0){
			j = F[j - 1];
		}else{
			i++;

		}
	}
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
