/*
 * Bst1.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: chandra.shekhar
 */
#include "BST.h"
#include<cmath>

int MaxDepthOrHeight(BSTNode *root){

	if(root == NULL)
		return 0;
	return ( max(MaxDepthOrHeight(root->left), MaxDepthOrHeight(root->right)) + 1);
}

int main(){

	BST* bsTree = new BST(10);
	//bsTree->InsertNode(10);
	bsTree->InsertNode(60);
	bsTree->InsertNode(15);
	bsTree->InsertNode(9);
	bsTree->InsertNode(40);
	bsTree->InsertNode(80);
	//bsTree->PrintElements(bsTree->GetRoot());
	cout << endl ;
	//bsTree->DeleteNode(bsTree->GetRoot(), 30);
	//PrintElements(bsTree->GetRoot());
	bsTree->PrintLevelOrder(bsTree->GetRoot());
	printf("\n InOrderTraversal \n");
	bsTree->InOrderTraversal(bsTree->GetRoot());

	printf("\n PreOrderTraversal \n");
	bsTree->PreOrderTraversal(bsTree->GetRoot());

	printf("\n PostOrderTraversal \n");
	bsTree->PostOrderTraversal(bsTree->GetRoot());

	unsigned int ht = bsTree->HeightOfTree(bsTree->GetRoot());

	printf("\n Height of Tree is %d \n", ht);
	return 0;
}




