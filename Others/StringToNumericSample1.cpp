/*
 * StringToNumericSample1.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#define INPUTLEN 7

using namespace std;
char HashCode[26] ={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','8','9','9','9'};


char *inputStr[INPUTLEN] = {"3", "run", "amazon", "pun", "sun", "sum","xxx"};
//char *inputStr[] = {"3", "run", "amazon", "pun", "sun"};
class List{

public :
	List(){
		numString = NULL;
		ipStr = NULL;
	}
	List(char *nums, char *ips){
		numString  = nums;
		ipStr = ips;
		subList = NULL;
		next = NULL;

	}
	char *numString;
	char *ipStr;
	List *subList;
	List *next;
};

List *headL = NULL;

void TraverList(List **head){
	List *node = *head;
	cout << endl ;
	while(node != NULL){
		//printf("\n \n ListHead addr %u \n", node);
		cout << node->numString << " "  << node->ipStr << endl;
		List *sList = node->subList;
		while( sList != NULL){
			cout << sList->numString << " "  << sList->ipStr << endl;
			sList = sList->subList;
		}
		node = node->next;
	}
}

bool InsertToSubList(List **head, List *newNode){
	int status = strcmp((*head)->ipStr, newNode->ipStr);
	List *tmpNode = *head;
	if(status > 0){ // Swap the head pointer
		//cout << endl << "C2  " << tmpNode->ipStr << " " <<  newNode->ipStr << " " << status  ;
		*head = newNode;
		(*head)->subList = tmpNode;
		(*head)->next = (tmpNode)->next;

		tmpNode->subList = NULL;
		tmpNode->next = NULL;
		//cout << endl << "C21 " << (*head)->ipStr << " " <<  (*head)->subList->ipStr << " " << status  ;

		return true;
	}
	List *prevNode = tmpNode;
	//cout << endl << "Inserting Slist " << src << " " << dest;
	while(tmpNode != NULL){
		//cout << endl << "C100  "  << tmpNode->ipStr;
		status = strcmp(tmpNode->ipStr, newNode->ipStr);
		if(status >= 0){ // Ascending .. swap the nodes
			newNode->subList = prevNode->subList;
			prevNode->subList = newNode;
			//cout << endl << "C3  "  <<  tmpNode->ipStr << " "  << newNode->ipStr  << " "<< status;
			return true;
		}else if(status < 0){
			prevNode = tmpNode;
		//	cout << endl << "C4  "  <<  tmpNode->ipStr << " "  << newNode->ipStr  << " "<< status;
			tmpNode = tmpNode->subList;
		}
	}
	prevNode->subList = newNode;
	return true;
}
bool InsertToList(List **head, char *src, char *dest){
	List *newNode = new List(dest, src);
	if(*head == NULL){
		*head = newNode;
		//cout << endl << "root NULL " << src << " " <<  dest  ;
		return true;
	}
	int status = strcmp(dest, (*head)->numString);
	if(status < 0){
		//cout << endl << "C1  " << src << " " <<  dest  ;
		newNode->next = (*head);
		*head = newNode;
		return true;
	}
	List *tmpNode = *head;
	List *prevNode = *head;

	while(tmpNode != NULL){
		status = strcmp(dest, tmpNode->numString);
		if(!status ){ // Numeric string matches
			InsertToSubList(&tmpNode, newNode);
			//This took lot of time to understand
			// As this is not modification in the tmp not reflecting the original node, adde the below logic.
			cout << endl << "Inserting Slist1 " << src << " " <<  dest <<" " << tmpNode->numString << " "<< status ;
			prevNode->next = tmpNode;
			return true;;
		}else  if(status > 0){ // curr string is greater than stored one
			cout << endl << "Inserting Slist2 " << src << " " <<  dest <<" " << tmpNode->numString << " "<< status ;
			prevNode = tmpNode;
			tmpNode = tmpNode->next;
		}else{
			cout << endl << "Inserting Slist3 " << src << " " <<  dest <<" " << tmpNode->numString << " "<< status ;
			newNode->next = prevNode->next;
			prevNode->next = newNode;
			return true;

		}
	}
	return true;
}

bool ValidateInput(char *src, unsigned int srcLen, char *dest){	//cout << "Input String " << src << endl;

	stringstream st;
	for(int i=0; i<srcLen; i++){
		if(src[i] < 'a' || src[i] > 'z'){
			return false;
		}
		//cout << HashCode[(src[i] - 'a')] ;
		dest[i] =  HashCode[(src[i] - 'a')];
	}
	//printf("\n Dest add %s ", dest);
	return true;
}
int main(){

	std::string output;
	cout << endl ;
	for(int i=0; i<INPUTLEN; i++){
		unsigned int len = strlen(inputStr[i]);
		char *dest =  NULL;
		dest = (char *)malloc(len +1);
		memset(dest,'\0',len+1);
		//cout << endl << "Input Str " << inputStr[i] ;
		//printf("\n Dest1 add %u \n ", dest);
		if( !ValidateInput( inputStr[i], len, dest) ){
			free(dest);
			dest = NULL;
			//cout << endl << "Wrong Input "  << inputStr[i] <<  endl ;
			continue;
		}
		//cout <<  inputStr[i] << "  " << dest << endl;
		InsertToList(&headL, inputStr[i], dest);
	}
	cout << endl << "TRAVERSING ####"  ;
	TraverList(&headL);
	return 0;
}

