#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Min Heap
void InsertIntoHeap(int *Heap, int size, int data){
		Heap[size+1] = data;
		if(size == 0)
			return;
		int parent = 0;
		while(size == 0){
			parent = size/2;
			if(Heap[size] < Heap[parent]){
				swap(Heap[size] , Heap[parent]);
				size = parent;
			}else
				return;
		}
}

void Heapify(int *Heap, int size, int idx){
	while(idx < size){

	}
}

int GetMin(int *Heap, int size){
	int min = Heap[0];
	Heap[0] = Heap[--size];
	Heapify(Heap, size, 0);

	return min;
}
int main(){
	int arr[] = {3,4,1,8,5,2};
	int *heap;
	int size = sizeof(arr)/sizeof(int);
	heap = (int *)malloc(sizeof(int)*(size+10));
	int heapSize = 0;
	for(int i =0; i < size; i++){
		InsertIntoHeap(heap, heapSize++, arr[i]);
	}
	return 0;
}
