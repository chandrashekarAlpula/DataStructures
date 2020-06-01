#include <iostream>

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

void PrintNthNode(Node *head, int pos){
	Node *n1, *n2;
	n1 = n2 = head;
	int cnt = 0;

	while(n1 && pos != cnt++)
		n1 = n1->next;

	cout << endl << "N1 data " << n1->data << endl;
	if(n1 == NULL){
		cout << endl << "List size is less than the position returning" << endl;
		return;
	}
	while(n1 != NULL){
		n1 = n1->next;
		n2 = n2->next;

	}
	cout << endl << pos << " node from last is " << n2->data << endl;
	return;

}
int main(){

	Node *head = NULL;
	InsertNode(&head, 1);
	InsertNode(&head, 4);
	InsertNode(&head, 2);
	InsertNode(&head, 9);
	InsertNode(&head, 3);
	InsertNode(&head, 8);
	int inp;
	PrintList(head);
	cout << endl << "Enter the nth node :"  ;
	cin >> inp;
	cout << endl;
	PrintNthNode(head, inp);
	return 0;
}
