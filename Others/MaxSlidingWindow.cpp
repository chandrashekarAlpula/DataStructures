/*
 * MaxSlidingWindow.cpp
 *
 *  Created on: Dec 10, 2016
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;

#define N 20

int main(){
	//int A[] = {1,3,-1,-3,5,3,6,7};
	int A[] = {12, 1, 78, 90, 57, 89, 56};
	int w = 3;
	int n = sizeof(A)/sizeof(A[0]);
	int B[n];
	int j = 0;
	cout << endl << "Size of Array is " << n << endl ;
	deque<int> dq;
	for(int i=0; i<w; i++){
		// Remove all the previous elements which are less than the
		// Current element.
		while(!dq.empty() && A[i] >= A[dq.back()]){
			//cout << " A[i] " << A[i] << " Back "<<  A[dq.back()] << " : ";
			dq.pop_back();
		}

		dq.push_back(i);
	}
	//cout << "Front element is " << dq.front() << endl;
	for(int i = w; i<n; i++){
		// Print the first front element
		cout << A[dq.front()] << "\t";

		//Remove all previous window elements
		while(!dq.empty() && dq.front() <= (i-w))
			dq.pop_front();

		while(!dq.empty() && A[i] >= A[dq.back()])
			dq.pop_back();

		dq.push_back(i);
		deque<int>::iterator itr =dq.begin();
		/*while(itr != dq.end()){
			cout << "Qeueu ele " << *itr << "\t" ;
			itr++;
		}
		cout << endl;*/
	}
	cout << A[dq.front()] << endl;
	return 0;
}



