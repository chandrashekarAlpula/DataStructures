#include <iostream>
using namespace std;

struct List{
    int data;
    List *next;
};
void InsertNode(List **head, int data){
    List *newNode = new List();
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return ;
    }
    List *node = *head;
    while(node->next)
        node = node->next;
    node->next = newNode;

}
void DeleteElementByValue(List **head, int data){
    if(*head == NULL){
        cout << "List is empty, cannot delete the element  " << data << endl;
        return;
    }
    List *node = *head;
    if((*head)->data == data){
        *head = node->next;
        cout << "Deleted the node with value " << node->data << endl;
        delete node;
        return;
    }
    List *prevNode = node;
    while(node){
        if(node->data == data){
            prevNode->next = node->next;
            cout << "Deleted the node with value " << node->data << endl;
            delete node;
            return;
        }
        prevNode = node;
        node = node->next;
    }
    cout << "Failed to delete the node with value " << data << endl ;
}
void DeleteNodeByIndex(List **head, int idx){
    List *node = *head;
    if(idx == 0){
        *head = node->next;
        cout << "Deleted the node at index "<< idx << " and value " << node->data << endl;
        delete node;
        return;
    }
    int i = 0;
    while(i < idx-1 && node){
        node = node->next;
    }
    if(node == NULL || node->next == NULL){
        cout << "Failed to delete the node at index " << idx << endl;
        return;
    }
    List *tmpNode = node->next;
    node->next = tmpNode->next;
     cout << "Deleted the node at index "<< idx << " and value " << tmpNode->data << endl;
    delete tmpNode;
}
void PrintList(List *head){
    cout << "Printing list" << endl ;
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl ;
}
int main() {
	//code
	List *head = NULL;
	for(int i = 1; i <= 10; i++)
	    InsertNode(&head, i);

	PrintList(head);
	DeleteElementByValue(&head, 5);
	DeleteNodeByIndex(&head, 1);
	DeleteElementByValue(&head, 10);
	DeleteNodeByIndex(&head, 10);
	DeleteNodeByIndex(&head, 0);
	PrintList(head);
	return 0;
}
