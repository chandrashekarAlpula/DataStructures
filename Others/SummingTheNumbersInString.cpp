/*
 * SummingTheNumbersInString.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: chandra.shekhar
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main(){

	//char str[1024] = "aa120bb200cc300dd";
	char str[1024] ;
	int sum =0;
	int tempSum = 0;

	printf("\n Enter the input string \n");
	scanf("%s",str);
	int len = strlen(str);
	for(int i=0; i<len; i++){
		if(str[i] >= '0' &&  str[i] <= '9'){
			tempSum = (str[i] - '0') + (tempSum * 10) ;
			//cout << endl << "Sum value is " << tempSum << " Char is " << str[i];
		}else{
			sum += tempSum;
			tempSum = 0;
			//cout << endl << " No Sum value is " << sum << " Char is " << str[i];
		}
	}
	sum += tempSum;
	int tmp = pow(10, 2);
	cout << endl << "Original String " << str << " Tmp Value " << tmp;
	cout << endl << "Sum value is " << sum << endl;
	return 0;
}



