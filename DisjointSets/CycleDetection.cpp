/*
 * CycleDetection.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>

using namespace std;

// a structure to represent an edge in graph
struct Edge
{
	int src, dest;
};

// a structure to represent a graph
struct Graph
{
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges
	Edge* edge;
};

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
	Graph* graph =  (Graph*) malloc( sizeof(Graph) );
	graph->V = V;
	graph->E = E;

	graph->edge =
	(Edge*) malloc( graph->E * sizeof( Edge ) );

	return graph;
}

void MakeSet(int parent[], int n){
	for(int i = 0; i<n; i++){
		parent[i] = -1;
	}
}

int Find(int parent[], int i){
	if(parent[i] == -1)
		return i;
	parent[i] = Find(parent, parent[i]);
	return parent[i];
}

void Union(int parent[], int x, int y){
	int xParent = Find(parent, x);
	int yParent = Find(parent, y);
	if(xParent != yParent){
		parent[xParent] = yParent;
	}
}
bool IsCyclic(Graph *g){
	int parent[g->V];
	MakeSet(parent, g->V);

	for(int i = 0; i < E; i++){
		Union(parent, g->edge[i].src, g->edge[i].dest);

	}

	return false;
}
int main(){

	int V = 3, E = 3;
	Graph *g = createGraph(V, E);
	g->edge[0].src = 0;
	g->edge[0].dest = 1;

	g->edge[1].src = 1;
	g->edge[1].dest = 2;

	g->edge[2].src = 2;
	g->edge[2].dest = 0;

	IsCyclic(g);
	return 0;
}



