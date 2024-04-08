//Queue is a data structure (an abstract data type)
//So we'll use a class to implement it
//Methods: enqueue dequeue display (all void)
//*Properties: an array with rear and front

//BASICS:
#include <iostream>
#define size 50
using namespace std;

//The class:
class Queue{
	int array[size];
	int rear, front;
	
	public:
		//constructor function
		Queue(){
			rear=front=-1;
		}
		void enqueue(int item){
			if(rear == size-1){
				cout<<"Queue is full";
				return;
			}else if(rear == -1){
				front++;
				rear++;
				array[rear]=item;
			} else{
				rear++;
				array[rear]= item;
			}
		}
		
		void dequeue(){
			if(front == -1){
				cout<<"Queue is empty";
				return;
			}else if(front == rear){
				cout<<array[front];
				front = rear = -1;
			} else{
				cout<<array[front]<<" ";
				front++;
			}
		}
		
		void display(){
			while(front != -1){
				dequeue();
			}
		}
		
};

int main(){
	Queue q;
	int i, n, item;
	cout<<"How many values ";
	cin>>n;
	for (i=0; i<n; i++){
		cout<<"Key in value ";
		cin>>item;
		q.enqueue(item);
	}
	q.display();
	
}


