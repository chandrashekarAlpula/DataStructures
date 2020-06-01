/*
 * DisjointSet3.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: chandra.shekhar
 */
#include<iostream>
#define MAX 1000
int dHash[MAX];
struct DSet{
	int data;
	int rank;
	int parent;

	DSet(int d){
		data = d;
		parent = d;
		rank = 0;
	}
};

void Init(){
	for(int i = 0; i < MAX; i++)
		dHash[i] = i;
}
void MakeSet(int d){
	DSet s(d);
}

DSet &Find(DSet &s){

}



