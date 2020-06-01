/*
 * MaxSlidingWindowSum.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct List{
	int d;
	List *next;
	List *prev;

	List(int v){
		d = v;
		next = prev = NULL;
	}
};
class DoubleEndedQueue{
	List* front;
	List* rear;
	//List *arr;
	int size;
public:
	DoubleEndedQueue(){
		size = 0;
		front = rear = NULL;
	}
	int PushFront(int v){
		List *n = new List(v);
		if(size == 0){
			front = rear = n;
		}else{
			n->next = front;
			front->prev = n;
			front = n;
		}
		size++;
	}
	int PushBack(int v){
		List *n = new List(v);
		if(size == 0)
			front = rear = n;
		else{
			rear->next = n;
			n->prev = rear;
			rear = n;
		}
		size++;

	}
	bool IsQueueEmpty(){
		return size == 0;
	}
	int PopFront(){
		if(IsQueueEmpty()){
			printf("\n Queue is empty cannot pop\n");
			return -1;
		}
		List *n = front;
		front = front ->next;
		int v = n->d;
		delete(n);
		size--;
		return v;
	}
	int PopBack(){
		if(IsQueueEmpty()){
			printf("\n Queue is empty cannot pop\n");
			return -1;
		}
		List *n = rear;
		int v = rear->d;

		if(!rear->prev)
			rear->prev = NULL;
		rear = rear->prev;
		size--;
		return v;
	}

	int Front(){
		if(IsQueueEmpty()){
			printf("\n Queue is empty cannot pop\n");
			return -1;
		}
		return front->d;
	}
	int Back(){
		if(IsQueueEmpty()){
			printf("\n Queue is empty cannot pop\n");
			return -1;
		}
		return rear->d;
	}


};

void MaxSlidingWindow(int A[], int n, int w, int B[]){
	DoubleEndedQueue Q;
	for(int i = 0; i < w; i++){ //Pust first window size elements in to queue
		while(!Q.IsQueueEmpty() && A[i] >= A[Q.Back()])
			Q.PopBack();
		Q.PushBack(i);
	}
	for(int i = w; i < n; i++){
		B[i -w] = A[Q.Front()];

		while(!Q.IsQueueEmpty() && A[i] >= A[Q.Back()])
			Q.PopBack();
		while(!Q.IsQueueEmpty() && Q.Front() <= i -w)
			Q.PopFront();
		Q.PushBack(i);

	}
	B[n-w] = A[Q.PopFront()];
}

int main(){

	int A[] = {1,3,-1,-3,5,3,6,7};
	int n = sizeof(A)/sizeof(A[0]);
	int B[n];
	for(int i = 0; i < n; i++)
		B[i] = 0X0FFFFFFF;
	int window = 3;
	MaxSlidingWindow(A, n, window, B);
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d, ", B[i]);
	printf("\n");
	return 0;
}

