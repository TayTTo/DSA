#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;

	Node(int data){
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;
	}
};

vector<vector<int>> levelOrder(Node* root){
	vector<vector<int>> ans; 
	if(root == nullptr){
		return ans;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		vector<int> level;
		int size = q.size();
		for(int i = 0; i < size; i++){
			Node* node = q.front();
			q.pop();
			level.push_back(node->data);
			if(node->left != nullptr){
				q.push(node->left);
			}
			if(node->right != nullptr){
				q.push(node->right);
			}
		}
		ans.push_back(level);
	}
	return ans;
}
			

	
int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	vector<vector<int>> result = levelOrder(root);

	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
	}
	return 0;
}



