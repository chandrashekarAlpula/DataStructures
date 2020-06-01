/*
 * EncryptDcryptXOR.cpp
 *
 *  Created on: Dec 12, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

void EncrriptDecript(string &str){

	int len = str.length();
	char xorKey1 = 'K';
	char xorKey2 = 'd';

	for(int i=0; i<len; i++){
		str[i] = str[i] ^ xorKey1;
		str[i] = str[i] ^ xorKey2;
	}
}

int main(){

	string str = "Chandra";
	cout << endl << "Original string " << str << endl ;
	EncrriptDecript(str);
	cout << endl << "string After encription  " << str << endl ;
	EncrriptDecript(str);
	cout << endl << "string After decription  " << str << endl ;

	return 0;

}



