/*
 * Queue.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>

using namespace std;

template<class T>
class Queue{

	int mFront;
	int mRear;
	T *mQueuedata;
	unsigned int capacity;
	unsigned int size;

	public:
	Queue(int cap){
		mFront = -1;
		mRear = -1;
		capacity = cap;
		mQueuedata = (T *)malloc(sizeof(T)*capacity);
		size = 0;

	}
	bool RemoveElement(T &data){
		if(size <= 0){
			cout << "Queue is empty" <<  endl;
			return false;
		}
		data = mQueuedata[mFront--];
		size--;
		return true;
	}

	bool AddElement(T &data){
		if(mRear == capacity || mRear == mFront){
			cout << endl << "Queue is full " << endl ;
			return false;
		}
		mQueuedata[++mRear] = data;
		size++;
	}

};

int main(){

	return 0;
}



