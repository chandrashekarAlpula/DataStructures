/*
 * LongestCommonSubsequence.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int LCS[100][100];
	string s1;
	string s2;
	cout << endl << "Here " << endl;
	cin >> s1;
	cout << endl << "Here1 " << endl;
	cin >> s2;
	string s3 ;
	int l1 = s1.size();
	int l2 = s2.size();
	for(int i = 0; i <= l1; i++)
		for(int j = 0; j <= l2; j++)
			LCS[i][j] = 0;

	for(int i = 0; i < l1; i++){
		for(int j = 0; j < l2; j++){
			if(s1[i] == s2[j]){
				LCS[i+1][j+1] = 1 + LCS[i][j];
				s3 += s1[i];
			}else{
				LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
			}
		}
	}
	int len = LCS[l1][l2];
	cout << endl << "Longest Common Subsequence " << len << " and the string is " << s3 << endl;
	return 0;
}



