/*
 * InterLeavingStrs.cpp
 *
 *  Created on: Jul 29, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

#define BUFF 25

void InterLeaveStrs(char *s1, char *s2, int n, int m, char *dest, int destIdx){

	if(n == strlen(s1) && m == strlen(s2) ){
		cout << "String is " << dest << endl ;
		return;
	}
	if(n < strlen(s1)){
		dest[destIdx] = s1[n];
		InterLeaveStrs(s1,s2,n+1, m,dest, destIdx+1);
	}
	if(m < strlen(s2)){
		dest[destIdx] = s2[m];
		InterLeaveStrs(s1,s2,n, m+1,dest, destIdx+1);
	}

}
int main(){

	char s1[BUFF];
	char s2[BUFF];

	cout << endl <<  "Enter String 1 " << endl ;
	cin >> s1;
	cout << "Enter String 2" << endl;
	cin >> s2;
	char dest[BUFF];
	memset(dest, '\0', BUFF);
	InterLeaveStrs(s1,s2,0,0,dest,0);



	return 0;
}



