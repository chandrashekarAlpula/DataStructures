/*
 * THeap.h
 *
 *  Created on: Dec 2, 2016
 *      Author: chandra.shekhar
 */
#include <iostream>
#include<cstdio>
#include<cstdlib>
#ifndef DS_TREES_INCLUDE_THEAP_H_
#define DS_TREES_INCLUDE_THEAP_H_

using namespace std;
template<class T>
class Heap{
	T *mHeapData;
	unsigned int mCapacity;
	unsigned int mSize;
	bool mIsMinHeap;
public:
	Heap(int cap, bool isMinHeap){
		mIsMinHeap = isMinHeap;
		mSize = 0;
		mCapacity = cap;
		mHeapData = (T *)malloc(sizeof(mCapacity*(sizeof(T))));
	}
	bool compare(T &a, T &b){
		if(mIsMinHeap)
			return a > b;
		else
			return b > a;
	}
	bool Heapify(bool isbottomUp, unsigned int idx){
		if(isbottomUp){ // Insert
			if(idx == 0)
				return true;
			unsigned int parent = (idx)/2;
			if(compare(mHeapData[parent] , mHeapData[idx])){
				swap(mHeapData[parent], mHeapData[idx]);
				Heapify(isbottomUp, parent);
			}
		}else{
			unsigned left = (2 * idx) +1;
			unsigned right = left +1 ;
			unsigned int minOrMax = idx;
			if(idx >= mSize)
				return true;

			if(left < mSize && compare(mHeapData[idx] , mHeapData[left]))
				minOrMax = left;
			if(right < mSize && compare(mHeapData[minOrMax] , mHeapData[right]))
				minOrMax = right;
			if(minOrMax != idx){
				swap(mHeapData[minOrMax], mHeapData[idx]);
				Heapify(isbottomUp, minOrMax);
			}
		}

	}
	bool empty(){
		return (mSize == 0);
	}
	T size(){
		return mSize;
	}
	void push(T &data){
		Insert(data);
	}
	bool Insert(T &data){
		if(mSize == mCapacity){
			cout << endl << "Heap is full cannot insert. Heap size " << mSize <<
						" and Capacity " << mCapacity << endl;
			return false;
		}
	//	cout << endl << "Inserting data " << data << endl ;
		mHeapData[mSize++] = data;
		Heapify(true, mSize-1);
		return true;
	}
	T top(){

		if(mSize == 0){
			cout << endl << "Heap is empty. size " << mSize << endl;
			return -1;
		}
		return mHeapData[0];
	}
	void pop(){
		if(mSize == 0){
			cout << endl << "Heap is empty. size " << mSize << endl;
			return ;
		}
		mHeapData[0] = mHeapData[--mSize];
		Heapify(false, 0);
		return ;
	}
	void pop(T &data){
		if(mSize == 0){
			cout << endl << "Heap is empty. size " << mSize << endl;
			return ;
		}
		data = mHeapData[0];
		mHeapData[0] = mHeapData[--mSize];
		Heapify(false, 0);
		return ;
	}
	void PrintHeap(){
		printf("\n Print Heap %s \n", (mIsMinHeap == true ? "MIN" : "MAX"));
		for(int i=0; i<mSize; i++)
			cout << " " << mHeapData[i];

		printf("\n");
	}
};
#endif /* DS_TREES_INCLUDE_THEAP_H_ */
