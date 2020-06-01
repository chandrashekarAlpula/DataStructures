#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Heap{
public:

	int *arr;
	int size;
	int capacity;

	Heap(int capacity){
		this->capacity = capacity;
		size = 0;
		arr = (int *)malloc(sizeof(int)*(this->capacity ) );
		memset(arr, -1, sizeof(int)*(this->capacity));
	}
	void Insert(int data);
	int GetMin();
	void PercolateDown(int idx);
	void Hepify(int A[], int n);
	int GetKthSmallest(int rank);
	int GetKthSmallest1(int rank);
	void Print(){
		cout << endl  << "Printing Heap elements " << endl ;
		for(int i =0; i < size; i++){
			cout << arr[i]  <<" " ;
		}
		cout << endl ;
	}
	void swap(int &a, int &b){
		int tmp = a;
		a = b;
		b = tmp;
	}

};
void Heap::Insert(int data){

	if(arr == NULL || size >= capacity)
		return;

	arr[size++] = data;
	int idx = size -1;
	int parent = 0;
	while(idx > 0){
		parent = (idx -1)/2;
		if(arr[idx] < arr[parent])
			swap(arr[idx], arr[parent]);
		else
			break;
		idx = parent;
	}
	printf("Inserted element %d at %d and size is %d parent %d\n", data ,idx, size, parent);
}
void Heap::PercolateDown(int idx){
	if(size == 0)
		return;
	int min = idx;
	int left = 2*idx + 1;
	int right = left + 1;
	if(left < size && arr[left] < arr[idx])
		min = left;
	if(right < size && arr[right] < arr[min])
		min = right;
	if(min == idx){
		return;
	}
	swap(arr[idx], arr[min]);
	PercolateDown(min);

}
void Heap::Hepify(int A[], int n){
	memcpy(arr, A, sizeof(int)*n);
	size = n;
	int j = (size -1)/2;
	printf("\n Before Hepify size %d and last non leaf node %d\n", size,j);
	Print();
	for(int i = j; i >= 0; i--){
		PercolateDown(i);
		Print();
	}
}


int Heap::GetMin(){
	if(arr == NULL || size == 0)
		return -1;

	int min = arr[0];
	arr[0] = arr[--size];
	//arr[--size] = -1;
	PercolateDown(0);
	return min;
}

int Heap::GetKthSmallest(int rank){
	int min = 0;
	for(int i = 0; i < rank; i++)
		min = GetMin();
}

int Heap::GetKthSmallest1(int rank){
	Heap *h1 = new Heap(capacity);
	h1->Insert(arr[0]);
	printf("\n Printing H1");
	h1->Print();
	int min = 0;
	int idx, l, r;
	idx = 0;
	for(int i =0; i < rank; i++){
		min = h1->GetMin();
		printf("\n Min received is %d\n", min);
		l = 2*idx + 1;
		r = l + 1;
		if(l < size)
			h1->Insert(arr[l]);
		if(r < size)
			h1->Insert(arr[r]);

		idx++;
	}
	return min;
}
int main(){

	Heap *h = new Heap(20);
	h->Insert(5);
	h->Insert(1);
	h->Insert(3);
	h->Insert(2);
	h->Insert(4);
	h->Print();
	int kth = h->GetKthSmallest1(5);
	printf("\n 4th smallest element is %d \n", kth);
	h->Print();
	/*
	int A[] = {4,1,5,7,9,3,2,8};
	int n = sizeof(A)/sizeof(int);
	Heap *h1 = new Heap(20);
	h1->Hepify(A, n);
	h1->Print();
	*/
	return 0;
}
