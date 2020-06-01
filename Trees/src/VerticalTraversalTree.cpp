/*
 * VerticalTraversalTree.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: chandra.shekhar
 */
#include <iostream>
#include <stdio.h>
#include<set>
#include<map>
#include<vector>
#include<stdlib.h>

using namespace std;

class MyTree{

public:
	MyTree *left;
	MyTree *right;
	int data;

	MyTree(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void CreateNode(int data){
	MyTree *node =   new(node);
	return node;
}
void TraverseVertical(MyTree *root, int hD, std::map< int, std::vector< int > > &myMap){

	if(root == NULL)
		return;

	std::map< int, std::vector< int > >::iterator itr = myMap.find(hD);
	if(itr != myMap.end()){
		itr->second.push_back(root->data);
	}else{
		std::vector<int> vec;
		vec.push_back(root->data);
		myMap[hD] = vec;
	}
	TraverseVertical(root->left, hD-1, myMap);
	TraverseVertical(root->right, hD+1, myMap);

}

void PrintVerticalOrder(std::map< int, std::vector< int > > &myMap){
	std::map< int, std::vector<int> >::iterator itr = myMap.begin();
	for(; itr != myMap.end(); itr++){
		printf("\n $ ");
		for(int i =0; i< itr->second.size(); i++)
			printf("%d \t", itr->second[i]);
	}
}
int main(){

	MyTree *root = new MyTree(1);
	MyTree *node = new MyTree(2);
	root->left = node;
	node = new MyTree(3);
	root->right = node;
	node = new MyTree(4);
	root->left->left = node;
	node = new MyTree(5);
	root->right->left = node;
	int hD = 0;

	std::map< int, std::vector< int > > myMap;
//	std::vector<int> vec;
//	vec.push_back(root->data);
//	myMap[hD] = vec;
	TraverseVertical(root, hD, myMap);

	PrintVerticalOrder(myMap);
	cout << endl ;
	return 0;
}

