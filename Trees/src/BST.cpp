/*
 * BST.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: chandra.shekhar
 */
#include "BST.h"
#include "TQueue.h"

unsigned int BST::HeightOfTree(BSTNode *root){

	if(root == NULL)
		return 0;

	unsigned int ht = (max(HeightOfTree(root->left), HeightOfTree(root->right))+1 ) ;
	//printf("\n Value %d  Height %d \n", root->data, ht);
	return ht;
}


unsigned int DiameterOfTree(BST *root){
	if(root == NULL)
		return 0;
}
void BST::InsertNode(int val){

	BSTNode *node = new BSTNode(val);
	if(mRoot == NULL){
		mRoot = node;
		return;
	}

	BSTNode *tmpNode = mRoot;
	while(1){
		if(tmpNode->data > val){
			if(tmpNode->left == NULL){
				tmpNode->left  = node;
				break;
			}else{
				tmpNode = tmpNode->left;
			}
		}else{
			if(tmpNode->right == NULL){
				tmpNode->right = node;
				break;
			}else{
				tmpNode = tmpNode->right;
			}
		}
	}
}

BSTNode *BST::GetInorderSucc(BSTNode *currentNode){

	while(currentNode->left != NULL){
		currentNode = currentNode->left;
	}
	return currentNode;
}

BSTNode* BST::DeleteNode(BSTNode *root, int value){

	if(root == NULL)
		return root;
	cout << " Node Value " << root->data << endl ;
	if(root->data > value){
		root->left =  DeleteNode(root->left, value);
	}
	else if(root->data < value){
		root->right =  DeleteNode(root->right, value);
	}
	else{
		//If node has one child
		cout << "Found Value " << endl ;
		if(root->left == NULL)
		{
			cout << "Left " << endl ;
			BSTNode *tmpNode = root;
			root = root->right;
			delete tmpNode;
		}
		else if(root->right == NULL){
			cout << "Right " << endl ;
			BSTNode *tmpNode = root;
			root = root->left;
			delete tmpNode;
		}else {
		//If both children are not null. Then replace with next successor.
			BSTNode *tmpNode =  GetInorderSucc(root->right);
			root->data = tmpNode->data;
			root->right = DeleteNode(root->right, value);
		}
	}
	return root;
}

void BST::PrintElements(BSTNode *root){
	//Print in BFT order
	if(root == NULL)
		return;

	cout << endl << "Data " << root->data ;
	PrintElements(root->left);
	PrintElements(root->right);

}

void BST::PrintLevelOrder(BSTNode *root){

printf("\n Printing Level order \n");
	TQueue<BSTNode *> *queue = new TQueue<BSTNode *>(100);
	bool ret = queue->EnQueue(root);

	while(!queue->isEmpty()){
		BSTNode *node = queue->DeQueue();
		if(node != NULL){
			printf("%d \t", node->data);
			if(node->left != NULL)
				bool ret = queue->EnQueue(node->left);
			if(node->right != NULL)
				bool ret = queue->EnQueue(node->right);
		}
	}
	delete queue;
}

void BST::InOrderTraversal(BSTNode *root){
	if(root == NULL)
		return;

	InOrderTraversal(root->left);
	printf("%d \t", root->data);
	InOrderTraversal(root->right);
}

void BST::PreOrderTraversal(BSTNode *root){

	if(root == NULL)
		return;
	printf("%d\t", root->data);
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}


void BST::PostOrderTraversal(BSTNode *root){
	if(root == NULL)
		return;

	PostOrderTraversal(root->left);
	PostOrderTraversal(root->right);
	printf("%d\t", root->data);
}
