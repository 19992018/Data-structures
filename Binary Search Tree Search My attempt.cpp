//Binary search tree
//Search Algorithm
//Its a tree! A data structure// So use class or struct

//Basics
#include <iostream>
using namespace std;

//Struct
struct node{
	int data;
	node *left, *right;
};

//Tree creator
node *insertnodes(node *root, int item){
	if(root == NULL){
		node *newnode = new node;
		newnode->data= item;
		newnode->left= NULL;
		newnode->right= NULL;
		return newnode;
	}else if(item<root->data){
		root->left = insertnodes(root->left, item);
	} else{
		root->right = insertnodes(root->right, item);
	}

}

int search(node *root, int value, int& movesleft, int& movesright){
	if(root==NULL){
		return -1;
	} else if(root->data == value){
		return 0;
	} else if(value<root->data){
		movesleft++;
		return search(root->left, value, movesleft, movesright);
	}else{
		movesright++;
		return search(root->right, value, movesleft, movesright);
	}
}

int main(){
	node *root = NULL;
	int i, n, x, searchkey;
	cout<<"How many values ";
	cin>>n;
	cout<<"Enter the values: ";
	for(i=0; i<n; i++){
		cin>>x;
		root=insertnodes(root, x);
	}
	
	cout<<"Enter search key ";
	cin>>searchkey;
	int movesleft=0;
	int movesright=0;
	int result=search(root, searchkey, movesleft, movesright);
	if (result == -1){
		cout<<"\n Item not found";
	}else{
		cout<<"\n Found";
		cout<<"Moves left "<<movesleft;
		cout<<"Moves right "<<movesright;
		
	}			
}

