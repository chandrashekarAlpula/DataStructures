/*
 * TLRUCache.h
 *
 *  Created on: Feb 24, 2018
 *      Author: chandra.shekhar
 */

#ifndef DS_OTHERS_TLRUCACHE_H_
#include<iostream>
#include<map>

#define DS_OTHERS_TLRUCACHE_H_
template<typename T1, typename T2>
class LRUCache{
	template<typename T3>
	struct QNode{
		T3 key;
		QNode *prev, *next;
		QNode(T3 d){
			key = d, prev = next = NULL;
		}
	};
	template<typename T4>
	struct MapData{
		T4 data;
		QNode<T4> *node;

		MapData(T4 d, QNode<T4> *n){
			data = d;
			node = n;
		}
	};
	typedef std::map<T1, MapData<T2> *> LRUMAP;
private:
	LRUMAP mLruMap;
	QNode<T1> *mFront, *mRear;
	unsigned long int mSize;
	unsigned long int mCapacity;
	bool IsQueueIsEmpty(){
		return mSize == 0;
	}
	bool IsQueueFull(){
		return mSize == mCapacity;
	}
	void Dequeu(QNode<T1> *node = NULL){
		if(IsQueueIsEmpty())
			return;
		QNode<T1> *tempNode = NULL;
		if(node == NULL || node == mFront){ //Removing Front element
			node = mFront;
			mFront = mFront->next;
			if(mFront)
				mFront->prev = NULL;
			else
				mRear = mFront; //Assigning NULL
		}else{
			if(node == mRear){
				mRear = mRear->prev;
				mRear->next = NULL;
			}else{
				tempNode = node->next;
				if(tempNode){
					tempNode->prev = node->prev;
					if(tempNode->prev)
						tempNode->prev->next = tempNode;
				}
			}
		}
		if(node){
			delete node;
		}
		mSize--;
		if(IsQueueIsEmpty())
			mRear = mFront = NULL;
	}
	bool GeFront(T1 &key){
		if(IsQueueIsEmpty())
			return false;
		key =  mFront->key;
		return true;
	}

	QNode<T1> *Enqueue(T1 &d){
		if(IsQueueFull())
			return NULL;
		QNode<T1> *node = new QNode<T1>(d);
		if(IsQueueIsEmpty()){
			mFront = mRear = node;
		}else{
			mRear->next = node;
			node->prev = mRear;
			mRear = mRear->next;
		}
		mSize++;
		return node;
	}
public:
	TLRUCache(int capacity){
		mCapacity = capacity;
		mSize = 0;
		mFront = mRear = NULL;
		mLruMap.clear();
	}
	void insert(T1 &key, T2 &value){
		typename LRUMAP::iterator itr = mLruMap.find(key);
		if(itr != mLruMap.end()){
			std::cout << "Found key in map  " << key << std::endl;
			Dequeu(itr->second->node);
			itr->second->node = Enqueue(key);
		}else{
			if(IsQueueFull()){
				T1 oldKey;
				GeFront(oldKey);
				std::cout << "Key " << key << " old Key Vlaue is " << oldKey << std::endl;
				typename LRUMAP::iterator oldItr = mLruMap.find(oldKey);
				if(oldItr != mLruMap.end()){
					std::cout << "Found Old key in map  " << std::endl;
					delete oldItr->second;
					mLruMap.erase(oldItr++);
				}
				Dequeu();
			}
			QNode<T1> *node = Enqueue(key);
			MapData<T2> *md = new MapData<T2>(value, node);
			mLruMap[key] = md;

		}
	}

	bool find(T1 &key, T2 &value){
		typename LRUMAP::iterator itr = mLruMap.find(key);
		if(itr != mLruMap.end()){
			value = itr->second->data;
			return true;
		}
		return false;
	}

	void remove(T1 &key){
		typename LRUMAP::iterator itr = mLruMap.find(key);
		QNode<T1> *node = NULL;
		if(itr != mLruMap.end()){
			node = itr->second->node;
			delete itr->second;
			mLruMap.erase(itr++);
		}
		if(node)
			Dequeu(node);
	}

};

#endif /* DS_OTHERS_TLRUCACHE_H_ */
