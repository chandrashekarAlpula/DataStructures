/*
 * QueueSample.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: chandra.shekhar
 */
#include "../../DS/Queues/includes/Queue.h"

using namespace std;

int main(){

	class DoubleEndedQueue Q(4);
	int pop  = 0;
	Q.EnQueue(10);
	Q.EnQueue(20);
	Q.EnQueue(30);
	Q.EnQueue(40);
	Q.DeQueue(pop);
	printf("\n Poped Item is %d\n", pop);
	//Q.EnQueue(50);
	Q.DeQueue(pop);
	printf("\n Poped Item is %d\n", pop);
	Q.DeQueue(pop);
	printf("\n Poped Item is %d\n", pop);
	Q.DeQueue(pop);
	printf("\n Poped Item is %d\n", pop);

	//Q.DeQueue(pop);
	Q.EnQueue(50);
	//Q.DeQueue(pop);
	//printf("\n Poped Item is %d\n", pop);
	Q.EnQueue(10);
	Q.PrintQueue();


}



