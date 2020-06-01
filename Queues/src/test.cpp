/*
 * test.cpp
 *
 *  Created on: Feb 11, 2019
 *      Author: chandra.shekhar
 */

#include<stdio.h>
#include<iostream>

using namespace std;

struct Queue{
	int cap;
	int rear, front;
	int *array;

};

void CreatQueue(Queue **Q1, int cap){
	*Q1 = new Queue();
	Queue *Q = *Q1;
	Q->cap = cap;
	Q->array = new int[cap];
	Q->front = Q->rear = -1;
}

bool IsQueueFull(Queue *Q){
	return (Q->front == (Q->rear+1)%Q->cap);
}

bool IsQueueEmpty(Queue *Q){
	return (Q->front == -1);
}

void Enqueue(Queue *Q, int val){
	if(IsQueueFull(Q)){
		cout << endl << "Q is full" << endl;
		return;
	}
	Q->rear = (Q->rear+1)%Q->cap;
	Q->array[Q->rear] = val;
	if(Q->front == -1)
		Q->front = Q->rear;
}

int DeQueue(Queue *Q){
	if(IsQueueEmpty(Q)){
		cout << endl << "Queue is empty" << endl;
		return -1;
	}
	int data = Q->array[Q->front];
	if(Q->front == Q->rear)
		Q->front = Q->rear = -1;
	else
		Q->front = (Q->front+1)%Q->cap;
	return data;
}

void PrintQueue(Queue *Q){
	cout << endl;
	for(int i = Q->front; i <= Q->rear; i++)
		cout << Q->array[i] << " ";
	cout << endl;
}

int main(){

	Queue *Q = NULL;
	int d = -1;
	CreatQueue(&Q, 5);
	Enqueue(Q, 1);
	Enqueue(Q, 2);
	Enqueue(Q, 3);
	Enqueue(Q, 4);
	Enqueue(Q, 5);
	d = DeQueue(Q);
	cout << endl << "DeQUeue " << d << endl;
	Enqueue(Q, 6);
	Enqueue(Q, 7);
	PrintQueue(Q);

	return 0 ;
}
