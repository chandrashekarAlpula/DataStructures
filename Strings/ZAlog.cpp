/*
 * ZAlog.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<iostream>
#include<string>

#define MAX  100
using namespace std;

unsigned int Z[MAX];

void PatternBuild(std::string &T, int n){
	Z[0] = 0;
	unsigned int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i && T[i+j] == T[j]; j++){
			cnt++;
		}
		Z[i]  = cnt;
		cnt = 0;
	}
}


int main(){
	std::string str = "aabxaayaab";
	int len = str.length();
	PatternBuild(str, len);
	for(int i =0 ; i < len; i++)
		printf("%d ", Z[i]);
	printf("\n");
	return 0;
}



