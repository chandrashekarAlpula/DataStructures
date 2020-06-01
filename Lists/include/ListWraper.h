/*
 * ListWraper.h
 *
 *  Created on: Nov 2, 2016
 *      Author: chandra.shekhar
 */

#ifndef DS_LISTS_INCLUDE_LISTWRAPER_H_
#define DS_LISTS_INCLUDE_LISTWRAPER_H_

class List;

void PrintList(List *head);
void InserNode(List **head, int val);
void DeleteNodeOnValue(List **head, int Val);
void DeleteNodeOnPos(List **head, int Pos);

class List{
public:
	int data;
	List *next;
	List(){
		data = 0;
		next = NULL;
	}

	List(int val){
		data = val;
		next = NULL;
	}

};


#endif /* DS_LISTS_INCLUDE_LISTWRAPER_H_ */
