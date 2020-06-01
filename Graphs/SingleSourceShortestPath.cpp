/*
 * SingleSourceShortestPath.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include "THeap.h"

using namespace std;

struct AdjNode{
	int V;
	int wt;
	AdjNode *next;
	AdjNode(int a, int wt){
		V = a;
		this->wt = wt;
	}
};
struct AdjList{
	AdjNode *head;
};
class UndirectedGraph{
public:
	int NumVer;
	AdjList *list;
	std::map<>
	UndirectedGraph(int V){
		NumVer = V;
		list = (AdjList *)malloc(NumVer*sizeof(AdjList));
		for(int i=0; i<NumVer; i++)
			list[i].head = NULL;
	}
	void AddEdge(int n1, int n2, int wt){
		AdjNode *newNode1 = new AdjNode(n2, wt);
		newNode1->next = list[n1].head;
		list[n1].head = newNode1;

		AdjNode *newNode2 = new AdjNode(n1, wt);
		newNode2->next = list[n2].head;
		list[n2].head = newNode2;

	}
	void PrintGraph(){
		for(int i=0; i<NumVer; i++){
			AdjNode *head = list[i].head;
			cout << endl << "Adjacency list of Vertex " << i << " are  " ;
			while(head){
				cout << "==> " << head->V;
				head = head->next;
			}
		}
	}
};
int main(){

	UndirectedGraph g1(6);
	g1.AddEdge(0,1,2);
	g1.AddEdge(0,3,5);
	g1.AddEdge(0,5,4);
	g1.AddEdge(1,2,4);
	g1.AddEdge(2,5,3);
	g1.AddEdge(3,5,2);
	g1.AddEdge(3,4,1);
	g1.PrintGraph();

	int StartPoint = 0;
	Heap<int> *myHeap = new Heap<int>(6, true);

	return 0;
}



