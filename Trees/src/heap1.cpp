/*
 * test3.cpp
 *
 *  Created on: Dec 29, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>

//#include"THeap.h"
//typedef std::priority_queue<int, std::vector<int>, std::greater<int>> HPQ;
//typedef std::priority_queue<int, std::vector<int>, std::less_equal<int>>  LPQ;

//std::priority_queue<int, std::vector<int>, std::less_equal<int> > Hq;
//std::priority_queue<int, std::vector<int>, std::greater<int>  >  Lq;

using namespace std;
class Heap{
    int mIsmin;
    int mSize;
    int mCapacity;
    int *data;
  public :
    Heap(bool isMin, int cap = 100){
        mIsmin = isMin;
        mSize = 0;
        mCapacity = cap;
        data = (int *)malloc(mCapacity*sizeof(int));
    }
    bool empty(){
        return mSize == 0;
    }
    int size(){
        return mSize;
    }
    int top(){
        return data[0];
    }
    void pop(){
        data[0] = data[--mSize];
        heapifyDown(0);
    }

    void push(int v){
        data[mSize++] = v;
        heapifyUp(mSize-1);
    }
    void PrintHeap(){
		printf("\n Print Heap %s \n", (mIsmin == true ? "MIN" : "MAX"));
		for(int i=0; i<mSize; i++)
			cout << " " << data[i];

		printf("\n");
	}
   private:
   void heapifyDown(int idx){
        if(idx >= mSize)
            return;
        int min = idx;
        int l = 2*idx +1;
        int r = l + 1;
        if( l < mSize && ( (!mIsmin && data[l] > data[idx]) || (mIsmin && data[l] < data[idx])) )
            min = l;
        if( r < mSize && ( (!mIsmin && data[r] > data[min]) || (mIsmin && data[r] < data[min])) )
            min = r;
        if(min != idx){
        	swap(data[idx], data[min]);
            heapifyDown(min);
        }
    }
    void heapifyUp(int idx){
        if(idx == 0)
            return;
        int parent = idx/2;
        if( (mIsmin && data[parent] > data[idx]) || (!mIsmin && data[parent] < data[idx])){
            swap(data[parent], data[idx]);
            heapifyUp(parent);
        }
    }
};

Heap Hq(false);
Heap Lq(true);

int main(){


	int N ;

	std::cin >> N;
	std::cout<<endl;
	printf("\n");
	for(int i=0; i<N; i++){
		int a;
		cin >> a;
		if(Hq.empty()){
			Hq.push(a);
			//Hq.PrintHeap();
		}
		else{
			if(Hq.size() <= Lq.size()){
				if(a > Lq.top()){
					int v = Lq.top();
					Lq.pop();
					Hq.push(v);
					Lq.push(a);
				}else{
					Hq.push(a);
				}
			}else{
				if(a < Hq.top()){
					int v = Hq.top();
					Hq.pop();
					Hq.push(a);
					Lq.push(v);
				}else{
					Lq.push(a);
				}
				//printf("\n MIN A  %d  Htop %d\n", A[i], Hq.top());
			}
		}
		if(Hq.size() == Lq.size()){
			double d = ((double)Hq.top() + (double)Lq.top())/2;
			printf("%0.1f \n", d);
		}
		else if(Lq.size() > Hq.size())
			printf("%0.1f \n", (double)(Lq.top()) );
		else
			printf("%0.1f \n", (double)(Hq.top()) );
	}
	Lq.PrintHeap();
	Hq.PrintHeap();

	return 0;
}



