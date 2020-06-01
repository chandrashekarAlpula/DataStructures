#include<stdio.h>
#include<iostream>

#include "../../DS/Lists/include/ListWraper.h"


using namespace std;



List *MergeLists(List *list1, List *list2){

	if(list1 == NULL && list2 == NULL)
		return NULL;

	if(list1 == NULL && list2 != NULL)
		return list2;

	if(list1 != NULL && list2 == NULL )
		return list1;

	List *list = NULL;
	if(list1->data <= list2->data){
		list = list1;
		list1 = list1->next;
	}else {
		list = list2;
		list2 = list2->next;
	}

	List *head = list;
	//Merge the nodes in to List1;
	while(list1  != NULL && list2 != NULL ){
		if(list1->data <= list2->data){
			list->next = list1;
			list1 = list1->next;
		}else{
			list->next = list2;
			list2 = list2->next;
		}
		list = list->next;
	}

	if(list1 != NULL){
		list->next = list1;
	}
	else if(list2 != NULL){
		list->next = list2;
	}
	return head;
}

int main(){

	List *head = NULL;
	InserNode(&head, 1);
	InserNode(&head, 20);
	InserNode(&head, 40);
	InserNode(&head, 60);
	InserNode(&head, 80);
	InserNode(&head, 100);



	List *head2 = NULL;
	InserNode(&head2, 10);
	InserNode(&head2, 15);
	InserNode(&head2, 17);
	InserNode(&head2, 18);
	InserNode(&head2, 19);


	cout << endl << "List One" << endl ;
	PrintList(head);

	cout << endl << "List Two" << endl ;
	PrintList(head2);

	List *list = MergeLists(head, head2);
	cout << endl << "Merged List " << endl ;
	PrintList(list);

	DeleteNodeOnValue(&list, 15);
	DeleteNodeOnValue(&list, 100);
	DeleteNodeOnValue(&list, 90);
	cout << endl << "After Deleting " << endl ;
	PrintList(list);
}
