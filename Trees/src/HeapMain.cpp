/*
 * HeapMain.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "THeap.h"

int main(){

	Heap<int> *myHeap = new Heap<int>(6, true);
	myHeap->Insert(5);
	myHeap->Insert(6);
	myHeap->Insert(1);
	myHeap->Insert(8);
	myHeap->Insert(3);

	myHeap->PrintHeap();
	for(int i=0; i<5; i++){
		int x = 0 ;
		myHeap->ExtractMinOrMax(x);
		cout << endl << "Extracted value is " << x ;
		//myHeap->PrintHeap();
	}

	return 0;
}

