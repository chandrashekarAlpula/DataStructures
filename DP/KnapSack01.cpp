/*
 * KnapSack01.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<stdlib.h>

int maxWeight = 0;
int **KNP;
void PrintMatrix(int **maxA, int n){
	for(int i = 0; i <= n; i++){
			printf("\n");
			for(int j = 0; j <= maxWeight; j++)
				printf("%d ",maxA[i][j]);
			printf("\n");
	}
}
int max(int a, int b){
	return a >= b ? a : b;
}

int KnapSack(int wt[], int W, int Val[], int n){
	int K[n+1][W+1];
	for(int i = 0; i <= n; i++){
		for(int w = 0; w <= W; w++){
			if(i == 0 || w == 0)
				K[i][w] = 0;
			else if( wt[i-1] <= w)
				K[i][w] = max(Val[i-1] + K[i-1][w - wt[i-1]],  K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
	return K[n][W];
}
int main(){

	int weights[] = {2,3,4,5};
	int benifits[] = {3,4,5,6};
	//int weights[] =  {10, 20, 30};
	//int benifits[] = {60, 100, 120};
	int n = sizeof(weights)/sizeof(weights[0]);
	maxWeight = 5;
	KNP = (int **)malloc(sizeof(int *) * (n+1));
	for(int i =0; i<= n; i++)
		KNP[i] = (int *)malloc(sizeof(int)*(maxWeight+1));
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= maxWeight; j++)
			KNP[i][j] = 0;
	//PrintMatrix(KNP, n);
	/*for(int i = 1; i <=n; i++){
		for(int wt = 1; wt <= maxWeight; wt++){
			if(weights[i-1] <= wt)
				KNP[i][wt] = max(KNP[i][wt - weights[i-1]] + benifits[i-1],
									KNP[i-1][wt]);
			else
				KNP[i][wt] = KNP[i-1][wt];
			//printf("\n i(%d) j(%d) (%d, %d)  %d %d \n ", i , wt, weights[i-1], benifits[i-1], KNP[i-1][wt], KNP[i][wt]);
		}
	}*/
	//PrintMatrix(KNP, n);
	int maxVal = KnapSack(weights, maxWeight, benifits, n);
	printf("\n Max Value is %d\n", maxVal);


}



