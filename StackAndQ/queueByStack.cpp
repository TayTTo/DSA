#include <iostream>
#include <stack>
using namespace std;

struct Queue{
	stack<int> s1, s2;

	void Push(int x){
		while(s1.size() != 0){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);

		while(s2.size() != 0){
			s1.push(s2.top());
			s2.pop();
		}
	}

	int Top(){
		return s1.top();
	}

	int Pop(){
		int data = s1.top();
		s1.pop();
		return data;
	}

	int Size(){
		return s1.size();
	}
};

int main(){
	Queue q;
	q.Push(1);
	q.Push(2);
	q.Push(5);
	q.Push(8);
	q.Push(9);
	cout << "The top ele is: " << q.Top() << endl;
	q.Pop();
	cout << "The current size is: " << q.Size() << endl;
	cout << "The current ele is: " << q.Top() << endl;
	return 0;
}
