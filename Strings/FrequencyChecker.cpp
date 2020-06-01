#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int GetIdx(char c){
    return c -'a';
}

bool isFreqMet(int M[]){

    int same = 0;
    for(int i = 0; i < 26; i++){
        if(M[i] == 0)
            continue;

        if(same == 0)
            same = M[i];
        else{
            if(same != M[i]){
                return false;
            }
        }
    }
    return true;
}

bool CheckTheFreqOfChars(char *str){

    int M[26] = {0};
    int len = strlen(str);

    for(int i = 0; i < len; i++)
        M[GetIdx(str[i])]++;

    if(isFreqMet(M))
        return true;
    for(int i = 0; i< 26; i++){
        if(M[i] == 0)
            continue;
        M[i]--;
        if(isFreqMet(M))
            return true;
        M[i]++;
    }
    return false;
}
int main(){

    char str[] = "abcdefgh";

   // printf("\n Enter the input string(only alphabets smaller \n");
    //scanf("%s", str);

    bool ret = CheckTheFreqOfChars(str);
    if(ret)
        printf("\nYes");
    else
        printf("\nNo");
}
