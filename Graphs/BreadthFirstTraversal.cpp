/*
 * BreadthFirstTraversal.cpp
 *
 *  Created on: Feb 4, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct List{
	int data;
	List *next;

	List(int d){
		data = d;
		next = NULL;
	}
};

class Queue{
	List *A;
	List *front;
	List *rear;
	int size;

public:
	Queue(){
		rear = front = NULL;
		size = 0;
	}
	bool isQueueEmpty(){
		return front == NULL;
	}
	void Enqueue(int u){
		//Not added Qfull logic
		List *n = new List(u);
		if(!rear){
			front = rear = n;
		}else{
			rear->next = n;
			rear = n;
		}

	}
	int Dequeu(){
		if(isQueueEmpty())
			return -1;

		List *n = front;
		front = front->next;
		if(isQueueEmpty())
			front = rear = NULL;
		int data = n->data;
		delete n;
		return data;
	}
};
struct AdjList{
	List *head;
	AdjList(){
		head = NULL;
	}
	void AddEdge(int v){
		List *node = new List(v);
		node->next = head;
		head = node;

	}
};

class Graph{
	int V;
	AdjList  **adjList;
	bool isDirectedGraph;
public:
	Graph(int numVert, bool isDirected = true){
		V = numVert;
		adjList = (AdjList **)malloc(sizeof(AdjList *) * V);
		for(int i = 0; i < V; i++)
			adjList[i] = new AdjList();
		isDirectedGraph = isDirected;
	}
	void AddEdge(int u, int v){
		adjList[u]->AddEdge(v);
		if(!isDirectedGraph)
			adjList[v]->AddEdge(u);
	}

	void BFS(int u){
		bool isVisted[V];
		for(int i = 0; i < V; i++)
			isVisted[i] = false;
		Queue Q;
		Q.Enqueue(u);
		isVisted[u] = true;
		int v = -1;
		printf("\n H1 \n");
		while(!Q.isQueueEmpty()){
			int v = Q.Dequeu();
			printf("\n H2 \n");
			printf("\n processing adjlist of vertex %d - ", v);
			List *l = adjList[v]->head;
			while(l){
				if(!isVisted[l->data]){
					printf("%d ", l->data);
					Q.Enqueue(l->data);
					isVisted[l->data] = true;
				}
				l = l->next;
			}
		}
		printf("\n");

	}
};

int main(){
	int V = 10;
	Graph g(V);
	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(1, 4);
	g.AddEdge(2, 5);
	g.AddEdge(2, 3);
	g.BFS(1);
	return 0;
}

