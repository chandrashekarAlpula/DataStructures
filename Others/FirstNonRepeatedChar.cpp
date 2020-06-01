/*
 * FirstNonRepeatedChar.cpp
 *
 *  Created on: Jul 30, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<string>

#define BUF 250;
using namespace std;

int Hash[255];

void FirstNonRepeatedChar(string &str){

	for(int i=0; i<str.size(); i++)
	{
		Hash[str[i]] += 1;
		//cout << endl << " Char " << str[i] << " Hash Val " << Hash[str[i]] <<endl ;
	}

	for(int i=0; i<str.size(); i++){
		if(Hash[str[i]] == 1){
			cout << endl << " First Non Repeating Char " << str << " Char " << str[i] <<endl ;
			return;
		}
	}
	cout << endl << "No repeated char found " << endl;
}

int main(){

	string str;
	cout << endl << "Enter input string  " << endl;
	cin >> str;
	cout << endl << " Input String " << str;
	FirstNonRepeatedChar(str);
	return 0;
}



