/*
 * RemoveAdjDupInStr.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: chandra.shekhar
 */
//Remove adjacent duplicates from a string.Ex careermonk ==> camonk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class Stack{
	char *arr;
	int top;
	int capacity ;
public:
	Stack(int size){
		capacity = size;
		top = -1;
		arr = (char  *)malloc(size * sizeof(char));
	}
	bool isStackFull(){
		return (top == (capacity -1));
	}
	bool isStackEmpty(){
		return top == -1;
	}
	void Push(char v){
		if(isStackFull()){
			printf("\n Stack is size %d", top + 1);
			return;
		}
		arr[++top] = v;
	}
	char Pop(){
		if(isStackEmpty()){
			printf("\n Stack is empty \n");
			return -1;
		}
		return arr[top--];
	}
	void PrintStack(){
		printf("\n");
		for(int i = top; i >= 0; i--)
			printf("%c", arr[i]);
	}
	int Top(){
		return arr[top];
	}
};

void RemoveDuplicates(char *s){
	Stack stk(100);
	int l = strlen(s);
	int i = l - 1;
	while(i >= 0){
		//printf("\nc %c", s[i]);
		if(stk.isStackEmpty()){
			stk.Push(s[i]);
		}else{
			if(stk.Top() == s[i])
				stk.Pop();
			else
				stk.Push(s[i]);
		}
		i--;
		//stk.PrintStack();
	}
	stk.PrintStack();
}
int main(){

	char s[] = "mississippi";
	RemoveDuplicates(s);
}



