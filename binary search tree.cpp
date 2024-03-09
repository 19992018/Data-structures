#include <iostream>
using namespace std;
struct node{
	int data;
	node *left, *right;
};

node *createnode(node *root, int item){
	if (root ==NULL){
		root= new node;
		root->data=item;
		root->left = NULL;
		root->right =NULL;
	} 
	else if(item < root->data){
		root->left=createnode(root->left, item);
	}
	else{
		root->right=createnode(root->right, item);
	}
	return root;
}

void preorderTraversal(node *root){
	if(root==NULL){
		return;
	}
	else{
		cout<<root->data<<" ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal(node *root){
	if(root==NULL){
		return;
	}
	else{
		inorderTraversal(root->left);
		cout<<root->data<<" ";
		inorderTraversal(root->right);
	}
}

void postorderTraversal(node *root){
	if(root==NULL){
		return;
	}
	else{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout<<root->data<<" ";
	}
}

//searching
void searchnode(node *root, int item){
	if(root == NULL){
		cout<<"not found";
		return;
	} else if(item == root->data){
		cout<<"Item has been found";
	}
	else if(item < root->data){
		searchnode(root->left, item);
	}else{
		searchnode(root->right, item);
	}
}


main(){
	node *root=NULL;
	int i, n;
	int item;
	
	cout<<"How many values ";
	cin>>n;
	cout<<"Enter the values ";
	for(i=0; i<n; i++){
		cin>>item;
		root=createnode(root, item);
	}
	cout<<"\nPreorder traversal: ";
	preorderTraversal(root);
	
	cout<<"\nInorder traversal: ";
	inorderTraversal(root);
	
	cout<<"\nPostorder traversal: ";
	postorderTraversal(root);
	
	cout<<"\nEnter item to search ";
	cin>>item;
	searchnode(root, item);
}


