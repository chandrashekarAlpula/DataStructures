/*
 * Anargams1.cpp
 *
 *  Created on: Jul 26, 2016
 *      Author: chandra.shekhar
 */

#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
char HashCode[10][5] = {"","","abc","def","ghi","jkl","mno",
    "pqrs","tuv","wxyz"};

void PrintPossibleValues(char *inputStr, char*outPutStr, unsigned int curCharIdx, unsigned int len){
    //printf(" Str %s Cur Idx %u Str Len %u \t", inputStr, curCharIdx, len);
   if(curCharIdx == len) {
      // printf(" Str %s Cur Idx %u Str Len %u \t", outPutStr, curCharIdx, len);
       printf("%s \t", outPutStr);
       return;
   }
   unsigned int hashLen = strlen(HashCode[(inputStr[curCharIdx] - '0')]);
   //printf("\n Hash value len %u \n", hashLen);
   for(int i=0; i<hashLen; i++){
       //cout << "HERE 123 " << endl ;
       outPutStr[curCharIdx] = HashCode[inputStr[curCharIdx] - '0'][i];
       PrintPossibleValues(inputStr, outPutStr,curCharIdx+1,  len);

   }
}
int main() {
	//code
	char inStr[10] = "234";
	char otStr[10];
	memset(otStr,'\0',10);
	cout << endl  << "Input String " << inStr << endl;
	unsigned int len = strlen(inStr);
	PrintPossibleValues(inStr, otStr,0,len);
	return 0;
}


