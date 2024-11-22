#include <iostream>
#include <vector>
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

Node* convert2ll(vector<int> &a){
	Node* head = new Node(a[0]);
	Node* mover = head;
	for(int i = 1; i < a.size(); i++){
		Node* tmp = new Node(a[i]);
		mover->next = tmp;
		mover = tmp;
	}
	return head;
}

Node* insertHead(Node* head, int val){
	return new Node (val, head);
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

int checkIfPresent(Node* head, int val){
	Node* tmp = head;
	while(tmp){
		if(tmp->data == val) return 1;
		tmp = tmp->next;
	}
	return 0;
}

void print(Node* head){
	Node* temp = head;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
}

Node* removeHead(Node* head){
	if(head == NULL) return head;
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

Node* removeTail(Node* head){
	if(head == NULL || head->next == NULL) return NULL;
	Node* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
	return head;
}

Node* removeK(Node* head, int k){
	if(head == NULL) return head;
	if(k == 1){
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}
	int count = 0;
	Node* temp = head;
	Node* prev = NULL;
	while(temp != NULL){
		count++;
		if(count == k){
			prev->next 	= prev->next->next;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}

Node* insertTail(Node* head, int val){
	if(head == NULL) return new Node(val);
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	Node* newNode = new Node(val);
	temp->next = newNode;
	return head;
}

Node* insertKth(Node* head, int val, int k){
	if(head == NULL){
		if(k == 1) return new Node(val);
		else return NULL;
	}
	if(k==1) return new Node(val,head);
	Node* temp = head;
	int count = 0;
	while(temp->next != NULL){
		count++;
		if(count == k - 1){
			Node* newNode = new Node(val, temp->next);
			temp->next = newNode;
			break;
		}
		temp = temp->next;
	}
	return head;
}

Node* insertBeforeValue(Node* head, int val, int el){
	if(head == NULL) return head;
	if(head->data == el) return new Node(val, head);
	Node* temp = head;
	while(temp->next != NULL){
		if(temp->next->data == el){
			Node* newNode = new Node(val, temp->next);
			temp->next = newNode;
			break;
		}
		temp = temp->next;
	}
	return head;
}

int main(){
	vector<int> arr = {2, 12, 32, 41, 2};
	Node* head = convert2ll(arr);
//	head = removeHead(head);
//	head = removeTail(head);
	head = insertBeforeValue(head, 14, 2);
	print(head);
	return 0;
}
