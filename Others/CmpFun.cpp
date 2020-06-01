/*
 * CmpFun.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: chandra.shekhar
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>

int main()
{
	char s1[] = "786";
	char s2[] = "262966";
	int ret = atoi(s1) - atoi(s2);
	printf("\n S1 %s, S2 %s, ret %d \n", s1,s2,ret);

	return  0;
}


