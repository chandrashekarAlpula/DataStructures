/*
 * Queue.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: chandra.shekhar
 */
#include "../../DS/Queues/includes/Queue.h"

DoubleEndedQueue::Queue(int val){
	front = 0;
	rear = -1;
	capacity = val;
	Size = 0;

	QueueData = (int *)malloc(sizeof(int)*capacity) ;
	for(int i=0;i<capacity; i++)
		QueueData[i] = -1;
}

bool DoubleEndedQueue::EnQueue(int data){
	if(QueueData == NULL){
		std::cout << std::endl << "Data Structure not initialized "  << std::endl;
		return false;
	}
	if(isFull())
	{
		std::cout << std::endl << "Queue is Full " << std::endl;
		return false;
	}
	QueueData[(++rear%capacity)] = data;
	Size++;
}

bool DoubleEndedQueue::DeQueue(int &data){
	if(isEmpty()){
		std::cout << std::endl << "DQueue is empty "  << std::endl;
		return false;
	}
	data = QueueData[front];
	QueueData[(front++)] = -1;
	printf("\n Front is %d size is %d \n", front, capacity);
	front = front%capacity;
	Size--;
}
