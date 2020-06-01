#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

struct List{
    int data;
    List *next;
    List(int d){
        data = d;
        next = NULL;
    }
};
class Queue{
    List *front;
    List *rear;
    int size;
public:
    Queue(){
        front = rear = NULL;
        size = 0;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    int Size(){
        return size;;
    }
    
    void Enqueue(int d){
        List *node = new List(d);
        if(size == 0){
            front = rear = node;
            size++;
            return;
        }
        rear->next = node;
        rear = rear->next;
        size++;
    }
    
    int Dequeue(){
        if(isEmpty())
            return -1;
        List *n = front;
        int d = n->data;
        front = n->next;
        size--;
        if(size == 0)
            front =  rear = NULL;
        delete n;
        return d;
    }
};

int GetElement(map<int, int> &m1, int val){
    map<int, int>::iterator it = m1.find(val);
    if(it != m1.end()){
        return it->second;
    }
    return -1;
}

int UnlockKey(int A[], int n,int k1, int k2){
    Queue *q = new Queue();
    //long key  = 1;
    map<int , int> timeMap;
    timeMap[k1] = 0;
    q->Enqueue(k1);
    int cnt =  0;
    while(!q->isEmpty()){
        int k = q->Dequeue();
        //cout << " " << k ;
        if(k == k2){
            return GetElement(timeMap, k);
        }
        for(int i = 0; i < n; i++){
            cnt++;
            long key = (((long)k) * A[i]) % 100000;
            int x = GetElement(timeMap, (int)key);
            if(x == -1){
                q->Enqueue((int)key);
                timeMap[(int)key] = GetElement(timeMap, k) + 1;
            }
        }
    }
    return -1;
}

int main(){
    int k1, k2, N;
    
    cin >> k1 >> k2 >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    printf("%d", UnlockKey(arr, N,k1, k2));
    return 0;
}
