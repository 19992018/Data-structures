//Hash table(s)
#include <iostream>
#include <vector>
using namespace std;
class Hashtable{
	int tablesize;
	vector<int> *table;
	
	public:
		//constructor
	Hashtable(int size){
		this->tablesize=size;
		table = new vector<int>[tablesize];
		}
		
	int hashfunction(int k){
		return ((2*k+3) % tablesize);
	}
	
	void insertvalues(int k){
		int index= hashfunction(k);
		//Push value you have into index
		table[index].push_back(k);
	}
	
	void display(){
		for (int i=0; i<tablesize; i++){
			cout<<i<<":";
			
			for(int x:table[i])
			cout<<x<<"-->";

			cout<<"\n";	}
	}
};

int main(){
	int i, n, size, x;
	cout<<"Enter size of the table: ";
	cin>>size;
	Hashtable h(size);
	
	cout<<" How many values ";
	cin>>n;
	for(i=0; i<n; i++){
		cout<<"Enter the value: ";
		cin>>x;
		h.insertvalues(x);
	}
	h.display();
}
