/*
 * CyclicList.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>

using namespace std;
struct Node {
	int data;
	Node *next;

	Node(int value){
		data  = value;
		next = NULL;
	}
};
void InsertNode(Node **head, int data){
	Node *newNode = new Node(data);
	newNode->next = NULL;
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node *tmpNode = *head;
	while(tmpNode->next != NULL){
		tmpNode = tmpNode->next;
	}
	tmpNode->next = newNode;
}

void PrintList(Node *head){

	cout << endl;
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

bool FindCycleInList(Node *head){

	Node *f, *l;
	l =  head;
	f = head->next;
	while(f != NULL){
		printf("F data %d", f->data);
		if(f->data == l->data){
			printf("\n Cycle found at value %d\n",l->data);
			break;
		}
		f = f->next;
		if(f != NULL)
			f = f->next;
		l = l->next;

	}



}

int main(){
	Node *head = NULL;
	InsertNode(&head, 1);
	InsertNode(&head, 2);
	InsertNode(&head, 8);
	InsertNode(&head, 10);
	InsertNode(&head, 95);
	InsertNode(&head, 16);

	PrintList(head);
	int loopPos = 5;
	//Make Loop
	Node *n = head;
	Node *n1 = NULL;
	int i = 1;
	while(n != NULL){
		printf("\n HERE");
		if(loopPos == i++){
			n1 = n;
			break;
		}
		n = n->next;
	}
	if(n != NULL)
		n->next = n1;
	FindCycleInList(head);
	return 0;
}
