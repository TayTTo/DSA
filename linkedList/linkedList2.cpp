#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int data1, Node* next1){
		data = data1;
		next = next1;
	}

	Node(int data1){
		data = data1;
		next = nullptr;
	}
};

Node* convert2ll(int *a){
	Node* head = new Node(a[0]);
	Node* mover = head;
	int sizeArr = sizeof(a) / sizeof(a[0]);
	for(int i = 1; i < sizeArr; i++){
		Node* tmp = new Node(a[i]);
		mover->next = tmp;
		mover = tmp;
	}
	return head;
}

int length(Node* head){
	int cnt = 0;
	Node* tmp = head;
	while(tmp){
		tmp = tmp->next;
		cnt++;
	}
	return cnt;
}


int main(){
	int arr[] = {2, 12, 32, 41};
	Node* head = convert2ll(arr);
	cout << length(head);
	return 0;
}
