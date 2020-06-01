/*
 * charGrpOccur.cpp
 *
 *  Created on: Dec 11, 2016
 *      Author: chandra.shekhar
 */
/* Char group occurences in a string*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string.h>

using namespace std;

int CharHash[26];


int main(){

	string str;
	cout << "Enter input string " << endl;
	cin >> str;
	cout << endl << "Entered string " << str << endl ;
	memset(CharHash,0 , 26);
	int len = str.length();
	for(int i=0; i < len; i++){
		if(str[i] < 'a' || str[i] > 'z'){
			cout << endl << "Invalid string " << endl ;
			return 0;
		}
		CharHash[(str[i]-'a')]++;
	}
	cout << endl << "Char Hash " << endl ;
	for(int i =0; i< 26; i++){
		cout << CharHash[i] << " ";
	}
	// Second loop to print the string in order
	cout << endl << "Printing the string in order"  << endl ;
	for(int i = 0; i<len; i++){
		//cout << "Cur char " << str[i] << " count " << CharHash[str[i]-'a'] << endl;
		for(int j=1; j <= CharHash[str[i]-'a']; j++){
			cout << str[i];
		}
		CharHash[str[i]-'a'] = 0;
	}
	return 0;
}


