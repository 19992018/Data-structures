//Quick sort:
//It's an algorithm thus functions will suffice
//BASICS:
#include <iostream>
#define size 100 //not include size 100
using namespace std;

//Deaclare the variables
int i,n,j;
int array[size];

//The functions
//1. Insert values
void insertValues(){
	cout<<"How many values: ";
	cin>>n;
	cout<<"Enter the values";
	for(i=0; i<n; i++){
		cin>>array[i];
	}
}

//2.Partition
int partition(int array[], int low, int high){
	int pivotValue = array[low];
	i= low;
	j= high + 1;
	
	while(i<j){
		do{
			i++;
		}while (array[i]<pivotValue);
		
		do{
			j--;
		}while (array[j]>pivotValue);
		
		if (i<j){
			swap(array[i], array[j]);
		}	
	}
	
	swap(array[low], array[j]);
	
	return j;
}

//3.Quicksort
void quicksort(int array[], int low, int high){
	if(low<high){
		int pivot= partition(array, low, high);
		quicksort(array, pivot+1, high);
		quicksort(array, low, pivot-1);
	}
	
}

//4. PrintValues
void printValues(){
	for(i=0; i<n; i++){
		cout<<array[i]<<" ";
	}
}

int main(){
	insertValues();
	quicksort(array, 0, n-1);
	printValues();
}
