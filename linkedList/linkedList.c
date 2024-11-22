#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* creatNode(int data, Node* next){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = next;
	return newNode;
}

Node* convert2ll(int *arr, int n){
	Node* head = creatNode(arr[0], NULL); 
	Node* mover = head;
	for(int i = 1; i < n; i++){
		Node* temp = creatNode(arr[i], NULL);
		mover->next = temp;
		mover = temp;
	}
	return head;
}

void print(Node* head){
	Node* temp = head;
	while(temp){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main(){
	int arr[] = {2, 12, 32, 41, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	Node* head = convert2ll(arr, n);
	print(head);
	Node* n{42};
	return 0;
}
