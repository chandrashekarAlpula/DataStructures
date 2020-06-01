/*
 * test.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>
#include<queue>

#define ll long long int
#define pi(x) printf("%d ", x);
#define pn() printf("\n");

#define FOR(i, n) for(ll i = 0; i < n; i++)
using namespace std;

struct List{
	ll d;
	ll wt;
	List *next;

	List(ll v, ll w){
		d = v;
		wt = w;
		next = NULL;
	}
};
struct AdjList{
	List *head;
	List *tail;
	AdjList(){
		head = tail = NULL;
	}
	void AdjEdge(ll u, ll w){
		List *n = new List(u, w);
		if(head == NULL){
			head = tail = n;
			return;
		}
		tail->next = n;
		tail = n;
	}
	List *GetHeadPtr(){
		return head;
	}
};
class Graph{
	ll V;
	AdjList **adList;
	bool isDirectedGraph;
public:
	Graph(ll vert, bool isDirected = false){
		V = vert;
		isDirectedGraph = isDirected;
		adList = new AdjList *[V];
		FOR(i, V){
			adList[i] = new AdjList();
		}
	}
	void AddEdge(ll u, ll v, ll wt){
		u--;
		v--;
		adList[u]->AdjEdge(v, wt);
		if(!isDirectedGraph)
			adList[v]->AdjEdge(u, wt);
	}

	ll GetNumVertices(){
		return V;
	}
	List *GetAdjList(ll u){
		return adList[u]->GetHeadPtr();
	}
};

ll GetCost(ll dist){
	if(dist < 100)
		return 0;
	if(dist <= 1000)
		return 100;
	if(dist <= 10000)
		return 1000;
	return 10000;
}


ll BFS(Graph &g, ll source){
	//source--;
	queue<ll>  q;
	ll n = g.GetNumVertices();
	bool isVisited[n];
	ll distance[n];
	FOR(i, n){
		isVisited[i] = false;
		distance[i] = 0;
	}
	q.push(source);
	isVisited[source] = true;
	distance[source] =  0;
	ll totWt  = 0;
	ll dist = 0;
	while(!q.empty()){
		ll v =  q.front();
		q.pop();
		List *n  = g.GetAdjList(v);
		while(n){
			ll val = n->d;
		    ll wt = n->wt;
			if(!isVisited[val]){
				totWt += wt;
				dist++;
				isVisited[val] = true;
				printf("\n u %d v %d wt %d\n", v, val, wt);
				//distance[]
				q.push(val);
			}else{

			}
			n = n->next;
		}
	}
	printf("\n%d %d\n", GetCost(dist), totWt);

}

ll DFS(Graph &g, bool isVisted[], ll u){
	List *n  = g.GetAdjList(u);
	ll totWeight = 0;
	ll tWt = 0;
	ll cnt = 1;
	while(n){
		if(!isVisted[n->d]){
			cnt = 1;
			isVisted[n->d] = true;
			ll wt = n->wt;
			wt += DFS(g, isVisted, n->d);
			if(wt > totWeight){
				totWeight = wt;
				//prllf("\n u %d v %d wt %d\n", u+1, n->d+1, wt);
			}
		}
		n =  n->next;
	}
	return totWeight;
}

//Lognest path is the diameter of N array tree i.e distance b/w two leafs
// Calcualte the longest leaf from root node.
//Now again calcualte the distance from this node  leaf node to leaf node which at longest distance.

ll DiameterOfNArray(Graph &g, ll u){
	static int run = 0;
	ll n = g.GetNumVertices();
	bool isVisited[n];
	ll distance[n];
	FOR(i, n){
		isVisited[i] = false;
		distance[i] = 0;
	}
	queue<ll> q;
	q.push(u);
	isVisited[u] = true;
	distance[u] = 0;
	ll totDis = 0;
	while(!q.empty()){
		ll u  = q.front();
		q.pop();
		List *n = g.GetAdjList(u);
		while(n){
			ll v = n->d;
			ll wt = n->wt;
			if(!isVisited[v]){
				if(distance[v] < distance[u] + n->wt)
					distance[v] =  distance[u] + n->wt;
				q.push(v);
				isVisited[v] = true;
			}
			n = n->next;
		}
	}
	ll leaf = 0;
	ll maxDis = 0;
	FOR(i, n){
		if(distance[i] > maxDis){
			leaf = i;
			maxDis = distance[i];
		}
	}
	//printf("\n Leaf node %d max Distance %d\n", leaf+1, maxDis);
	if(!run++)
		maxDis = DiameterOfNArray(g, leaf);

	return maxDis;


}
int main(){

	int T;
	cin >> T;
	FOR(i, T){
		ll N;
		cin >> N;
		Graph g(N);
		FOR(j , N-1){
			ll u, v, wt;
			cin >> u  >> v >> wt;
			g.AddEdge(u, v, wt);
		}
		ll totWt = 0;
		FOR(k, N){//Iterate through num vertices and calculate the max path for each vertex
			bool isVisited[N];
			FOR(i, N){
				isVisited[i] = false;
			}
			//cout << "===== " << k+1 << endl;
			isVisited[k] = true;
			ll wt = DFS(g, isVisited, k);
			if(wt > totWt){
				totWt = wt;
			}

		}

	//	totWt  = DiameterOfNArray(g, 0);
		cout <<  GetCost(totWt)  << " " << totWt << endl;
	}
	return 0;
}



