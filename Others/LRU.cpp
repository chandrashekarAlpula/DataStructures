/*
 * LRU.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: chandra.shekhar
 */
#include <stdio.h>
#include<iostream>
#include<stdlib.h>


struct QNode{
	int page;
	QNode *next;
	QNode *prv;
};


class Hash{
	QNode **arrNodes;// Array of Queue nodes.
	int capacity;

public:
	Hash(int size){
		arrNodes = (QNode **)malloc(sizeof(QNode *) * size);
		for(int i = 0; i < size; i++)
			arrNodes[i] = NULL;

		capacity = size;
	}
	QNode *GetNode(int page){
		return arrNodes[page];
	}
	void AddNode(QNode *node, int page){
		arrNodes[page] = node;
	}
	void DeleteNode(int page){
		arrNodes[page] = NULL;
	}

};

class LRUCache{
private:
	Hash *hash;
	QNode *front;
	QNode *rear;
	int capacity;
	int numOfPages;
public :
	LRUCache(int size, Hash *h){
		//hash = new Hash(size);
		capacity = size;
		numOfPages = 0;
		hash = h;
	}

	void ReferPage(int page){
		//If page does not exists.
		QNode *node = hash->GetNode(page);
		if(node == NULL ){
			node = CreateNode(page);
			printf("\n Adding page %d\n", page);
			Enqueue(node);
		}else{
		// If page exists, delete the node from the existing loc and add it to the front;
			node = Dequeu(node);
			Enqueue(node);
		}

	}

	void PrintQueue(){
		QNode *node = front;
		while(node != NULL){
			printf("%d ", node->page);
			node = node->next;
		}
		printf("\n PrintQueue num pages %d\n", numOfPages);
		//printf("\n");
	}
private :
	QNode *CreateNode(int page){
		QNode *node = (QNode *)malloc(sizeof(QNode));
		node->prv = node->next = NULL;
		node->page = page;
		return node;
	}
	bool IsQueueEmpty(){
		return front == NULL;
	}
	bool isQueueFull(){
		return numOfPages == capacity;
	}
	void Enqueue(QNode *node){
		if(node == NULL ){
			printf("\n Node is NULL ");
			return ;
		}
		if(IsQueueEmpty()){
			printf("\n Queue is Empty\n");
			front = node;
			rear = front;
			numOfPages++;
			hash->AddNode(front, node->page);
			return;
		}
		if(isQueueFull()){ //If Q is full delete the rear and add this to front
			rear = Dequeu(rear);
			printf("\n Queue full num pages %d\n", numOfPages);
			hash->DeleteNode(rear->page);
			QNode *n = rear;
			rear = rear->prv;
			rear->next = n->prv;
			n->next->prv = rear;
			delete n;
		}
		numOfPages++;
		node->next = front;
		front->prv = node;
		front = node;
		hash->AddNode(node, node->page);

	}
	QNode *Dequeu(QNode *node){
		//QNode *node = hash->GetNode(page);
		if(node == NULL)
			return NULL;
		//TBD change the front and rear pointers if the the node to be deleted is either front or rear or both
		int page = node->page;
		QNode *prevNode = node->prv;
		prevNode->next = node->next;
		printf("\n DeQueue num pages %d\n", numOfPages);
		numOfPages--;
		return node;

	}

};

int main(){
	Hash *hash = new Hash(10);
	LRUCache *cac = new LRUCache(4, hash);
	cac->ReferPage(1);
	cac->ReferPage(2);
	cac->ReferPage(3);
	cac->ReferPage(4);
	cac->PrintQueue();
	cac->ReferPage(5);
	cac->PrintQueue();
	cac->ReferPage(2);
	cac->PrintQueue();
	return 0;

}


