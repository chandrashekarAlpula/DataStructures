/*
 * WildCardPatternMatchWithDP.cpp
 *
 *  Created on: Dec 13, 2016
 *      Author: chandra.shekhar
 */

/*Wild card pattern matching with Dynamic Programming. */

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>

#define COL 20
using namespace std;

void PrintMat(int Tlen, int Plen, bool matrix[][COL]){
	printf("\n");
		for(int i=0; i<Tlen; i++){
			for(int j=0; j<Plen; j++){
				printf("%d\t", matrix[i][j]);
			}
		}
		printf("\n");
}
bool PatternMatch(string T, string P){
	bool ret = false;
	int Tlen = T.length() +1 ;
	int Plen = P.length() + 1;
	bool matrix[Tlen][Plen];
	memset(matrix, false, (Tlen*Plen));
	printf("\n Tlen %d Plen %d\n ", Tlen, Plen);
	printf("\n Before pattern matching \n");
	for(int i=0; i<Tlen; i++){
		for(int j=0; j<Plen; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	matrix[0][0] = true;//Becase empty string matches with empty pattern.
	for(int i=1; i<Plen; i++)
		matrix[0][i] = false;
	for(int i=1; i<Tlen; i++)
		matrix[i][0] = false;


	for(int i=1;i<Tlen; i++){
		for(int j=1;j<Plen; j++){
			if(T[i-1] == P[j-1] || P[j-1] == '?'){
				matrix[i][j] = matrix[i-1][j-1];
			}else if(P[j-1] == '*'){
				matrix[i][j] = (matrix[i-1][j] | matrix[i][j-1]); // put either above true or before true
			}else{
				matrix[i][j] = false;
			}
		}
	}
	printf("\n After pattern matching \n");
	for(int i=0; i<Tlen; i++){
		for(int j=0; j<Plen; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return ret;

}
int main(){
	string T = "xaylmz";
	string P = "x?y*z";
	if(PatternMatch(T, P)){

	}

}
