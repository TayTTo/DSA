#include <iostream>
using namespace std;

struct Stack{
	int top = -1;
	int st[1000];

	void push(int x){
		if(top > 1000) cout << "The stack is full" << endl;
		top = top + 1; 
		st[top] = x;
	}

	int get_top(){
		if(top == -1) cout << "The stack is empty";
		return st[top];
	}
	
	int pop(){
		if(top == -1) cout << "The stack is empty";
		int value = st[top];
		top = top - 1;
		return value;
	}

	int size(){
		return (top + 1);
	}
};

int main(){
	Stack s;
	s.push(5);
	s.push(6);
	s.push(7);
	cout << s.size();
	while(s.size() != 0){
		cout << s.pop();
	}
	return 0;
}
