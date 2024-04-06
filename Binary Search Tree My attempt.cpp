//This is a data structure
//Hence we'll use a struct, which is a type of class

//Basics
#include <iostream>
using namespace std;

struct node{
	int data;
	node *left, *right;
};

//Creating our tree
node *insert(node *root, int item){
	if(root==NULL){
		node *newnode = new node;
		newnode->data=item;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	} else if(root->data < item){
		root->right = insert(root->right, item);
	} else{
		root->left = insert(root->left, item);
	}
	
}

//Preorder traversal
void preorder(node *root){
	if(root==NULL){
		return;
	}else{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

//Inorder traversal
void inorder(node *root){
	if(root==NULL){
		return;
	}else{
		preorder(root->left);
		cout<<root->data<<" ";
		preorder(root->right);
	}
}

//Postorder traversal
void postorder(node *root){
	if(root==NULL){
		return;
	}else{
		preorder(root->left);
		preorder(root->right);
		cout<<root->data<<" ";
	}
}

// Search for a value in the binary search tree  //ADDED TO MY ATTEMPT
// and track the number of moves left and right
int search(node *root, int value, int& movesleft, int& movesright) {
    if (root == NULL) {
        // Value not found
        return -1;
    } else if (root->data == value) {
        // Value found
        return 0;
    } else if (root->data < value) {
        // Move right
        movesright++;
        return search(root->right, value, movesleft, movesright);
    } else {
        // Move left
        movesleft++;
        return search(root->left, value, movesleft, movesright);
    }
}




int main(){
	node *root =NULL;
	int i, n, x;
	cout<<"How many numbers ";
	cin>>n;
	cout<<"Insert the numbers";
	for(i=0; i<n; i++){
		cin>>x;
		root=insert(root, x);
	}
	cout<<"\nPreorder Traversal :";
	preorder(root);
	cout<<"\nInorder Traversal :";
	inorder(root);
	cout<<"\nPostorder Traversal :";
	postorder(root);
	
	int value;
    cout << "\nEnter a value to search: ";
    cin >> value;
	int movesright = 0;
	int movesleft = 0;
    int result = search(root, value, movesleft, movesright);
    if (result == -1) {
        cout << "Value not found in the binary search tree." << endl;
    } else {
        cout << "Value found in the binary search tree." << endl;
        cout << "Number of moves left: " << movesleft << endl;
        cout<<"Number of moves right "<<movesright<<endl;
    }
		
	
}
