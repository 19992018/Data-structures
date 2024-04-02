//https://www.onlinegdb.com/online_c++_compiler TEST CODE HERE
//Hash table(s) --> A hash table is a data structure.
//We'll therefore create it using a class with properties and methods
#include <iostream>
#include <vector> //vector used to increase array size dynamically.
using namespace std;
class Hashtable{
	int tablesize;
	// a pointer to a vector named table to store the elements of the hash table.
	vector<int> *table; // this vector points to a vector named table
						
	
	public:
		//constructor
	// The constructor of the class takes an integer size as a parameter 
	// and initializes the tablesize member variable with it. line 18	
	Hashtable(int size){
		this->tablesize=size;
		// constructor DYNAMICALLY allocates an array of vectors of integers with the 
		// size tablesize using the new keyword.
		table = new vector<int>[tablesize]; // table is a new vector of size tablesize
		}
	
	// a hash function named hashfunction that takes an integer k as a parameter 
	// and returns the HASH VALUE for that key.	 HASH VALUE == INDEX DETERMINANT
	int hashfunction(int k){
		// hash value is calculated using the formula (2*k+3) % tablesize
		return ((2*k+3) % tablesize);
	}
	
	// a function named insertvalues that takes an integer k as a parameter and inserts it into the hash table.
	void insertvalues(int k){
		// this function first calculates the hash value for the key k using the hashfunction 
		// and stores it in the variable index.
		int index= hashfunction(k);
		//Push value you have into index
		// this function then pushes the value k into the vector at the index index of the table array (*table vector?).
		table[index].push_back(k);
	}
	
	// a function named display that displays the contents of the hash table.
	void display(){
		// this function iterates over each index of the table array and prints the index
		for (int i=0; i<tablesize; i++){
			cout<<i<<":";
			
			//followed by the values stored at that index, separated by arrows.
			for(int x:table[i])
			cout<<x<<"-->";

			cout<<"\n";	}
	}
};

int main(){
	int i, n, size, x;
	cout<<"Enter size of the table: ";
	cin>>size;
	//an instance of the Hashtable class named h with the given size.
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
