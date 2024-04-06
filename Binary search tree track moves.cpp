#include <iostream>
using namespace std;
struct node{
	int data;
	node *left, *right;
	//A constructer for the struct node
	node(int val) : data(val), left(NULL), right(NULL) {}
};

//converts array to a tree
node *insertNode(node *root, int value){
	if (root == NULL){
		return new node(value);
	}else if (value < root->data){
		root->left=insertNode(root->left, value);
	}else{
		root->right=insertNode(root->right, value);
	}
}

//searching function
void searchnode(node *root, int value, int& count_left, int& count_right){
	node *current = root;
	
	while (current != NULL) {
		if(root == NULL){
			cout<<"not found";
			return;
		} else if(value == current->data){
			cout<<value<<" has been found"<<endl;
			cout<<"Moves left: "<< count_left<<endl;
			cout<<"Moves right: "<< count_right<<endl;
			return;
		}
		else if(value < root->data){
			count_left ++;
			searchnode(root->left, value, count_left, count_right );
			
		}else{
			count_right++;
			searchnode(root->right, value, count_left, count_right);
		}
		break;
	}	
}

main(){
	node *root=NULL;
	int values[] = {45,7,1,89,34,23,12,78,22,56,35,67,4,9,64,21,20,90,58};
	int valuesLength = sizeof(values)/sizeof(values[0]);
	for (int i=0; i<valuesLength; i++){
			root = insertNode(root, values[i]);
	}
	
	int value= 21;	
	int count_left = 0;
	int count_right = 0;
	searchnode(root, value, count_left, count_right);
	

}


