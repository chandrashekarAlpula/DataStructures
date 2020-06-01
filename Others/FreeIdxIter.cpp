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
#include<vector>

using namespace std;
#define MAX_CNT 37
bool isStart = true;


struct CGIs{
	CGIs(std::string str, int x){
		key = str;
		cnt = x;
		slot = 0.0f;
		idx = 0;
	}
	std::string key;
	int cnt;
	unsigned int idx;
	double slot;
};

struct  myCmp{
	bool operator()(const CGIs &a, const CGIs &b) const{
		return b.cnt <= a.cnt;
	}
};

typedef std::map<std::string, CGIs, myCmp> MAP;
typedef std::set<CGIs, myCmp> SET;
typedef std::vector<CGIs> VEC;

SET cgiSet;
VEC cgiVec;

void InitCgi(SET &cgiSet, unsigned int &totalCount){

	 cgiSet.insert( CGIs("A", 16) );
	 cgiSet.insert( CGIs("B", 9) );
	 cgiSet.insert( CGIs("C", 6) );
	 cgiSet.insert( CGIs("D", 6) );

	/*cgiVec.push_back(CGIs("B", 16));
	 cgiVec.push_back(CGIs("B", 16));
	 cgiVec.push_back(CGIs("B", 16));
	 cgiVec.push_back(CGIs("B", 16));*/

	 SET::iterator itr = cgiSet.begin();
	 unsigned int vecIndex = 0;
	 while(itr != cgiSet.end()){
		 totalCount += itr->cnt;
		 itr++;
	 }

	 //Calculate the Average
	itr = cgiSet.begin();
	 while(itr != cgiSet.end()){
		 CGIs cgiObj = *itr;
		 cgiObj.idx = vecIndex++;
		 cgiObj.slot = ( (double)totalCount ) / ((double)cgiObj.cnt);
		 cgiVec.push_back(cgiObj);
		 itr++;
	 }
}



 int GetFreeIndex(std::set<std::size_t> &freeIndexSet, std::deque<std::string> &target, unsigned int TotCnt, std::size_t indexFactor, CGIs &cgiObj){
	 std::set< std::size_t >::iterator indexIter = freeIndexSet.begin();
	 std::size_t cnt = 1;
	 std::size_t idx = 0;
	 std::size_t reqCount = 0;
	 std::string &key = cgiObj.key;
	 indexFactor = ::floor(cgiObj.slot);
	 int reqToSpread = cgiObj.cnt;
	 cout << endl << "CGI " << key  << " Slot " << cgiObj.slot <<" and "  << key << " Count " << cgiObj.cnt <<" Index Factor "<< indexFactor <<  endl;
	 int tmp = cgiObj.slot * 100;
	 tmp = tmp % 100;
	 unsigned int numUeHigherThr = ::ceil((double) (tmp *  reqToSpread) /100 );
	 cout << endl << "Modulus is " << tmp << " Num Thre " << numUeHigherThr << endl;
	 if ( indexFactor == 0 ){
		while ( indexIter != freeIndexSet.end() && idx  <  TotCnt && reqCount < reqToSpread){
			cout << "Index Iterator " << *indexIter << " reqCount " << reqCount <<  endl;
			target[*indexIter] = key;
			freeIndexSet.erase(indexIter++);
			idx = idx + 2;
			/*if(reqCount < numUeHigherThr){
				idx++;
			}
			if(isStart){
				idx--;
				isStart = false;
			}*/
			indexIter = freeIndexSet.upper_bound(idx);
			cnt++;
			reqCount++;
			cgiObj.cnt--;
		}
	 }else{
		 while ( indexIter != freeIndexSet.end() && idx < TotCnt && reqCount < reqToSpread){
			 cout << "Index Iterator " << *indexIter << endl;
			 target[*indexIter] = key;
			 freeIndexSet.erase(indexIter++);
			 idx += indexFactor;
			 /*if(reqCount < numUeHigherThr ){
				idx++;
			}*/
			if(isStart){
				idx--;
				isStart = false;
			}
			indexIter = freeIndexSet.upper_bound(idx);
			cnt++;
			reqCount++;
			cgiObj.cnt--;
		 }
	 }
	 if(indexIter == freeIndexSet.end()){
		 cout << endl << " No Slot left returning " << endl;
	 }
	 cout << " Processed Count " << reqCount << " CGI Count " << cgiObj.cnt << " Idx " << idx << endl ;
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

	//cgiMap[std::string("A")] = CGIs(16);
	InitCgi(cgiSet, totalCnt);

	for ( std::size_t indexIter = 0; indexIter < totalCnt ; ++indexIter ){
		freeIndexSet.insert(indexIter);
	}
	myQueue.assign(totalCnt, "NULL");
	std::size_t reqCount = 0;
	cout << endl << "Total Count " << totalCnt << endl;
	while(reqCnt < totalCnt){
		VEC::iterator itr = cgiVec.begin();
		while(itr != cgiVec.end()){
			CGIs cgiObj = *itr;
			reqCnt += GetFreeIndex(freeIndexSet, myQueue, totalCnt, indexFactor, cgiObj);
			cgiVec[cgiObj.idx] = cgiObj;
			itr++;
			//cgiSet.insert(cgiObj);
		}
		cout << "Request Processed " << reqCnt << endl;
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






