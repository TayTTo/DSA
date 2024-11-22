#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

int main(){
	Node* root = new Node{1, nullptr, nullptr};
	root->left = new Node{2};
	root->right = new Node{3};
	root->left->right = new Node{8};
	return 0;
}
