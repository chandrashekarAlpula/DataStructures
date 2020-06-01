/*
 * RemoveDupFromStr.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int cmp(char *str, int len, char e){
	for(int j=0;j<len;j++)
		if(str[j] == e)
			return 1;
	return 0;
}
int RemoveDuplicates(char *str){
	unsigned int ci = 0;
	int len = strlen(str);
	for(int i=0; i<len; i++){
		if(!cmp(str, ci, str[i])){
			str[ci++] = str[i];
		}
	}
	return ci;
}

int  RemoveDupWithHash(char *str){
	if(str == NULL)
	{
		cout << endl << "Empty String " << endl;
		return 0;
	}
	int hash[255];
	for(int i=0; i <255; i++){
		hash[i] = 0;
	}
	int m = 0;
	int len = strlen(str);
	for(int i=0; i<len; i++){
		if(!hash[(str[i])]){
			str[m++] = str[i];
			hash[(str[i])] = 1;
		}
	}
	cout << "Done with processing, len " << m ;
	//printf("\n Char A is  (%c) A ascii %d",12, 'A');
	return m;
}
int main(){

	char str[500];
	cout << endl << "Enter string " << endl;
	cin >> str;
	cout << endl << "Entered string is " << str << endl;
	int len = RemoveDupWithHash(str);
	str[len] = '\0';
	cout << endl << "After removing Duplicates " << str << endl;
	return 0;
}



