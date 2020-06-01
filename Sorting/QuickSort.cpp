#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void PrintArray(int A[], int n){
	cout << endl ;
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
}

int Partition(int A[], int low, int high){
	int pivot = A[low];
	int left = low;
	int right = high;

	while(left < right){

		while(A[left] <= pivot)
			left++;

		while(A[right] > pivot)
			right--;

		//cout << endl << "Left " << left << " right " << right << endl;
		if(left < right)
			swap(A[left], A[right]);
	}

	A[low] = A[right];
	A[right] = pivot;
	return right;

}

void QuickSort(int A[], int low, int right){
	if(low < right){
		int pivot = Partition(A, low, right);
		//cout << endl << "Pivot element " << pivot << " ELement "<< A[pivot] <<  endl;
		//PrintArray(A, 7);
		QuickSort(A, low, pivot-1);
		QuickSort(A, pivot+1, right);
	}
}

int main(){

	int A[] = {2,1,5,3,7,8,4};
	int n = sizeof(A)/sizeof(A[0]);
	PrintArray(A, n);
	QuickSort(A, 0, n-1);
	PrintArray(A, n);

	return 0;
}
