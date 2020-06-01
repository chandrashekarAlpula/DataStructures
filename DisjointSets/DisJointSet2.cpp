/*
 * DisJointSet2.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<iostream>
#define MAX 1000
using namespace std;


struct DSet{
	int data;
	int rank;
	DSet *parent;
	DSet(int d){
		data =d;
		parent = NULL;
		rank = 0;
	}
};

DSet *Dhash[MAX];

void MakeSet(int  d){
	DSet *s = new DSet(d);
	s->parent = s;
	Dhash[d] = s;
}

DSet *Find(DSet *s){
	if(s == s->parent)
		return s;
	s->parent = Find(s->parent);
	return s->parent;
}
void Union(int d1, int  d2){
	DSet *s1 = Find(Dhash[d1]);
	DSet *s2 = Find(Dhash[d2]);

	if(s1->parent == s2->parent)
		return;
	if(s1->rank > s2->rank)
		s2->parent = s1->parent;
	else if(s1->rank < s2->rank)
		s1->parent = s2->parent;
	else{
		s2->parent = s1->parent;
		s1->rank++;
	}
}

int Find(int d){
	DSet *parent = Find(Dhash[d]);
	return parent->data;
}
int main(){

	for(int i = 0; i < MAX; i++)
		Dhash[i] = NULL;

	MakeSet(1);
	MakeSet(2);
	MakeSet(3);
	MakeSet(4);
	MakeSet(5);
	MakeSet(6);
	MakeSet(7);

	Union(1,2);
	Union(2,3);
	Union(4,5);
	Union(6,7);
	Union(4,7);
	Union(1,5);


	cout << "1 Parent " << Find(1) << endl;
	cout << "2 Parent " << Find(2) << endl;
	cout << "3 Parent " << Find(3) << endl;
	cout << "4 Parent " << Find(4) << endl;
	cout << "5 Parent " << Find(5) << endl ;
	cout << "6 Parent " << Find(6) << endl ;
	cout << "7 Parent " << Find(7) << endl;
}



