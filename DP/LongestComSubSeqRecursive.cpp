/*
 * LongestComSubSeqRecursive.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<string.h>

char Map[1000];
int k =  0;
int max(int a, int b){
	return (a >= b ? a : b);
}
int LongComSubSeqRecLength(char A[], int m, int i, char B[], int n, int j){
	if( i >= m || j >= n)
		return 0;
	k++;
	if(A[i] == B[j]){
		/*printf("\n Matched at i %d and j %d char %c", i, j, A[i]);
		Map[k++] = A[i];*/
		return 1 + LongComSubSeqRecLength(A, m, i+1, B, n, j+1);
	}
	return (max(LongComSubSeqRecLength(A, m, i, B, n, j+1),
			LongComSubSeqRecLength(A, m, i+1, B, n, j)) );

}
int main(){

	char A[] = "ABCBDAB";
	char B[] = "BDCABA";
	int m = strlen(A);
	int n = strlen(B);
	for(int i = 0; i < 1000; i++)
		Map[i] = '\0';
	int seqLen = LongComSubSeqRecLength(A, m, 0, B, n, 0);
	//Map[k] = '\0';
	printf("\n Long sub seq is %d and k is %d\n", seqLen, k);
	return 0;
}



;
