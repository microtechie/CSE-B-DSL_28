#include<iostream>
using namespace std;
#define SIZE 5

class Queue{
	private:
		int arr[SIZE];
		int front;
		int rear;
		
	public:
		Queue(){
			front=-1;
			rear=-1;
		}
		void enqueue(int value){
			if(rear == SIZE-1){
				cout<<"Queue Overflow"<<endl;
				return;
			}
			if(front==-1){
				front=0;
			}
			rear++;
			arr[rear]=value;
			cout<<value<<"inserted"<<endl;
		}
		void dequeue(){
			if(front==-1 || front>rear){
				cout<<"Queue underflow"<<endl;
				return;
			}
			cout<<arr[front]<<"deleted"<<endl;
			front++;
		}
		void display(){
			if(front==-1 || front>rear){
				cout<<"Queue is empty"<<endl;
				return;
			}
			cout<<"Queue elements";
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	Queue q;
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.display();
	q.dequeue();
	q.display();
	return 0;
}