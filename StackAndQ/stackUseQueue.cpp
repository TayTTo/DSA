#include <iostream>
#include <queue>
using namespace std;

struct Stack{
	queue<int> st;

	void Push(int x){
		int size = st.size();
		st.push(x);
		for(int i = 0; i < size; i++){
			st.push(st.front());
			st.pop();
		}
	}

	int Pop(){
		int data = st.front();
		st.pop();
		return data;
	}

	int Top(){
		return st.front();
	}

	int Size(){
		return st.size();
	}
};

int main(){
	Stack st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(8);
	st.Push(5);
	cout << "The current top element is: " << st.Top();
	st.Pop();
	cout << "The current top element is: " << st.Top();
	cout << "The current size of stack is: " << st.Size();
	return 0;
}


