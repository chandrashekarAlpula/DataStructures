/*
 * patterNaive.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

void PatternSearchNaiveOld(string &T, string &P){
	int len = T.length();
	int pLen = P.length();
	int j = 0, i = 0;
	cout << endl << "Text Len " << len << endl;
	for(; i < len-pLen; i++){
		//cout << endl << "I char is " << T[i] ;
		for(j =0; j<pLen; j++){
			if(T[i+j] == P[j]){
				j++;
			}
			else{
				//cout << endl << "HERE ";
				break;
			}
		}

		if(j == pLen){
			break;
		}
	}
	cout << endl << "PLen is " << pLen << " J is " << j << endl;
	if(j == pLen){
		cout << endl << "Found the Pattern at the index "<< i << endl;
		return;
	}else{
		cout << endl << "No string found in Text " <<  i << endl;
	}
}

void PatternSearchNaive(string &T, string &P){
	int len = T.length();
	int pLen = P.length();
	int i = 0, j = 0;
	cout << endl << "Text Len " << len << endl;
	while(i < len - pLen+1){
		if(T[i+j] == P[j]){
			printf("\n i %d j %d Text ", i, j);
			cout << T[i+j] << endl;
			if(++j == pLen){
				break;
			}
		}else{
			i++;
			j=0;
		}
	}
	cout << endl << "PLen is " << pLen << " J is " << j << endl;
	if(j == pLen){
		cout << endl << "Found the Pattern at the index "<< i << endl;
		return;
	}else{
		cout << endl << "No string found in Text " <<  i << endl;
	}
}

int main(){
	string text = "THIS IS A TEST TEXT";
	string pattern = "TEXT";

	PatternSearchNaive(text, pattern);
}



