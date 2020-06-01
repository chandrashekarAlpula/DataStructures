/*
 * TestTries.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
const int ALPHABET_SIZE = 26;

struct TrieNode{
	bool isEnd;
	TrieNode *child[ALPHABET_SIZE];
};

TrieNode *GetNode(){
	TrieNode *node= (TrieNode *)malloc(sizeof(TrieNode));
	//printf("\n H1 \n");
	for(int i =0; i< ALPHABET_SIZE; i++)
		node->child[i] = NULL;
	//printf("\n H1 \n");
	node->isEnd = false;
	return node;
}
//Assuming all are small letters
void InsertNode(TrieNode *root, char *word){
	int len= strlen(word);
	TrieNode *node = root;
	for(int i = 0; i < len; i++){
		int index = word[i] - 'a';
		if(node->child[index] == NULL )
			node->child[index] = GetNode();
		//printf("\n char1 is %c index %d\n", word[i], index);
		node = node->child[index];
	}

	node->isEnd = true;
}


bool SearchNode(TrieNode *root, char *word){
	if(root == NULL)
		return false;
	int len = strlen(word);
	for(int i = 0; i < len; i++){
		int index = word[i] - 'a';
		//printf("\n Searching char %c index %d\n", word[i], index);
		if(root == NULL || root->child[index] == NULL)
			return false;
		root = root->child[index];
	}
	//printf("\n Here\n ");
	return (root != NULL && root->isEnd);
}

int main(){
	char keys[][8] = {"the", "a", "there", "answer", "any","by", "bye", "their"};

	TrieNode *root = GetNode();
	char output[][32] = {"Not present in trie", "Present in trie"};
	for (int i = 0; i < ARRAY_SIZE(keys); i++){
		InsertNode(root, keys[i]);
		//break;
	}
	printf("%s --- %s\n", "the", output[SearchNode(root, "the")] );
	printf("%s --- %s\n", "these", output[SearchNode(root, "these")] );
	printf("%s --- %s\n", "their", output[SearchNode(root, "their")] );
	printf("%s --- %s\n", "answer", output[SearchNode(root,"answer")] );
	return 0;
}
