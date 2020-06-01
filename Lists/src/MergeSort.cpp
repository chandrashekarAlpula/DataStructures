/*
 * MergeSort.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: chandra.shekhar
 */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#include "../../DS/Lists/include/ListWraper.h"

using namespace std;

void BisectList(List *head, List **l1, List **l2){


	//printf("\n HERE \n");
	//PrintList(head);
	if(head == NULL || head->next == NULL) // Single node
	{
		*l1 = head;
		*l2 = NULL;
		return;
	}
	List *slowPtr = head, *fastPtr = head->next;
	while(fastPtr != NULL ){
		fastPtr = fastPtr->next;
		if(fastPtr != NULL){
			fastPtr = fastPtr-> next;
			slowPtr = slowPtr->next;
		}
	}
	*l1 = head;
	*l2 = slowPtr->next;
	slowPtr->next = NULL;

//	exit(0);

}

List *SortListRecur(List *l1, List *l2){
	List *list = NULL;
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;

	if(l1->data <= l2->data)
	{	list = l1;
		list->next = SortListRecur(l1->next, l2);
	}else{
		list = l2;
		list->next = SortListRecur(l1, l2->next);
	}

	return list;
}

List *SortListIterative(List *l1, List *l2){
	List *list;
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;

	if(l1->data <= l2->data)
	{
		list = l1;
		l1 = l1->next;
	}else{
		list = l2;
		l2 = l2->next;
	}
	List *head = list;
	while(l1 != NULL && l2 != NULL){
		if(l1->data <= l2->data){
			list->next = l1;
			l1 = l1->next;
		}else {
			list->next = l2;
			l2 = l2->next;
		}

		list = list->next;
	}
	if(l1 != NULL)
		list->next = l1;
	else if(l2 != NULL)
		list->next = l2;

	return head;
}
void MergeSort(List **head){

	static int cnt = 0;
	List *tmpHead = *head;
	if(tmpHead == NULL || tmpHead->next == NULL)
		return;

	List *l1, *l2;
	BisectList(tmpHead, &l1, &l2);
	MergeSort(&l1);
	MergeSort(&l2);
	/*printf("\n ++++++++++++ \n");
	printf("\n l1 \n");
	PrintList(l1);
	printf("\n l2 \n");
	PrintList(l2);*/

	//*head = SortListRecur(l1, l2);
	*head = SortListIterative(l1, l2);
	/*printf("\n l1 \n");
	PrintList(l1);
	printf("\n l2 \n");
	PrintList(l2);
	printf("\n Head \n");
	PrintList(*head);
	printf("\n ================= \n");*/

	//PrintList(*head);
	//if(cnt++ == 2)
		//exit(0);
}

int main(){

	List *head = NULL;
		InserNode(&head, 100);
		InserNode(&head, 20);
		InserNode(&head, 40);
		InserNode(&head, 60);
		InserNode(&head, 80);

		InserNode(&head, 30);
		InserNode(&head, 50);
		InserNode(&head, 22);
		InserNode(&head, 17);
		InserNode(&head, 118);
		InserNode(&head, 9);


		cout << endl << "List One" << endl ;
		PrintList(head);
		cout << endl ;
		MergeSort(&head);
		cout << endl << "List One" << endl ;
		PrintList(head);

}



