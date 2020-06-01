/*
 * Practice.cpp
 *
 *  Created on: Jan 10, 2019
 *      Author: chandra.shekhar
 */
#include <iostream>
using namespace std;

enum HEAP_TYPE{
	MIN_HEAP,
	MAX_HEAP
};

class Heap{
	int *A;
	int size;
	int cap;
	int heapType;

	bool Compare(int &a, int &b){
		if(heapType == MIN_HEAP)
			return a <= b;
		return a >= b;
	}
	void Swap(int &a, int &b){
		int temp = a;
		a = b;
		b = temp;
	}
public:
	void PrintHeapElements(){
		cout << endl;
		for(int i = 0; i < size; i++){
			cout << A[i] << ",";
		}
		cout << endl;
	}
	void HeapifyUp(int idx){
		int parent = idx/2;
		if(!Compare(A[parent], A[idx])){
			Swap(A[parent], A[idx]);
			HeapifyUp(parent);
		}
	}
	void HeapifyDown(int idx){

		int m = idx;
		int l = 2*idx + 1;
		int r = l + 1;

		if(l < (size) &&!Compare(A[idx], A[l]) ){
			m = l;
		}
		if(r < (size) && !Compare(A[m], A[r])){
			m = r;
		}
		if(m != idx){
			Swap(A[idx], A[m]);
				HeapifyDown(m);
		}
	}
	Heap(int capacity, int zHeapType) {
		cap = capacity;
		size = 0;
		heapType = zHeapType;
		A = (int *)malloc(sizeof(int)*cap);
	}
	Heap(int Arr[], int n, int capacity, int zHeapType){
		cap = capacity;
		size = 0;
		heapType = zHeapType;
		A = (int *)malloc(sizeof(int)*cap);
		for(int i = 0; i < n; i++){
			A[size++] = Arr[i];
		}
	}
	Heap(int zHeapType) {
		cap = 100;
		size = 0;
		heapType = zHeapType;
		A = (int *)malloc(sizeof(int)*cap);
	}
	bool IsFull(){
		return size == cap;
	}
	bool IsEmpty(){
		return size == 0;
	}
	int GetMinOrMax(){
		if(IsEmpty())
			return -1;
		int data = A[0];
		A[0] = A[size--];
		HeapifyDown(0);
		return data;
	}
	int SeekMinOrMax(){
		if(IsEmpty())
			return -1;
		return A[0];
	}

	bool Insert(int x){
		if(IsFull()){
			return false;
		}
		A[size++] = x;
		HeapifyUp(size-1);
	}
};

void Heapify(int A[], int n, int HeapType){

	int LastNonLeaf = (n-1)/2;
	Heap *heap = new Heap(A, n, 100, HeapType);

	for(int i = LastNonLeaf; i >=0; i--){
		heap->HeapifyDown(i);
	}
	heap->PrintHeapElements();
}

void PrintArray(int A[], int n){

	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d ", A[i]);
}
int main(){

	int A[] = {2,4,9,6,3,8,1,5};
	int n = (sizeof(A)/sizeof(A[0]));
	Heapify(A, n, MIN_HEAP);

	/*int n = (sizeof(A)/sizeof(A[0]));
	PrintArray(A, n);
	HeapSort(A,n);
	PrintArray(A, n); */

	return 0;
}



