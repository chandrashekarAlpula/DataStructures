/*
 * TernarySearch.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<string.h>

struct TernaryNode{
	char data;
	TernaryNode *left, *eq, *right;
	bool isEnd;
};


TernaryNode *GetNode(char data){
	TernaryNode *node = new TernaryNode();
	node->data = data;
	node->left = node->right = node->eq = NULL;
	return node;
}

void InsertString(TernaryNode **root, char *word){
	if(!*word)
		return;
	if(!*root)
		*root = GetNode(*word);
	if( *word < (*root)->data){
		InsertString(&((*root)->left), word);
	}else if(*word > (*root)->data){
		InsertString(&((*root)->right), word);
	}else{
		if(*(word+1)){
			InsertString(&((*root)->eq), word+1);
		}else
			(*root)->isEnd = true;
	}
}

bool SearchString(TernaryNode *root, char *word){
	if(!root)
		return false;

	if(*word < root->data){
		return SearchString(root->left, word);
	}else if(*word > root->data){
		return SearchString(root->right, word);
	}else{
		if(*(word +1) == '\0')
			return root->isEnd;
		else
			return SearchString(root->eq, word+1);

	}
}

int main()
{
    TernaryNode *root = NULL;

    InsertString(&root, "cat");
    InsertString(&root, "cats");
    InsertString(&root, "up");
    InsertString(&root, "bug");

 //   printf("Following is traversal of ternary search tree\n");
   // traverseTST(root);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    SearchString(root, "cats")? printf("Found\n"): printf("Not Found\n");
    SearchString(root, "bu")?   printf("Found\n"): printf("Not Found\n");
    SearchString(root, "cat")?  printf("Found\n"): printf("Not Found\n");

    return 0;
}



