#include<iostream>
using namespace std;

struct List{
	int data;
	List *next;
	List(int val){
		data = val;
		next = NULL;
	}
};

void PrintList(List *head){
	cout << "Printing  list" << endl;
	while(head){
		cout << head->data << "  ";
		head = head->next;
	}
	cout << endl ;
}


void InsertNode(List **head, int data){
	List *newNode = new List(data);
	if(*head == NULL){
		*head = newNode;
		return;
	}

	List *node = *head;
	while(node->next)
		node = node->next;

	node->next = newNode;
	return;
}

void SwapNodesInList(List **head, int x, int y){
	if(*head == NULL || x == y){
		cout << "List is empty " << endl;
		return;
	}
	List *nodeX = *head;
	List *nodeY = *head;
	List  *prevX = *head;
	List *prevY = *head;

	while(nodeX && nodeX->data != x){
		prevX = nodeX;
		nodeX = nodeX->next;
	}
	while(nodeY && nodeY->data != y){
		prevY = nodeY;
		nodeY = nodeY->next;
	}
	if(nodeX == nodeY){
		cout << endl <<"Cant swap since the nodes are same ";
		return;
	}
	if(nodeX == NULL | nodeY == NULL){
		cout << endl << "Failed to swap the nodes";
		return;
	}
	List *node = nodeY->next;
	prevX->next = nodeY;
	nodeY->next = nodeX->next;

	prevY->next = nodeX;
	nodeX->next = node;

}
int main(){
	List *head = NULL;
	for(int i = 1; i <= 10; i++)
		InsertNode(&head, i);
	PrintList(head);
	SwapNodesInList(&head, 1, 2);
	PrintList(head);
	return 0;
}
