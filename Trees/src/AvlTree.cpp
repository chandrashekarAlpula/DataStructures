/*
 * AvlTree.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: chandra.shekhar
 */

#include<iostream>
#include<stdio.h>

using namespace std;

struct AVLTree{
	int data;
	int ht;
	AVLTree *left;
	AVLTree *right;
	AVLTree(int val){
		data = val;
		ht = 1;
		left = NULL;
		right = NULL;
	}
};

AVLTree *RightRotate(AVLTree *root){
	if(root == NULL)
		return NULL;

	AVLTree *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	return newRoot;
}

AVLTree *LeftRotate(AVLTree *root){
	if(root == NULL)
		return NULL;
	AVLTree *newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
	return newRoot;

}

int Height(AVLTree *node){
	return (node == NULL ? 0 : node->ht);
}

AVLTree *InsertNode(AVLTree *root, int key){
	if(root == NULL){
		return (new AVLTree(key));
	}
	if(key <= root->data)
		root->left = InsertNode(root->left, key);
	else
		root->right = InsertNode(root->right, key);

	int lht = Height(root->left);
	int rht = Height(root->right);
	root->ht =  max(lht, rht) +1 ;
	int htDiff = lht - rht;
	//printf("\n Data %d LH %d RH %d \n", root->data,lht, rht);
	//printf("\n root ht %d rt node data %d htDiff %d\n", root->ht,root->right->data, htDiff);
	if(htDiff > 1 ){
		if(key <= root->left->data){
		// Left subtree hight is more  and new node
		//is added to left of left subtree. So right rotate
			root = RightRotate(root);

		}else{
			// Left subtree hight is more  and new node
			//is added to left of left subtree.
			//So left rotate left sub tree and then right rotate
			root->left = LeftRotate(root->left);
			root = RightRotate(root);
		}

	}else if(htDiff < -1 ){
		if(key > root->right->data){
		// Left subtree hight is more  and new node
		//is added to left of left subtree. So right rotate
			root = LeftRotate(root);

		}else{
			// Left subtree hight is more  and new node
			//is added to left of left subtree.
			//So right rotate right sub tree and then Left rotate
			root->right = RightRotate(root->right);
			root =LeftRotate(root);
		}

	}

	return root;
}

void PreOrder(AVLTree *root){
	if(root == NULL)
		return;
	printf("%d\t", root->data);
	PreOrder(root->left);;
	PreOrder(root->right);
}

void InOrder(AVLTree *root){
	if(root == NULL)
			return;
	InOrder(root->left);
	printf("%d\t", root->data);
	InOrder(root->right);

}

int main(){

	AVLTree *root;
	root = InsertNode(root, 10);
	root = InsertNode(root, 20);
	root = InsertNode(root, 30);
	root = InsertNode(root, 40);
	root = InsertNode(root, 50);
	root = InsertNode(root, 25);
	printf("\n");
	PreOrder(root);
	printf("\n");

	printf("\n");
	InOrder(root);
	printf("\n");
	return 0;
}


