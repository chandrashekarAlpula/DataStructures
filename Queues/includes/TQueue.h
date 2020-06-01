/*
 * Queue.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
class TQueue{

	int mFront;
	int mRear;
	T *mQueuedata;
	unsigned int mCapacity;
	unsigned int mSize;

	public:
	TQueue(int cap){
		mFront = -1;
		mRear = -1;
		mCapacity = cap;
		mQueuedata = (T *)malloc(sizeof(T)*mCapacity);
		mSize = 0;

	}
	bool RemoveElement(T &data){
		if(mSize <= 0){
			cout << "Queue is empty" <<  endl;
			return false;
		}
		data = mQueuedata[mFront--];
		mSize--;
		return true;
	}

	bool AddElement(T &data){
		if(mRear == mCapacity || mRear == mFront){
			cout << endl << "Queue is full " << endl ;
			return false;
		}
		mQueuedata[++mRear] = data;
		mSize++;
	}
	bool EnQueue(T data){
		if(mQueuedata == NULL){
			std::cout << std::endl << "Data Structure not initialized "  << std::endl;
			return false;
		}
		if(isFull())
		{
			std::cout << std::endl << "Queue is Full " << std::endl;
			return false;
		}
		mQueuedata[(++mRear%mCapacity)] = data;
		mSize++;
	}

	T DeQueue(){
		if(isEmpty()){
			std::cout << std::endl << "DQueue is empty "  << std::endl;
		}else {
			T data = mQueuedata[++mFront];
			//mQueuedata[(mFront++)] = -1;
			//printf("\n Front is %d size is %d \n", mFront, mCapacity);
			mFront = mFront%mCapacity;
			mSize--;
			return data;
		}
	}

	bool isEmpty(){
		return (mSize == 0);
	}
	bool isFull(){
		return (mSize == mCapacity);
	}
};



