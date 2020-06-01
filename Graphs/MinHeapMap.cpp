/*
 * MinHeapMap.cpp
 *
 *  Created on: Jan 26, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>
#include<limits.h>
//#define INT_MAX 0X0FFFFFFF
struct List{
	int d;
	int wt;
	List *next;
};
using namespace std;

class Graph{
public:
	int V;
	List **AdjList;
	int size;
	bool isDirected;
public:
	Graph(int numVert, bool directed){
		V =  numVert;
		size = 0;
		isDirected = directed;
		AdjList = (List **)malloc(V * sizeof(List *));
		for(int i =0; i < V; i++)
			AdjList[i] = NULL;
	}
	void AddEdge(int u, int v, int wt){
		List *node = (List *)malloc(sizeof(List));
		node->d = v;
		node->wt = wt;
		node->next = NULL;
		// Duplicate Edge check is not considered
		node->next = AdjList[u];
		AdjList[u] = node;

		//Create reverse edge
		if(!isDirected){
			List *n1 = (List *)malloc(sizeof(List));
			n1->d = u;
			n1->wt = wt;
			n1->next = NULL;
			n1->next = AdjList[v];
			AdjList[v] = n1;
		}
	}
	void PrintEdges(){
		for(int i = 0; i < V; i++){
			if(AdjList[i] != NULL){
				List *node = AdjList[i];
				printf("\n Src %d : ", i);
				while(node){
					printf("(%d, %d), ", node->d, node->wt);
					node = node->next;
				}
			}
		}
		printf("\n");
	}

};

struct HeapNode{
	int v;
	int dist;
};

class CHeap{
public:
	HeapNode **heap;
	int *map;
	int size;
	int capacity;

public:
	CHeap(int cap){
		capacity = cap;
		size = 0;
		heap = (HeapNode **)malloc(capacity * sizeof(HeapNode *));
		map = (int *)malloc(sizeof(int) * capacity);
		for(int i =  0; i < capacity; i++){
			heap[i] = NULL;
			map[i] = INT_MAX;
		}
	}
	HeapNode *DeleteMin(){
		if(size == 0)
			return NULL;
		HeapNode *tmp = heap[0];
		heap[0] = heap[--size];
		map[heap[0]->v] = 0;
		Heapify(0);
		return tmp;
	}
	HeapNode *SeekMin(){
		return heap[0];
	}
	void AddNode(int v, int dist = INT_MAX){
		HeapNode *node = (HeapNode *)malloc(sizeof(HeapNode));
		if(size == capacity){
			printf("\n Heap is Full not adding the node %d", node->v);
			return;
		}
		node->v = v;
		node->dist = dist;
		heap[size++] = node;
		HeapifyUp(size -1);
		map[size -1] = size-1;
		//printf("\n Adding Node %d at %d dist %d size is %d", v, map[v], dist, size);
	}
	void SwapHeapNodes(int idx1, int idx2){
		UpdateMap(idx1, idx2);
		HeapNode *tmp = heap[idx1];
		heap[idx1] = heap[idx2];
		heap[idx2] = tmp;

	}
	void UpdateMap(int idx1, int idx2){
		//printf("\n UpdateMap idx1 %d Idx2 %d" );
		map[heap[idx1]->v] = idx2;
		map[heap[idx2]->v] = idx1;
	}
	bool ExistsInMap(int v){
		return map[v] >=  0;
	}
	int GetIndexFromMap(int v){
		return map[v];
	}
	void DeleteFromMap(int v){
		map[v] = -1;
		//printf("\n After Deleting min heap index of %d is %d \n", v, map[v]);
	}
	void HeapifyUp(int idx){
		if(idx == 0){
			map[idx] = 0;
			return;
		}
		while(idx > 0){
			if(heap[idx]->dist < heap[idx/2]->dist ){
				printf("\n&&& Dist of idx(%d) parent(%d) \n", heap[idx]->v,heap[idx/2]->v);
				SwapHeapNodes(idx, idx/2);
				//HeapifyUp(idx/2);
				PrintHeap();
				idx = idx/2;
			}else{
				printf("\n && Setting Idx [%d] of map to size %d", idx,(size-1));
				//map[idx] = size-1;
				break;
			}
		}
		printf("\n HERE \n");

	}
	void PrintHeap(){
		printf("\nPrintHeap Size %d\n", size);
		for(int i = 0; i < size; i++)
			printf("(V(%d), Wt(%d), mapIdx(%d)), ", heap[i]->v, heap[i]->dist, map[heap[i]->v]);
		printf("\n");
	}
	void Heapify(int idx){
		if(idx >= size)
			return;
		int left = 2*idx +1;
		int right = left + 1;
		int min = idx;
		//printf("\n Dist of idx(%d) left(%d) right(%d) \n", heap[idx]->dist,heap[left]->dist, heap[right]->dist);
		if(heap[idx]->dist > heap[left]->dist){
			min = left;
		}
		if(heap[min]->dist > heap[right]->dist){
			min = right;
		}
		if(min != idx){
			SwapHeapNodes(idx, min);
			Heapify(min);
		}
	}
	bool Decrement(int v, int dist){
		int idx  = GetIndexFromMap(v);
		printf("Idx from map %d for V %d\n",idx, v);
		if(heap[idx]->dist > dist){
			printf("Heap dist %d dist recv %d HeapId %d \n",heap[idx]->dist, dist, heap[idx]->v);
			heap[idx]->dist = dist;
			PrintHeap();
			HeapifyUp(idx);
			printf("\n +++++++++++++\n");
			return true;
		}
		return false;
	}
};

void DijkstraAlgo(Graph &g, int source){
	CHeap *heap = new CHeap(g.V);
	heap->AddNode(source, 0);
	for(int i = 0; i < g.V; i++)
		if(i != source)
			heap->AddNode(i, INT_MAX);
	//printf("\n Heap size %d", heap->size);
	int Path[g.V];
	int VDistances[g.V];
	for(int i =0; i < g.V; i++){
		Path[i] = -1;
		VDistances[i] = INT_MAX;
	}
	heap->Decrement(source, 0);
	heap->PrintHeap();

	HeapNode *node = heap->DeleteMin();
	int current = -1;
	int cnt = 1;
	VDistances[source] = 0;
	while(node){
		int u = node->v;
		printf("\n Heap Min Node %d Dist %d\n", u, node->dist);
		heap->DeleteFromMap(u);
		List *list = g.AdjList[u];
		current = u;
		//heap->PrintHeap();
		//return;
		while(list){
			int v = list->d;
			if(heap->ExistsInMap(list->d)){
				Path[v] = current;
				int distance = list->wt + node->dist;
				printf("\n u %d v %d Diist %d lst wt %d nodeDist %d listvertexx(%d)\n", u, v, distance, list->wt, node->dist, list->d);
				if(heap->Decrement(list->d, distance)){
					VDistances[list->d] = distance;
				}
			}
			list = list->next;
		}
		heap->PrintHeap();
	//	return;
		node = heap->DeleteMin();
	}
	for(int i = 0; i < g.V; i++)
		printf("Node %d (%d, %d): ", i, VDistances[i], Path[i]);

	int dest = 2;
	printf("\n Path to destination\n");
	while(1){
		printf("%d, ", dest);
		if(dest == 0)
			break;
		dest = Path[dest];

	}
	return;

}


int main(){
	Graph g(6, false);
	/*g.AddEdge(0, 1, 4);
	g.AddEdge(0, 2, 1);
	g.AddEdge(1, 4, 4);
	g.AddEdge(2, 1, 2);
	g.AddEdge(2, 3, 4);
	g.AddEdge(3, 4, 4);*/

	g.AddEdge(0, 1, 5);
	g.AddEdge(0, 3, 9);
	g.AddEdge(0, 4, 2);
	g.AddEdge(1, 2, 2);
	g.AddEdge(2, 3, 3);
	g.AddEdge(3, 5, 2);
	g.AddEdge(4, 5, 3);
	/*
	g.AddEdge(0, 1, 4);
	g.AddEdge(0, 7, 8);
	g.AddEdge(1, 2, 8);
	g.AddEdge(1, 7, 11);
	g.AddEdge(2, 3, 7);
	g.AddEdge(2, 8, 2);
	g.AddEdge(2, 5, 4);
	g.AddEdge(3, 4, 9);
	g.AddEdge(3, 5, 14);
	g.AddEdge(4, 5, 10);
	g.AddEdge(5, 6, 2);
	g.AddEdge(6, 7, 1);
	g.AddEdge(6, 8, 6);
	g.AddEdge(7, 8, 7);*/
	g.PrintEdges();

	DijkstraAlgo(g, 0);
	return 0;
}


