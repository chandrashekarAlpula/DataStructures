/*
 * LruMain.cpp
 *
 *  Created on: Mar 6, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<iostream>
#include "TLRUCache.h"
#include<algorithm>

using namespace std;

void Fun2(){
	LRUCache<int, std::pair<int, int> > lruCache(4);
	for(int i = 1 ; i <= 6; i++){
		int k = i % 6;
		int prod = k * 10;
		std::pair<int, int> valPair((k*10), (k*100));
		lruCache.insert(k, valPair);
	}
	int k, v;
	cin  >> k;
	std::pair<int, int> valPair;
	if(lruCache.find(k, valPair)){
		cout << "Found value " << valPair.first <<  ", " << valPair.second << " for the key "  << k << endl;
	}else{
		cout << "Could not found the value for the key " << k << endl;
	}
}

/*void Fun1(){
	TLRUCache<std::string, std::string> lruCache(5);
		std::string k ="a";
		std::string v ="aa";
		lruCache.insert(k , v);

		k = "b";
		v = "bb";
		lruCache.insert(k , v);

		k = "c";
		v = "cc";
		lruCache.insert(k , v);

		k = "d";
		v = "dd";
		lruCache.insert(k , v);

		k = "e";
		v = "ee";
		lruCache.insert(k , v);

		k = "a";
		v = "aa";
		lruCache.insert(k , v);

		k = "f";
		v = "ff";
		lruCache.insert(k , v);


		cin >> k;
		if(lruCache.find(k, v)){
			cout << "Found value " << v << " for the key "  << k << endl;
		}else{
			cout << "Could not found the value for the key " << k << endl;
		}
}*/

int main(){
	Fun2();
	return 0;

}


