/*
 * FreeIdxIter.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: chandra.shekhar
 */
/*
 * FreeIndexItr.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: chandra.shekhar
 */

#include <iostream>
#include<stdio.h>
#include<math.h>
#include <map>
#include <set>
#include <deque>

using namespace std;
#define MAX_CNT 37



struct CGIs{
	CGIs(int x){
		cnt = x;
		slot = 0.0f;
	}
	int cnt;
	double slot;

};

struct  myCmp{
	bool operator()(const CGIs &a, const CGIs &b) const{
		return b.cnt > a.cnt;
	}
};

typedef std::map<std::string, CGIs, myCmp> MAP;

void InitCgi(MAP &cgiMap, unsigned int &totalCount){

	 cgiMap[std::string("A")] = CGIs(16);
	 cgiMap[std::string("B")] = CGIs(9);
	 cgiMap[std::string("C")] = CGIs(6);
	 cgiMap[std::string("D")] = CGIs(6);

	 MAP::iterator itr = cgiMap.begin();
	 while(itr != cgiMap.end()){
		 totalCount += itr->second.cnt;
		 itr++;
	 }

	 //Calculate the Average
	itr = cgiMap.begin();
	 while(itr != cgiMap.end()){
		 itr->second.slot = totalCount / itr->second.cnt;
		 itr++;
	 }
}



 int GetFreeIndex(std::set<std::size_t> &freeIndexSet, std::deque<std::string> &target, unsigned int TotCnt, std::size_t indexFactor, std::string &key, CGIs &cgiObj){
	 std::set< std::size_t >::iterator indexIter = freeIndexSet.begin();
	 std::size_t cnt = 1;
	 std::size_t index = 0;
	 std::size_t reqCount = 0;

	 cout << endl << "CGI " << key  << " Total Cnt " << TotCnt << endl;
	 if ( indexFactor == 0 ){
		while ( indexIter != freeIndexSet.end() && cnt <= TotCnt){
			cout << "Index Iterator " << *indexIter << " Cnt " << cnt <<  endl;
			target[*indexIter] = key;
			index = index + 2;
			freeIndexSet.erase(indexIter++);
			indexIter = freeIndexSet.lower_bound(index);
			cnt++;
			reqCount++;
			cgiObj.cnt--;
		}
	 }else{
		 while ( indexIter != freeIndexSet.end() && cnt <= TotCnt){
			 cout << "Index Iterator " << *indexIter << endl;
			 target[*indexIter] = key;
			 index += indexFactor;
			freeIndexSet.erase(indexIter++);
			indexIter = freeIndexSet.lower_bound(index);
			cnt++;
			reqCount++;
			cgiObj.cnt--;
		 }
	 }
	 cout << " Processed Count " << reqCount << endl ;
	 return reqCount;
 }

 void PrintQueue(std::deque<std::string> &target){
	 cout << endl << "Printing QUEUE " << endl;
	 std::deque<std::string>::iterator itr = target.begin();
	 while(itr != target.end()){
		 cout << *itr << endl;
		 itr++;
	 }
 }


int main ()
{

	std::set<std::size_t> freeIndexSet;
	std::size_t indexFactor = 0;
	std::deque<std::string> myQueue;
	int reqCnt = 0;
	unsigned int totalCnt = 0;
	unsigned int seq = 1;

	MAP cgiMap;
	cgiMap[std::string("A")] = CGIs(16);
	InitCgi(cgiMap, totalCnt);

	for ( std::size_t indexIter = 0; indexIter < totalCnt ; ++indexIter ){
		freeIndexSet.insert(indexIter);
	}
	myQueue.assign(totalCnt, "NULL");
	std::size_t reqCount = 0;

	while(reqCnt < totalCnt){
		MAP::iterator itr = cgiMap.begin();
		while(itr != cgiMap.end()){
			std::string key = itr->first;
			CGIs &cgiObj = itr->second;
			reqCnt += GetFreeIndex(freeIndexSet, myQueue, totalCnt, indexFactor, key, cgiObj);
			itr++;
		}

	}
/*
 * indexFactor = static_cast<std::size_t>(::round( (double) 1 / (double) (0.43243243) ));
	reqCnt += GetFreeIndex(freeIndexSet, myQueue, reqCnt, indexFactor, seq);

	indexFactor = static_cast<std::size_t>(::ceil( (double) 1 / (double) (0.086957) ));
	GetFreeIndex(freeIndexSet, myQueue, 2, indexFactor,seq++);

	indexFactor = static_cast<std::size_t>(::ceil( (double) 1 / (double) (0.304348) ));
	GetFreeIndex(freeIndexSet, myQueue, 7,indexFactor,seq++);

	indexFactor = static_cast<std::size_t>(::ceil( (double) 1 / (double) (0.086957) ));
	GetFreeIndex(freeIndexSet, myQueue, 2, indexFactor,seq++);
*/
	PrintQueue(myQueue);
	return 0;
}






