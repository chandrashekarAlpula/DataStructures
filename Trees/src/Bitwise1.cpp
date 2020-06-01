/*
 * Bitwise1.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
int main(){

	char input[19] = "4290212345677";
	//char input[16] = "4231";
	unsigned long long lngVal  = 0;
	char *ch = (char *)&lngVal;
	unsigned char ch1;

	int len = strlen(input);
	int i = 0;
	cout << endl;
	while(i < len ){
		*ch = ( (input[i] - '0') << 4) ;
		if(i+1  <  len)
			*ch |=  ( (input[i+1] - '0') );
		else
			*ch |= 0xF;


		printf("\n Ch char %0X str1 %c str2 %c", *ch, input[i], input[i+1]);
		i = i+2;
		ch++;
	}
	unsigned char *ch2 =  (unsigned char *)&lngVal;
	printf("\n Input String %s Long Value %llu\n", input, lngVal);
	for(int i =0; i< sizeof(unsigned long long); i++){
		printf("%02x\t", ch2[i]);
	}
	return 0;
}



