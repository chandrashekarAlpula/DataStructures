#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;

bool isVisited[100005];
struct List{
	int d;
	List *next;
	List(int v){
		d = v;
		next = NULL;
	}
};
struct AdjList{
	List *head;
	int numofAdjNodes;
	AdjList(){
		head = NULL;
		numofAdjNodes = 0;
	}
	void AddEdge(int u){
		List *n = new List(u);
		n->next  = head;
		head = n;
		numofAdjNodes++;
	}
};
class Graph{
public:
	int V;
	bool isDirected;
	AdjList **adj;
	Graph(int vert, bool direct = true){
		V = vert + 1 ;
		adj = new AdjList *[V + 1];
		for(int i = 0; i <= V; i++)
			adj[i] = new AdjList();
		isDirected = direct;
	}
	void AddEdge(int u, int v){
		adj[u]->AddEdge(v);
		//printf("\n U is %d v %d", u, v);
		if(!isDirected)
			adj[v]->AddEdge(u);
	}
};

int IdetifytheParent(Graph g){
	int N = g.V;
	int minNodes = 0X0FFFFFFF;
	int parent =  0;
	for(int i = 1; i < N; i++){
		if(g.adj[i]->numofAdjNodes < minNodes){
			minNodes = g.adj[i]->numofAdjNodes;
			parent = i;
		}
	}
	cout << "parent is " << parent << endl;
	return parent;
}
int DFS(Graph g, int u, int &numHappyNodes){
	List *n = g.adj[u]->head;
	if(n  == NULL)
		return 0;
	int numNodes = g.adj[u]->numofAdjNodes;
	while(n){
		if(!isVisited[n->d]){
			int cnt =  DFS(g, n->d, numHappyNodes);
			if(cnt > numNodes)
				numHappyNodes++;
			isVisited[n->d] = true;
		}
		n = n->next;
	}
	return numNodes;
}
int main(){

	int N, M;
	cin >> N >> M;
	int x, y;
	Graph g(N);
	while(M--){
		cin >> x >> y;
		g.AddEdge(x, y);
	}
	for(int i = 0; i< 100005; i++)
		isVisited[i] = false;
	int parent = IdetifytheParent(g);
	int numHappyNodes = 0;
	DFS(g, parent, numHappyNodes);
	cout << numHappyNodes << endl;

	return 0;
}
