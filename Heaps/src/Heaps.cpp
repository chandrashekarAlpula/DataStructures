/*
 * Heaps.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<iostream>


using namespace std;
class MinHeap{
private:
	int *heap;
	int capacity;
	int size;
	MinHeap(int heapSize){
		capacity = heapSize;
		size = 0;
		heap = (int *)malloc(capacity * sizeof(int));
	}
	void Insert(int data){
		if(size >= capacity)
		{
			printf("\n Exceeded the capacity %d cannot insert the item %d", size, data);
			return;
		}
		heap[size++] = data;
		HeapifyUp(size-1);

	}
	void Delete(int data){
		if(size == 0){
			printf("\n Size is empty cannot delete the item %d", data);
			return;
		}
		for(int i = 0; i < size; i++){
			if(heap[i] == data){
				printf("\n Deleted the element %d", heap[i]);
				heap[i] = heap[--size];
				HeapifyDown(i);
				return;
			}
		}
	}

	void HeapifyDown(int idx){
		if(idx > size/2)
			return;

		int leftc = 2*idx + 1;
		int rightc = leftc + 1;
		int min = idx;
		if(leftc < size && heap[leftc] < heap[idx])
			min = leftc;
		if(right < size && heap[rightc] < heap[min])
			min = rightc;
		if(min != idx){
			swap(heap[idx], heap[min]);
			HeapifyDown(min);
		}
	}


	void HeapifyUp(int idx){
		if(idx >= size || idx == 0)
			return;
		int parent = idx/2;
		if(heap[idx] < heap[parent]){
			swap(heap[idx], heap[parent]);
			HeapifyUp(parent);
		}
	}
};



