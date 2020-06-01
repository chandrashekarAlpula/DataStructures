/*
 * CircularQueue.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: chandra.shekhar
 */

#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

class CQueue{
private:
	int *arr;
	int front;
	int rear;
	int capacity;
public:
	CQueue(int size){
		arr = (int *)malloc(sizeof(int) * size);
		for(int i = 0; i < size; i++)
			arr[i] = 0;
		front = rear = -1;
		capacity = size;
	}
	~CQueue(){
		//free arr[];
	}

	void Insert(int value){
		if(IsQueueFull()){
			printf("\n Queue is full, failed to insert data %d capacity %d", value, capacity);
			return;
		}
		rear = (++rear)%capacity;
		arr[rear] = value;
		if(front == -1)
			front = rear;
		printf("\n 1 Front %d rear %d  ", front, rear);
	}
	int Delete(){
		if(IsQueueEmpty()){
			printf("\n Queue is Empty ");
			return -1;
		}
		int ret=  arr[front++];
		if(front > rear){//This check needs to be checked
			front = rear = -1;
		}
		return ret;
	}
	void PrintQueue(){
		int x = front;
		if(x < 0)
			return;
		printf("\n Front %d rear %d", front, rear);
		do {
			printf("\n value is %d", arr[x % capacity]);
		}while(((x++)% capacity) != rear);
	}
private:
	bool IsQueueFull(){
		if(((rear + 1)% (capacity)) == front)
			return true;
		return false;
	}
	bool IsQueueEmpty(){
		return rear == -1;
	}
};
int main(){

	CQueue que = CQueue(4);
	int x = -1;
	que.Insert(1);
	que.Insert(2);
	que.Insert(3);
	que.Insert(4);
	que.PrintQueue();
	x = que.Delete();
	que.Insert(5);
	que.PrintQueue();
}


