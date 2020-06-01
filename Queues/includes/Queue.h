/*
 * Queue.h
 *
 *  Created on: Nov 4, 2016
 *      Author: chandra.shekhar
 */

#ifndef DS_QUEUES_INCLUDES_QUEUE_H_
#define DS_QUEUES_INCLUDES_QUEUE_H_

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class DoubleEndedQueue{

	int front;
	int rear;
	int capacity;
	int Size;
	int *QueueData;

public:
	Queue(int val);

	bool EnQueue(int data);
	bool DeQueue(int &data);
	bool isEmpty(){
		return (Size == 0);
	}
	bool isFull(){
		return (Size == capacity);
	}
	void PrintQueue(){
		printf("\n ");
		for(int i=0; i<capacity; i++)
			printf("%d \t", QueueData[i]);
		printf("\n ");
	}
};



#endif /* DS_QUEUES_INCLUDES_QUEUE_H_ */
