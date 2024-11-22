#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data){
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

vector<int> ans(TreeNode* root){
	vector<int> ds;
	if(root == nullptr) return ds;
	stack<TreeNode*> st1, st2;
	st1.push(root);
	while(!st1.empty()){
		root = st1.top();
		st1.pop();
		st2.push(root);
		if(root->left != nullptr){
			st1.push(root->left);
		}
		if(root->right != nullptr){
			st1.push(root->right);
		}
	}
	while(!st2.empty()){
		ds.push_back(st2.top()->data);
		st2.pop();
	}
	return ds;
}


int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	vector<int> result = ans(root);
	for(auto it : result){
		cout << it << " ";
	}
	return 0;
}

	
