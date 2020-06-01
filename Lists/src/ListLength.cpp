#include<iostream>
using namespace std;

struct List{
    int data;
    List *next;
    List(int val){
       data = val;
       next = NULL;
    }
};
void InsertNode(List **head, int data){
    List *node = *head;
    List *newNode = new List(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(node->next)
        node = node->next;
    node->next = newNode;
}


//List length using iterative method ;
int ListLengthIterative(List *head){
    int cnt = 0;
    while(head){
        cnt++;
        head = head->next;
    }
    return cnt;
}

int ListLengthRecursive(List *head){
    int cnt = 0;
    if(head == NULL)
        return cnt;
    return (ListLengthRecursive(head->next) + 1);

}
int main(){
    List *head = NULL;
    for(int i = 1; i <= 10; i++)
        InsertNode(&head, i);
    int cnt = ListLengthRecursive(head);
    cout << "List length is " <<cnt << endl;
    return 0;
}
