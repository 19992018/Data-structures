//Hash table is a data structure.
//use class to create it. Methods: constructor, hashfunction, insert, print vals

//Basics
#include <iostream>
#include<vector>
using namespace std;

class Hashtable{
	int tablesize;
	vector<int> *table;
	
	public:
		Hashtable(int size){
			this->tablesize =size;
			table = new vector<int>[tablesize];
		}
		
		int hashfunction(int k){
			return (2*k+3) % tablesize;
		}
		
		void insertvalues(int k){
			int index=hashfunction(k);
			table[index].push_back(k);
		}
		void printvalues(){
			for(int i=0; i<tablesize; i++){
				cout<<i<<" : ";
				for(int x: table[i])
					cout<<x<<"-->";
				
				cout<<"\n";				
			}
		}
		
};


int main(){
	int i,n,x,size;
	cout<<"What is your table size:";
	cin>>size;
	Hashtable h(size);
	
	cout<<"How many values?";
	cin>>n;
	for(i=0; i<n; i++){
		cin>>x;
		h.insertvalues(x);
	}
	h.printvalues();
}
