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
	TreeNode* node = root;
	stack<TreeNode*> st;
	while(true){
		if(node != nullptr){
			st.push(node);
			node = node->left;
		}
		else{
			if(st.empty() == true){
				break;
			}
			node = st.top();
			st.pop();
			ds.push_back(node->data);
			node = node->right;
		}
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

	
