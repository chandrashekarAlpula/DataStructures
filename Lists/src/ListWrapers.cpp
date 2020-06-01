#include<stdio.h>
#include<iostream>

#include "../../DS/Lists/include/ListWraper.h"

using namespace std;


void PrintList(List *head){
	while(head != NULL){
		printf("%d \t", head->data);
		head = head->next;
	}
}

void InserNode(List **head, int val){

	List *tmpHead = *head;
	List *node = new List(val);
	if(*head == NULL){
		*head = node;
		return;
	}
	int i = 1;
	while(tmpHead->next != NULL){
		tmpHead =  tmpHead->next;
	}
	tmpHead->next = node;
}

void DeleteNodeOnValue(List **head, int Val){

	if(*head == NULL){
		cout << endl << "Empty list" << endl;
		return;
	}
	List *node = *head;
	if((*head)->data == Val){
		*head = (*head)->next;
		delete node;
	}

	while(node->next != NULL){
		if(node->next->data == Val){
			List *tmpNode = node->next;
			node->next = tmpNode->next;
			delete tmpNode;
			return;
		}
		node = node->next;
	}
	cout << endl << "Value " << Val << " Not Found in the list " << endl;
}
