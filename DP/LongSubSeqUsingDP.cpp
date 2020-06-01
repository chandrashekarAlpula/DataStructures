/*
 * LongSubSeqUsingDP.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<string.h>

int LCS[100][100];
int max(int a, int b){
	return a >= b ? a : b;
}
int main(){
	char B[] = "ABCBDAB";
		char A[] = "BDCABA";
		int l1 = strlen(A);
		int l2 = strlen(B);
		printf("\n l1 %d and l2 %d \n", l1, l2);
		for(int i=0; i<=l1; i++)
			for(int j=0; j<=l2;j++)
				LCS[i][j] = 0;
		//Building LCS table.. Bottom up approach.
		for(int i = 0; i < l1; i++){
			for(int j = 0; j < l2; j++){
				if(A[i] == B[j]){
					LCS[i+1][j+1] = 1 + LCS[i][j];
					//break;
				}
				else
					LCS[i+1][j+1] = max(LCS[i+1][j], LCS[i][j+1]);
			}
		}
		printf("LCS \n");
		for(int i = 0; i <= l1; i++){
			for(int j = 0; j <= l2; j++){
				printf("%d ", LCS[i][j]);
			}
			printf("\n");
		}
		printf("\n Longest common subseq is %d\n", LCS[l1][l2]);


}
