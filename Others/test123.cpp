/*
 * test123.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: chandra.shekhar
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>

using namespace std;
char HashCode[26] ={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

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
		cout << endl << "C2  " << tmpNode->ipStr << " " <<  newNode->ipStr << " " << status  ;
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
			cout << endl << "C3  "  <<  tmpNode->ipStr << " "  << newNode->ipStr  << " "<< status;
			return true;
		}else if(status < 0){
			prevNode = tmpNode;
			cout << endl << "C4  "  <<  tmpNode->ipStr << " "  << newNode->ipStr  << " "<< status;
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
		//cout << endl << "root NULL " << src << " " <<  dest  << endl;
		return true;
	}
	int status = strcmp(dest, (*head)->numString);
	if(status < 0){
		//cout << endl << "C1  " << src << " " <<  dest << endl ;
		newNode->next = (*head);
		*head = newNode;
		return true;
	}
	List *tmpNode = *head;
	List *prevNode = *head;

	while(tmpNode != NULL){
		status = atoi(dest) - atoi(tmpNode->numString);
		//status = strcmp(dest, tmpNode->numString);
		cout << endl << "Inserting Slist " << src << " " <<  dest <<" " << tmpNode->numString << " "<< status << endl;
		if(!status ){ // Numeric string matches
			printf("\n HERE1 \n");
			InsertToSubList(&tmpNode, newNode);
			prevNode->next = tmpNode;
			return true;;
		}else  if(status > 0){ // curr string is greater than stored one
			//cout << endl << "Inserting Slist2 " << src << " " <<  dest <<" " << tmpNode->numString << " "<< status << endl;
			prevNode = tmpNode;
			tmpNode = tmpNode->next;
		}else{
			//cout << endl << "Inserting Slist1 " << src << " " <<  dest <<" " << tmpNode->numString << " "<< status << endl;
			newNode->next = prevNode->next;
			prevNode->next = newNode;
			return true;

		}
	}
	prevNode->next = newNode;
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
int main()
{
    unsigned int N = 0;
    char **str;
    cin >> N;
    for(int i=0; i<N; i++){
    	char tmpStr[1024];
    	scanf("%s", &tmpStr);
    	unsigned int len = strlen(tmpStr);
    	char *str = (char *)malloc(len+1);
    	char *numStr = (char *)malloc(len+1);
		memset(str,'\0',len+1);
		memset(numStr, '\0', len+1);
		strcpy(str, tmpStr);
		if( !ValidateInput(str, len, numStr) ){
			free(str);
			free(numStr);
			//cout << endl << "Wrong Input "  << str <<  endl ;
			continue;
		}
		//cout << endl << "Entered Input "  << str <<  endl ;
    	InsertToList(&headL, str, numStr);
    }
    cout << endl << "TRAVERSING ####"  ;
	TraverList(&headL);
	return 0;
    return 0;
}



