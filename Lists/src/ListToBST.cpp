#include<iostream>

using namespace std;

struct LNode{
	int d;
	LNode *next;

	LNode(int data){
		d = data;
		next = NULL;
	}
};

struct TNode{
	int d;
	TNode *left;
	TNode *right;

	TNode(int data){
		d = data;
		left = NULL;
		right = NULL;
	}
};

int CountNodes(LNode *head);

TNode *ConvertToBSTRec(LNode **head, int n){

	if(n <= 0)
		return NULL;

	TNode *left = ConvertToBSTRec(head, n/2);
	TNode *root = new TNode((*head)->d);
	*head = (*head)->next;
	root->left = left;
	root->right = ConvertToBSTRec(head, (n-n/2)-1);

	return root;

}

TNode *ConvertToBST(LNode **head){

	int numNodes = CountNodes(*head);
	return ConvertToBSTRec(head, numNodes);

}

//utility functions
void PrintList(LNode *head){
	cout << endl;
	while(head){
		cout << head->d <<  " ";
		head = head->next;
	}
	cout << endl;
}

int CountNodes(LNode *head){
	int cnt = 0;
	while(head){
		cnt++;
		head = head->next;
	}
	return cnt;
}

void PreOrder(TNode *root){
	if(root == NULL)
		return;

	cout << root->d << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InsertToList(LNode **head, int data){
	LNode *node = new LNode(data);
	node->next = *head;
	*head = node;
}


int main(){

	LNode *head = NULL;
	InsertToList(&head, 7);
	InsertToList(&head, 6);
	InsertToList(&head, 5);
	InsertToList(&head, 4);
	InsertToList(&head, 3);
	InsertToList(&head, 2);
	InsertToList(&head, 1);

	PrintList(head);
	TNode *root = ConvertToBST(&head);

	PreOrder(root);
	return 0;
}
