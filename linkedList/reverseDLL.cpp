#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* back;

	Node(int data){
		this->data = data;
		this->next = nullptr;
		this->back = nullptr;
	}

	Node(int data, Node* next, Node* back){
		this->data = data;
		this->next = next;
		this->back = back;
	}
};

Node* convert2DLL(vector<int>& arr){
	Node* head = new Node(arr[0]);
	Node* prev = head;
	for(int i = 1; i < arr.size(); i++){
		Node* temp = new Node(arr[i], nullptr, prev);
		prev->next = temp;
		prev = temp;
	}
	return head;
}

void print(Node* head){
	while(head != nullptr){
		cout << head->data << " ";
		head = head->next;
	}
}

Node* reverseDLL(Node* head){
	if(head == nullptr && head->next == nullptr){
		return head;
	}
	Node* prev = nullptr;
	Node* temp =  head;
	while(temp != nullptr){
		prev = temp->back;
		temp->back = temp->next;
		temp->next = prev;
		temp = temp->back;
	}
	cout << typeid(temp).name() <<endl;
	cout << temp << endl;
	cout << prev << endl;
	return prev->back;
}

int main(){
	vector<int> arr = {12, 41, 23, 65};
	Node* head = convert2DLL(arr);
	head = reverseDLL(head);
	print(head);
	return 0;
}
