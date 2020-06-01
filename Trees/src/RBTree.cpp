/*
 * RBTree.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: chandra.shekhar
 */
#include<cstdio>
#include<iostream>

using namespace std;

enum Color{
	BLACK = 0,
	RED = 1
};
class RBTree{
public:
	int data;
	Color color;
	RBTree *left;
	RBTree *right;

	RBTree(int key){
		data = key;
		color = RED;
		left = NULL;
		right = NULL;
	}
	RBTree(int key, Color clr){
		data = key;
		color = clr;
		left = NULL;
		right = NULL;
	}
};

void InOrder(RBTree *root){
	if(root == NULL)
		return;
	printf(" %d\t", root->data);
	InOrder(root->left);;
	InOrder(root->right);
}

void PreOrder(RBTree *root){
	if(root == NULL)
		return;
	PreOrder(root->left);
	printf(" (%d,%c)\t", root->data, (root->color == RED?'R':'B'));
	PreOrder(root->right);
}
RBTree *RotateRight(RBTree *root){
	if(root == NULL)
		return root;

	RBTree *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;
	return newRoot;
}

RBTree *RotateLeft(RBTree *root){
	if(root == NULL)
		return root;

	RBTree *newRoot  = root->right;
	printf("\n RotateLeft:: data %d color %d newRoot data %d newRoot color %d", root->data, root->color, (newRoot)->data, (newRoot)->color);
	root->right = newRoot->left;
	newRoot->left = root;
	return newRoot;
}

void InsertNode(RBTree **root, RBTree **parentNode, int key){
	if(*root == NULL){
		if(*parentNode != NULL)
			*root = new RBTree(key);
		else
			*root =  new RBTree(key,BLACK);
		return;
	}
	if(key > (*root)->data){
		InsertNode(&((*root)->right), root, key);
	}
	else{
		InsertNode(&((*root)->left), root, key);
	}
	if((*root)->color == BLACK )
			return ;

	//Enters here when descendants changes the color of root node
	if(*parentNode == NULL ){
		if((*root)->color == RED)
			 (*root)->color = BLACK;
		return;
	}
	//Both the siblings are RED
	if( ((*parentNode)->right && (*parentNode)->right->color == RED ) &&
	((*parentNode)->left && (*parentNode)->left->color == RED))  {
		(*parentNode)->right->color = BLACK;
		(*parentNode)->left->color = BLACK;
		(*parentNode)->color = RED;
		return ;
	}
	//Else if Sibling is black or empty, then rotate.
	if((*parentNode)->right == *root ){
		//right rotate
		if(key <= (*root)->data){ // child added to left
			*root = RotateRight(*root);
		}
		*parentNode = RotateLeft(*parentNode);
		(*parentNode)->color = BLACK;
		(*parentNode)->left->color = RED;
	}else if((*parentNode)->left == *root){
		if(key > (*root)->data){ //child added to right
			*root = RotateLeft((*root));
		}
		*parentNode = RotateRight(*parentNode);
		(*parentNode)->color = BLACK;
		(*parentNode)->right->color = RED;
	}
}

int main(){

	RBTree *root = NULL;
	RBTree *tmpNode = NULL;
	InsertNode(&root, &tmpNode, 10);
	 InsertNode(&root, &tmpNode, 20);
	InsertNode(&root, &tmpNode, 30);
	InsertNode(&root, &tmpNode, 5);
	cout << endl << "Printing" << endl;
	printf("\n");
	PreOrder(root);
	printf("\n");
	return 0;
}



