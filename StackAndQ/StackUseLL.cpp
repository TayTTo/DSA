#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		this->next = nullptr;
	}
};

struct Stack{
	Node* top;
	int size;

	Stack(){
		this->top = nullptr;
		this->size = 0;
	}

	void push(int x){
		Node* newNode = new Node(x);
		newNode->next = top;
		top = newNode;
		size++;
	}

	int pop(){
		if(size == 0){
			cout << "The stack is empty" << endl;
			return -1;
		}
		int data = top->data;
		Node* temp = top;
		top = top->next;
		temp->next = nullptr;
		delete temp;
		size--;
		return data;
	}

	int Size(){
		return size;
	}

	int Top(){
		if(top == nullptr){
			return -1;
		}
		return top->data;
	}

	void pritnStack(){
		Node* current = top;
		while(current != nullptr){
			cout << current->data;
			current = current->next;
		}
	}
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(8);
	s.push(7);
	cout << "element poped: " << s.pop();
	cout << "element size: "  << s.Size();
	cout << "stack includes: " << endl;
	s.pritnStack();
	return 0;
}
