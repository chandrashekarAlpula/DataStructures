/*
 * Anargams2.cpp
 *
 *  Created on: Jul 29, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

#define BUFF 500

static int bits[BUFF];
void PrintAnargams(char *str, char *dest, int idx, int len){

	if(idx == len){
		cout << " Str " << dest << endl;
		return;
	}
	for(int i=0; i<len; i++){
		if(bits[i])
			continue;

		bits[i] = 1;
		dest[idx] = str[i];
		PrintAnargams(str,dest,idx+1, len);
		bits[i] = 0;

	}

}
int main(){

	char str[BUFF];
	cout << endl << "Enter the string " << endl ;
	cin >> str;
	cout << endl << "Entered string is " << str << endl ;
	char tmp[BUFF];
	memset(tmp,'\0', BUFF);
	PrintAnargams(str,tmp, 0,strlen(str));

	return 0;
}



