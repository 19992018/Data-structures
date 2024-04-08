//MERGE SORT
//Algorithm so use functions to showcase
//4 functions: all void: getvalues, merge, mergesort, display

//Basics
#include <iostream>
#define size 50
using namespace std;

//Declare variable
int i,j,n;
int array[size];

void getvalues(){
	cout<<"How many values ";
	cin>>n;
	for (i=0; i<n; i++){
		cout<<"Key in the value ";
		cin>>array[i];
	}
}

void merge(int array[], int low, int mid, int high){
	i=low;
	j=mid+1;
	int k= low;
	int temp[n];
	
	while (i<=mid && j<=high){
		if(array[i]<= array[j]){ // <= or <?
			temp[k] = array[i];
			k++;
			i++;
		}else{
			temp[k]=array[j];
			k++;
			j++;
		}	
	}
	
	while(i<=mid){
		temp[k] = array[i];
		k++;
		i++;
	} 
	
	while(j<=high){
		temp[k] = array[j];
		k++;
		j++;
	}
	
	for(i=low; i<k; i++){
		array[i]=temp[i];
	}
}
	
void mergesort(int array[], int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		mergesort(array, low, mid);
		mergesort(array,mid+1, high);
		
		merge(array, low, mid, high);
	}	
}

void display(){
	for (i=0; i<n; i++){
		cout<<array[i]<<" ";
	}
}

int main(){
	getvalues();
	mergesort(array, 0, n-1);
	display();
		
}
