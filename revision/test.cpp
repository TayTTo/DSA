#include<iostream>
using namespace std;

struct Node{
	int data; 
	Node* next;
	Node* prev;

	Node(int data){
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}

	Node(int data, Node* next, Node* prev){
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

Node* convert2dll(int *arr, int n){
	Node* head = new Node(arr[0]);
	Node* mover = head;
	for(int i = 1; i < n; i++){
		Node* temp = new Node(arr[i]);
		mover->next = temp;
		temp->prev = mover;
		mover=mover->next;
	}
	return head;
}

Node* insertHead(Node* head, int val){
	Node* newHead = new Node(val, head, nullptr);
	head->prev = newHead;
	return newHead;
}

Node* insertTail(Node* head, int val){
	if(head == nullptr) return new Node(val);
	Node* temp = head;
	while(temp->next != nullptr){
		temp = temp->next;
	}
	Node* x = new Node(val);
	temp->next = x;
	x->prev = temp;
	return head;
}

Node* insertK(Node* head, int k, int val){
	if(head == nullptr){
		if(k == 1) return new Node(val);
		else return head;
	}
	if(k == 1){
		return new Node(val, head, nullptr);
	}
	int cnt = 0;
	Node* temp = head;
	while(temp != nullptr){
		cnt++;
		if(cnt == k) break;
		temp = temp->next;
	}
	if(temp == nullptr) return head;
	Node* front = temp->prev;
	Node* x = new Node(val, temp, front);
	front->next = x;
	temp->prev = x;
	return head;
}

Node* deleteHead(Node* head){
	if(head == nullptr) return head;
	if(head->next == nullptr && head->prev == nullptr) return nullptr;
	Node* temp = head;
	head = head->next;
	head->prev = nullptr;
	delete temp;
	return head;
}

Node* deleteTail(Node* head){
	if(head == nullptr) return head;
	if(head->next == nullptr && head->prev == nullptr) return nullptr;
	Node* temp = head;
	while(temp->next != nullptr){
		temp = temp->next;
	}
	Node* back = temp->prev;
	back->next = temp->prev = nullptr;
	delete temp;
	return head;
}

Node* deleteK(Node* head, int k){
	if(head == nullptr) return head;
	if(head->next == nullptr && head->prev == nullptr){
		if(k == 1) return nullptr;
		else return head;
	}
	if(k == 1){
		head = head->next;
		head->prev = nullptr;
		return head;
	}
	Node* temp = head;
	int cnt = 0;
	while(temp != nullptr){
		cnt++;
		if(cnt == k) break;
		temp = temp->next;
	}
	if(temp == nullptr) return head;
	Node* back = temp->prev;
	Node* front = temp->next;
	front->prev = back;
	back->next = front;
	temp->prev = temp->next = nullptr;
	delete temp;
	return head;
}

		

void traverse(Node* head){
	while(head != nullptr){
		cout << head->data << " ";
		head = head->next;
	}
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node* head = convert2dll(arr, n);
	head = insertHead(head, 10);
	head = insertTail(head, 15);
	head = insertK(head, 2, 29);
	head = deleteHead(head);
	head = deleteTail(head);
	head = deleteK(head, 9);
	traverse(head);
	return 0;
}
