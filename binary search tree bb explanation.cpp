//A tree is a data structure so we'll use a struct
//Structs and classes are identical in all ways except for the default access modifier: 
//Structures (also called structs) are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure.
//for a struct the default is public , whereas for a class it is private. There's no other difference as far as the language is concerned.

//Structures (also called structs) are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure.
//Unlike an array, a structure can contain many different data types (int, string, bool, etc.).

//This line includes the iostream header file, which provides input and output functionality in C++. 
//It allows us to use objects like cout and cin for printing and reading data, respectively.
#include<iostream>
//This line introduces the std namespace, which is the namespace that contains the standard library in C++
//By using this line, we can directly use the names of objects and variables from the std namespace without explicitly specifying the namespace each time.
using namespace std;


//This code defines a structure named node that represents a node in a binary tree. 
//It has three members: data, which stores the value of the node, and left and right, which are pointers to the left and right child nodes, respectively.
struct node{
	int data;
	node *left, *right;
};

//This code defines a function named insert that inserts a new node with the given item value into a binary tree. 
//It takes two parameters: root, which is a pointer to the root node of the tree, and item, which is the value to be inserted. 
//The function recursively traverses the tree to find the appropriate position for the new node and inserts it there.
node *insert(node *root,int item)
{
	if(root==NULL)
	{
		node *newnode=new node;
		newnode->data=item;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	else if(item<root->data)
	{
		root->left=insert(root->left, item);
	}
	else
	{
		root->right=insert(root->right, item);
	}
}

//This code defines a function named insert that inserts a new node with the given item value into a binary tree. 
//It takes two parameters: root, which is a pointer to the root node of the tree, and item, which is the value to be inserted. 
//The function recursively traverses the tree to find the appropriate position for the new node and inserts it there.
void preorder(node *root)
{
	
	//If root is NULL, it means that the current node is a leaf node or an empty tree. 
	//In this case, there is nothing to process further, so the function returns and exits.
	//condition ensures that the function stops the traversal when it reaches the end of a branch or a leaf node, 
	//preventing any further recursive calls on root->left and root->right. 
	//This condition acts as the base case for the recursive traversal.
	if(root==NULL) //**********
	{
		return;
	}
	else
	{
		cout<<root->data<<"  ";
		preorder(root->left);
		preorder(root->right);
	}
}

//This code defines a function named inorder that performs an inorder traversal of a binary tree. 
//It takes a parameter root, which is a pointer to the root node of the tree. 
//The function recursively visits each node in the tree in the order of left subtree, root, right subtree, and prints the value of each node.
void inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		inorder(root->left)	;
		cout<<root->data<<"  ";
		inorder(root->right);
	}
	
}

//This code defines a function named postorder that performs a postorder traversal of a binary tree. 
//It takes a parameter root, which is a pointer to the root node of the tree. 
//The function recursively visits each node in the tree in the order of left subtree, right subtree, root, and prints the value of each node.
void postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"  ";
	}
}


//This code defines the main function, which is the entry point of the program. 
//It initializes the root pointer to NULL and prompts the user to enter the number of data items to be inserted into the binary tree. 
//It then takes the input values from the user and inserts them into the tree using the insert function. 
//Finally, it performs preorder, inorder, and postorder traversals of the tree using the respective functions and prints the values of the nodes in each traversal.
int main()
{
	node *root=NULL;
	int i, item;
	int n;
	cout<<"how many data ";
	cin>>n;
	cout<<"enter values now ";
	for(i=0; i<n; i++)
	{
		cin>>item;
		root=insert(root, item);
	}
	cout<<"\nPreorder Traversal :";
	preorder(root);
	cout<<"\nInorder Traversal :";
	inorder(root);
	cout<<"\nPostorder Traversal :";
	postorder(root);
}
