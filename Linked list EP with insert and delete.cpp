//NB: TEST ON ONLINE COMPILER, DOESNT WORK IN DEV C++
//LINKED LIST
//Data Structure(indefinite size - can store " amt of items)
//We showcase it using a class AND struct
//2 methods so far: createnode: creating the linked list
//					display

//Basics:
#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class linkedlist{
	node *head, *tail;
	public:
		void createnode(int item){
			node *newnode = new node;
			newnode->data = item;
			newnode->next= NULL;
			
			if(head == NULL){
				head = tail = newnode;
			} else{
				tail->next = newnode;
				tail= newnode;
			}
		}
		
		//Extra Method to insert new node
		void insertnode(int item){
			node *newnode = new node;
			newnode->data = item;
			newnode->next = NULL;
			
			int pos;

			cout<<"Position to insert: ";
			cin>>pos;
			
			node *curr = head;
			node *prev;
			
			for(int i=1; i<pos; i++){
				prev = curr;
				curr= curr->next;
			}
			
			if(curr == head){
				newnode->next = head;
				head = newnode;
			} else if (curr == tail){
				tail->next = newnode;
				tail = newnode;
			}
			else{
				prev->next = newnode;
				newnode->next = curr;
			}
		}
		
		void deltenode(int item){	
			int pos;

			cout<<"Position to delete: ";
			cin>>pos;
			
			node *curr = head;
			node *prev;
			
			for(int i=1; i<pos; i++){
				prev = curr;
				curr= curr->next;
			}
			
			if(curr == head){
				head = curr->next;
			} else if (curr == tail){
				prev->next= NULL;
				tail= prev;
			}
			else{
				prev->next = curr->next;
			}
		}
		
		void display(){
			node *temp = head;
			while(temp != NULL){
				cout<<temp->data<<"--->";
				temp= temp->next;
			}
		}		
};



int main(){
	linkedlist l;
	int i,n, item;
	cout<<"How many items ";
	cin>>n;
	for (i=0; i<n; i++){
		int track = i+1;
		cout<<"Enter item "<<track<<": ";
		cin>>item;
		l.createnode(item);
	}
	
	l.display();
	
	cout<<"\n Enter new item to insert ";
	cin>>item;
	l.insertnode(item);
	l.display();
	
	//You dont have to enter item to delete
	//We'll check index in delete  method
	//next 2 lines unnecessary
	cout<<"\n Enter item to delete ";
	cin>>item;
	l.deltenode(item);
	l.display();
}
