/*
 * StackReverse.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: chandra.shekhar
 */
//Reverse Stack elements using only push and pop operations.

#include<stdio.h>
#include<stdlib.h>

int cnt= 0;
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

void InsertAtBottom(Stack &s, int data){
	if(s.isStackEmpty()){
		s.Push(data);
		cnt++;
		return;
	}
	int tmp = s.Pop();
	cnt++;
	InsertAtBottom(s, data);
	s.Push(tmp);
}
void ReverseStack(Stack &s){
	if(s.isStackEmpty())
		return;
	int data = s.Pop();
	ReverseStack(s);
	InsertAtBottom(s, data);
}
int main(){

	Stack s(10);
	s.Push(5);
	s.Push(4);
	s.Push(3);
	s.Push(2);
	s.Push(1);

	s.PrintStack();
	ReverseStack(s);
	s.PrintStack();
	//printf("\n Cnt %d \n", cnt);

}
