//QUICK SORT
//An algorithm- so we use functions
//the 4 functions: insert values, partition, quicksort, display
//only partition returns an integer

//Basics:
#include <iostream>
#define size 50
using namespace std;

//declare variables
int i, j, n;
int array[size];

void insertValues(){
	cout<<"How many values: ";
	cin>>n;
	for(i=0; i<n; i++){
		cout<<"Key in the value ";
		cin>>array[i];
	}
}

int partition(int array[], int low, int high){
	int pivotValue= array[low];
	i=low;
	j=high+1;
	
	while(i<j){
		do {
			i++;
		} while(array[i]<pivotValue);
		
		do {
			j--;
		} while(array[j]>pivotValue);
		if(i<j){
			swap(array[i], array[j]);
		}
	}
	swap(array[low], array[j]);
	return j;
	
}

void quicksort(int array[], int low, int high){
	if(low<high){
		int pivot = partition(array, low, high);
		partition(array, low, pivot-1);
		partition(array, pivot+1, high);
		//return;	
	}
}

void display(){
	for(i=0; i<n; i++){
		cout<<array[i];
	}
}

int main(){
	insertValues();
	quicksort(array, 0, n-1);
	display();
}
