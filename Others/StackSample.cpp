/*
 * StackSample.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class Stack{
	int *arr;
	int top;
	int capacity ;
public:
	Stack(int size){
		capacity = size;
		top = -1;
		arr = (int  *)malloc(size * sizeof(int));
	}
	bool isStackFull(){
		return (top == (capacity -1));
	}
	bool isStackEmpty(){
		return top == -1;
	}
	void Push(int v){
		if(isStackFull()){
			printf("\n Stack is size %d", top + 1);
			return;
		}
		arr[++top] = v;
	}
	int Pop(){
		if(isStackEmpty()){
			printf("\n Stack is empty \n");
			return -1;
		}
		return arr[top--];
	}
	void PrintStack(){
		printf("\n");
		for(int i = top; i >= 0; i--)
			printf("%d \t", arr[i]);
	}
	int GetMin(){
		return arr[top];
	}
};

void PushToStack(Stack &s, Stack &smin, int v){
	s.Push(v);
	int min = smin.GetMin();
	if(smin.isStackEmpty() || min >= v){
		smin.Push(v);
	}else
		smin.Push(min);
}

int PopFromStatck(Stack &s, Stack &smin){
	int v = s.Pop();
	if(v  != -1){
		smin.Pop();
	}
	return v;
}

int main(){
	Stack s(10);
	Stack minS(10);
	PushToStack(s, minS, 2);
	PushToStack(s, minS, 6);
	PushToStack(s, minS, 1);
	PushToStack(s, minS, 4);
	s.PrintStack();
	minS.PrintStack();
	PopFromStatck(s, minS);
	PopFromStatck(s, minS);
	printf("\n Min Value is %d \n", minS.GetMin());
	PushToStack(s, minS, 1);
	PushToStack(s, minS, 5);
	s.PrintStack();
	minS.PrintStack();
	return 0;
}



