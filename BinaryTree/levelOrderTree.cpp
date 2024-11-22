#include <iostream>
#include <queue>
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

TreeNode* insertNode(TreeNode* root, int data){
	if(root == nullptr){
		return root;
	}
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* temp = q.front();
		q.pop();
		if(temp->left != nullptr) q.push(temp->left);
		else{
			temp->left = new TreeNode(data);
			return root;
		}

		if(temp->right != nullptr) q.push(temp->right);
		else{
			temp->right = new TreeNode(data);
			return root;
		}
	}
	return root;
}

vector<vector<int>> levelOrder(TreeNode* root){
	vector<vector<int>> ans;
	if(root == nullptr){
		return ans;
	}
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		vector<int> level;
		int size = q.size();
		for(int i = 0; i < size; i++){
			TreeNode* temp = q.front();
			q.pop();
			level.push_back(temp->data);
			if(temp->left != nullptr) q.push(temp->left);
			if(temp->right != nullptr) q.push(temp->right);
		}
		ans.push_back(level);
	}
	return ans;
}

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	vector<vector<int>> ans = levelOrder(root);
	
	cout << "Before insertion" << endl;
	for(auto it : ans){
		for(auto x : it){
			cout << x << " ";
		}
		cout << endl;
	}

	root = insertNode(root, 8);
	root = insertNode(root, 9);
	root = insertNode(root, 10);
	
	vector<vector<int>> ans2 = levelOrder(root);
	cout << "After " << endl;
	
	for(auto it : ans2){
		for(auto x : it){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}































