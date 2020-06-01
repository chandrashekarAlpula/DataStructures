/*
 * heapSort.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<stdlib.h>

void PrintArray(int A[], int n);
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
class Heap{

	int capacity;
	int size;
	bool isMin;
public:
	int *arr;
	Heap(int n, bool zisMin){
		capacity = n;
		size = 0;
		isMin = zisMin;
		arr = (int *)malloc(sizeof(int)*n);
	}
	bool Compare(int a, int b){
		if(isMin)
			return a < b;
		else
			return a > b;
	}
	void PreLocateUp(int id){
		if(id <= 0)
			return;
		int p = (id -1)/2;
		if(Compare(arr[id], arr[p])){
			swap(arr[id], arr[p]);
			PreLocateUp(p);
		}
	}
	void PreLocateDown(int id){
		int l = 2*id +1;
		int r = l +1;
		//printf("\n i %d l %d r %d ", id, l,r);

		int minorMax = id;
		if(id >= size)
			return;

		if(l < size && Compare(arr[l], arr[id])){
			minorMax = l;
			//printf("\n minorMax %d A[id] %d A[l] %d", minorMax, arr[id], arr[minorMax]);
		}
		if(r < size && Compare(arr[r], arr[minorMax])){
			minorMax = r;
			//printf("\n minorMax %d A[id] %d A[r] %d", minorMax, arr[id], arr[minorMax]);
		}

		if(minorMax != id){
			swap(arr[id], arr[minorMax]);
			//printf("\n minorMax %d A[id] %d A[minorMax] %d", minorMax, arr[id], arr[minorMax]);
			PreLocateDown(minorMax);
		}
	}

	void Insert(int data){
		if(size >= capacity){
			printf("\n failed to insert as heap is full %d\n", size);
			return;
		}
		arr[size++] = data;
		PreLocateUp(size-1);
	}
	int GetMinorMax(){
		return arr[0];
	}
	int DeleteMinOrMax(){
		int x = arr[0];
		arr[0] = arr[--size];

		PreLocateDown(0);
		PrintArray(arr, size);
		return x;
	}
	void HeapifyanArray(int A[], int n){
		for(int i = 0; i < n; i++)
			arr[i] = A[i];
		size = n;
		int idx = (n -1)/2;
		for(; idx >= 0; idx--){
			PreLocateDown(idx);
		}
		printf("\n Heap array \n");
			PrintArray(arr, n);
	}

	int GetSize(){
		return size;
	}
};



Heap *BuildHeap(int A[], int n){
	Heap *h = new Heap(n, false);
	h->HeapifyanArray(A, n);
	return h;
}

void HeapSort(int A[], int n){
	Heap *h = BuildHeap(A, n);
	int size = h->GetSize();
	printf("\n Size %d \n", size);
	//return;
	while(h->GetSize() > 0){
		int max = h->DeleteMinOrMax();
		printf("\n Max %d size %d", max, h->GetSize());
		A[h->GetSize()] = max;
		//size--;
	}
}
void PrintArray(int A[], int n){

	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d ", A[i]);
}
int main(){
	int A[] = {2,4,9,6,3,8,1,5};
	int n = (sizeof(A)/sizeof(A[0]));
	PrintArray(A, n);
	HeapSort(A,n);
	PrintArray(A, n);
	return 0;
}
