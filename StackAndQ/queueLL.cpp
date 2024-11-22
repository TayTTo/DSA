#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

struct Queue{
	Node* start;
	Node* end;
	int size;

	Queue(){
		this->start = nullptr;
		this->end = nullptr;
		this->size = 0;
	}

	void push(int x){
		Node* newNode = new Node{x, nullptr};
		if(size == 0){
			start = newNode;
			end = newNode;
		} else{
			end->next = newNode;
			end = newNode;
		}
		size++;
	}

	int pop(){
		if(size == 0){
			cout << "The queue is empty";
			end = nullptr;
			return -1;
		}
		int data = start->data;
		Node* temp = start;
		start = start->next;
		temp->next = nullptr;
		delete temp;
		size--;
		return data;
	}

	int top(){
		return start->data;
	}

	int Size(){
		return size;
	}

	void printQueue(){
		Node* current = start;
		while(current != nullptr){
			cout << current->data;
			current = current->next;
		}
	}
};

int main(){
	Queue q;
	q.push(1);
	q.push(2);
	q.push(4);
	q.push(6);
	q.push(8);
	cout << "The top value is: " << q.top() << endl;
	cout << "The current size of the queue is: " << q.Size() << endl;
	cout << "The poped element is: " << q.pop() << endl;
	cout << "The poped element is: " << q.pop() << endl;
	cout << "The poped element is: " << q.pop() << endl;
	q.push(100);
	q.printQueue();
	return 0;
}



			

