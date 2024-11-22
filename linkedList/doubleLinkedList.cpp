#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* back;

	Node(int value, Node* nextAddress, Node* previousAddress){
		data = value;
		next = nextAddress;
		back = previousAddress;
	}

	Node(int value){
		data = value;
		next = nullptr;
		back = nullptr;
	}
};

Node* convert2DLL(vector<int> &arr){
	Node* head = new Node(arr[0]);
	Node* prev = head;
	for(int i = 1; i < arr.size(); i++){
		Node* temp = new Node(arr[i]);
		temp->back = prev;
		prev->next = temp;
		prev = temp;
	}
	return head;
}

Node* deleteHead(Node* head){
	if(head == nullptr) return head;
	if(head->next == nullptr && head->back == nullptr){
		delete head;
		return nullptr;
	}
	Node* prev = head;
	head = head->next;
	head->back = nullptr;
	prev->next = nullptr;
	delete prev;
	return head;
}

Node* deleteTail(Node* head){
	if(head == nullptr && head->next == nullptr) return nullptr;
	Node* tail = head;
	while(tail->next != nullptr){ //temp->next->next == (*(*temp).next).next 
		tail = tail->next;
	}
	Node* prev = tail->back;
	tail->back = nullptr;
	prev->next = nullptr;
	delete tail;
	return head;
}

Node* deleteKthNode(Node* head, int k){
	if(head == nullptr) return head;
	Node* temp = head;
	int count = 0;
	while(temp->next != 0){
		count++;
		if(count == k){
			break;
		}
		temp = temp->next;
	}
	Node* prev = temp->back;
	Node* behind = temp->next;
	if(prev == nullptr && behind == nullptr){
		delete head;
		return nullptr;
	}
	else if(behind == nullptr){
		return deleteTail(head);
	}
	else if(prev == nullptr){
		return deleteHead(head);
	}
	prev->next = behind;
	behind->back = prev;
	temp->next = nullptr;
	temp->back = nullptr;
	delete temp;
	return head;
}

void print(Node* head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
}

void deleteNode(Node* temp){
	Node* prev = temp->back;
	Node* behind = temp->next;
	if(behind == nullptr){
		prev->next = temp->back = nullptr;
		delete temp;
	}
	prev->next = behind;
	behind->back = prev;
	temp->next = temp->back = nullptr;
	delete temp;
}

Node* insertBeforeHead(Node* head, int val){
	Node* newHead = new Node(val);
	newHead->next = head;
	head->back = newHead;
	return newHead;
}

Node* insertAfterTail(Node* head, int val){
	Node* newNode = new Node(val);
	Node* tail = head;
	while(tail->next != nullptr){
		tail = tail->next;
	}
	tail->next = newNode;
	newNode->back = tail;
	return head;
}

Node* insertAfterHead(Node* head, int val){
	if(head->next == nullptr && head->back == nullptr) return insertAfterTail(head, val);
	Node* newNode = new Node(val);
	Node* behind = head->next;
	head->next = behind->back = newNode;
	newNode->back = head;
	newNode->next = behind;
	return head;
}

Node* insertBeforeTail(Node* head, int val){
	if(head->next == nullptr) return insertAfterHead(head, val);
	Node* newNode = new Node(val);
	Node* tail = head;
	while(tail->next != nullptr){
		tail = tail->next;
	}
	Node* prev = tail->back;
	prev->next = newNode;
	newNode->back = prev;
	newNode->next = tail;
	tail->back = newNode;
	return head;
}


Node* insertBeforeKth(Node* head, int val, int k){
	if(k == 1 || head->next == nullptr){
		return insertBeforeHead(head, val);
	}
	Node* newNode = new Node(val);
	Node* temp = head;
	int count = 0;
	while(temp->next != nullptr){
		count++;
		if(count == k) break;
		temp = temp->next;
	}
	Node* prev = temp->back;
	prev->next = temp->back = newNode;
	newNode->back = prev;
	newNode->next = temp;
	return head;
}

Node* insertAfterKth(Node* head, int val, int k){
	if(k == 1) return insertAfterHead(head, val);
	if(head->next == nullptr && head->back == nullptr){
		return insertAfterHead(head, val);
	}
	Node* newNode = new Node(val);
	Node* temp = head;
	int count = 0;
	while(temp->next != nullptr){
		count++;
		if(count == k) break;
		temp = temp->next;
	}
	if(temp->next == nullptr) return insertAfterTail(head, val);
	Node* behind = temp->next;
	temp->next = behind->back = newNode;
	newNode->back = temp;
	newNode->next = behind;
	return head;
}



int main(){
	vector<int> arr = {12};//, 23, 41, 65};
	Node* head = convert2DLL(arr);
	head = insertAfterKth(head,  4, 4);
	print(head);
	return 0;
}
