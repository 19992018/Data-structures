//Merge Sort
//This is an algorithm, thus functions will also suffice
//Basics:
#include <iostream>
#define size 100
using namespace std;

//Declare variables
int i, j, n;
int array[size];

//The functions
//1. Insert Values
void insertvalues(){
	cout<<"How many Values";
	cin>>n;
	cout<<"Enter the values";
	for(i=0; i<n; i++){
		cin>>array[i];
	}
}

//2. Merge
void merge(int array[], int low, int mid, int high){
	//3 while loops
	//Used to map values into imaginary array
	
	//Declare variables:
	i= low;
	j=mid+1;
	int k=low; //imaginary
	int temp[n];//Create a NEW imaginary array
	
	while(i<=mid && j<=high){
		if(array[i]<array[j]){
			temp[k]= array[i];
			k++;
			i++;
		} else {
			temp[k]=array[j];
			k++;
			j++;
		}
	}
	
	//Mop remaining values
	while(i<=mid){
		temp[k]= array[i];
		k++;
		i++;		
	}
	 
	while(j<=high){
		temp[k]=array[j];
			k++;
			j++;	
	}
	
	//Map imaginary array values to actial array
	for(i=low; i<k; i++){
		array[i] = temp[i];
	}
	
}

//3. MergeSort
void mergesort(int array[], int low, int high){
	int mid;
	//This happens until there is one element per array i.e low=high
	if(low<high){
		mid = (low+high)/2;
		mergesort(array, low, mid);
		mergesort(array, mid+1, high);
		
		merge(array, low, mid, high);
	}	
}

//4. PrintValues
void printvalues(){
	for(i=0; i<n; i++){
		cout<<array[i]<<" ";
	}
}

int main(){
	insertvalues();
	mergesort(array,0, n-1);
	printvalues();
}
