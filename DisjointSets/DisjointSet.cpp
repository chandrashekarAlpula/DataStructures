/*
 * DisjointSet.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<map>
using namespace std;

struct Node{
	int data;
	int rank;
	Node *parent;
	Node(int data){
		this->data = data;
		this->rank = 0;
		this->parent = NULL;
	}
};
class DisjointSet{
private:
	std::map<int, Node*> setMap;

public:
	void MakeSet(int data);
	void Union(int data1, int data2);
	int Find(int data);
	Node *Find(Node *node);
};

void DisjointSet::MakeSet(int data){
	Node *node = new Node(data);
	node->parent = node;
	setMap[data] = node;
}

void DisjointSet::Union(int data1, int data2){
	std::map<int,Node *>::iterator itr1 = setMap.find(data1);
	std::map<int, Node*>::iterator itr2 = setMap.find(data2);
	Node *node1 = itr1->second;
	Node *node2 = itr2->second;
	node1->parent = Find(node1);
	node2->parent = Find(node2);

	if(node1->parent == node2->parent)
		return;

	if(node1->rank >= node2->rank){
		node2->parent = node1;
		if(node1->rank == node2->rank)
			node1->rank++;
	}else{
		node1->parent = node2;
	}
}

Node *DisjointSet::Find(Node *node){
	if(node->parent == node)
		return node;
	node->parent = Find(node->parent);
	return (node->parent);
}

int DisjointSet::Find(int data){
	map<int, Node*>::iterator itr = setMap.find(data);
	if(itr == setMap.end())
		return -1;
	Node *node = itr->second;
	node = Find(node);
	return node->data;
}


int main(){

	DisjointSet ds;
	ds.MakeSet(1);
	ds.MakeSet(2);
	ds.MakeSet(3);
	ds.MakeSet(4);
	ds.MakeSet(5);
	ds.MakeSet(6);
	ds.MakeSet(7);

	ds.Union(1,2);
	ds.Union(2,3);
	ds.Union(4,5);
	ds.Union(6,7);
	ds.Union(4,7);
	ds.Union(1,5);

	cout << endl << "1 Parent " << ds.Find(1);
	cout << "2 Parent " << ds.Find(2) << endl;
	cout << "3 Parent " << ds.Find(3) << endl;
	cout << "4 Parent " << ds.Find(4) << endl;
	cout << "5 Parent " << ds.Find(5) << endl ;
	cout << "6 Parent " << ds.Find(6) << endl ;
	cout << "7 Parent " << ds.Find(7) << endl;

	return 0;
}
