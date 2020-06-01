/*
 * Graphs.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>

using namespace std;

struct AdjNode{
	int v;
	AdjNode *next;
	AdjNode(int v){
		this->v = v;
		this->next = NULL;
	}
};
struct AdjList{
	AdjNode *head;
};
class Graph{
	int V; // Number of vertices
	AdjList *list; // array of lists of adjacent vertices
public:
	Graph(int numVer){
		V = numVer;
		list = (AdjList *)malloc(V*sizeof(AdjList));
		for(int i=0; i<V; i++)
			list[i].head = NULL;
	}
	void AddEdge(int src, int dest){
		AdjNode *newNode = new AdjNode(dest);
		newNode->next = list[src].head;
		list[src].head = newNode;
	}

	void PrintGraph(){
		for(int i=0; i<V; i++){
			AdjNode *head = list[i].head;
			cout << endl << "Adjacency list of vertex " << i ;
			while(head){
				cout << " --> " << head->v;
				head = head->next;
			}
		}
	}
};
int main(){

	Graph g(5);
		g.AddEdge(0,1);
		g.AddEdge(0,2);
		g.AddEdge(1,2);
		g.AddEdge(1,3);
		g.AddEdge(1,4);
		g.AddEdge(2,1);
		g.AddEdge(3,0);
		g.AddEdge(0,4);
		g.AddEdge(3,4);
		g.AddEdge(4,3);
		g.AddEdge(2,3);
		g.AddEdge(2,4);
		g.AddEdge(4,0);
		g.AddEdge(4,3);

		g.PrintGraph();
	return 0;
}



