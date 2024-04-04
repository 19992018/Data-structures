//Merge sort my second attempt
//Functions coz its an algorithm
//Basics:
#include <iostream>
#define size 50
using namespace std;

//Declare variables 
int i, j, n;
int array[size];

//4 functions:insert, merge, mergesort, print (all void)

void insertvalues(){
	cout<<"How many values: ";
	cin>>n;
	cout<<"Enter the values: ";
	for(i=0; i<n; i++){
		cin>>array[i];
	}
}

void merge(int array[], int low, int mid, int high){
	//Declare variables
	i=low;
	j=mid+1;
	int k= low;
	int temp[n];
	
	//3 while loops
	//while 1 merges both arrays concurrently
	while(i<=mid && j<=high){
		if(array[i]<array[j]){
			temp[k]=array[i];
			k++;
			i++;
		} else{
			temp[k]=array[j];
			k++;
			j++;
		}
	} 
	
	//mop remaining values
	while(i<=mid){
		temp[k]=array[i];
		k++;
		i++;
	}
	
	while(j<=high){
		temp[k]=array[j];
		k++;
		j++;
	}
	
	//Map imaginary array values onto actual array
	for(i=low; i<k; i++){ //******* 
		array[i] = temp[i];
	}	
	
}

void mergesort(int array[], int low, int high){
	int mid;
	//Done till i=j i.e one value
	if(low<high){
		mid= (low+high)/2;
		mergesort(array, low, mid);
		mergesort(array, mid+1, high);
		
		merge(array, low, mid, high);
	}
}

void printvalues(){
	for(i=0; i<n; i++){
		cout<<array[i]<<" ";
	}
}

int main(){
	insertvalues();
	mergesort(array, 0, n-1);
	printvalues();
	
}
