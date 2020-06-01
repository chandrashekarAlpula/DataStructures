/*
 * KruskalsAlgo.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: chandra.shekhar
 */
#include<iostream>
using namespace std;

struct DSet{
	int d;
	DSet *parent;
	int rank;
	DSet(int data){
		d = data;
		rank = 0;
		parent = NULL;
	}
};

DSet *DHash[1000];
struct Edge{
	int src, dest, wt;
	/*Edge(int s, int d, int w){
		src = s;
		dest = d;
		wt = w;
	}*/
	Edge &operator=(const Edge &g){
		src = g.src;
		dest = g.dest;
		wt = g.wt;
		return *this;
	}
};

class Graph{
public:
	int V;
	int E;
	Edge *edge;
	int edgeSize;
	Graph(int ver, int ed){
		V = ver;
		E  = ed;
		edge = new Edge[E];
		edgeSize =  0;
	}
	void AddEdge(int u, int v, int w){
		edge[edgeSize].src = u;
		edge[edgeSize].dest = v;
		edge[edgeSize].wt = w;
		edgeSize++;
	}
};



void MakeSet(int u){
	DSet *s = new DSet(u);
	s->parent = s;
	DHash[u] = s;

}

DSet *root(DSet *s){

	if(s != s->parent)
		s->parent = root(s->parent);
	return s->parent;
}

void Union(int x, int y){
	DSet *p1 = root(DHash[x]);
	DSet *p2 = root(DHash[y]);

	if(p1->rank > p2->rank)
		p2->parent = p1;
	else if(p1->rank < p2->rank)
		p1->parent = p2;
	else{
		p2->parent = p1;
		p1->rank++;
	}
}

void insertionSort(Edge edg[], int n){
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0; j--){
			if(edg[j].wt < edg[j-1].wt){
				Edge temp = edg[j];
				edg[j] = edg[j-1];
				edg[j-1] = temp;

			}else
				break;
		}
	}
}
int  KruskalsMST(Graph &g){
	insertionSort(g.edge, g.E);
	int minCst = 0;
	for(int i = 0; i < g.E; i++){
		DSet *p1 = root(DHash[g.edge[i].src]);
		DSet *p2 = root(DHash[g.edge[i].dest]);
		if(p1 == p2)
			continue;
		Union(g.edge[i].src, g.edge[i].dest);
		minCst += g.edge[i].wt;
	}
	return minCst;
}
int main(){

	int N = 5;
	int E = 7;
	//cin >> N;
	Graph g(N, E);
	for(int i = 0; i < 1000; i++)
		DHash[i] = NULL;
	g.AddEdge(1, 2, 1);
	g.AddEdge(1, 3, 7);
	g.AddEdge(2, 3, 5);
	g.AddEdge(2, 4, 4);
	g.AddEdge(2, 5, 3);
	g.AddEdge(3, 5, 6);
	g.AddEdge(4, 5, 2);
	for(int i = 1; i <= N; i++)
		MakeSet(i);

	int cost = KruskalsMST(g);
	cout << "Min Cost " << cost << endl;
	return 0;
}
