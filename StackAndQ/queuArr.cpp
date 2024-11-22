#include <iostream>
using namespace std;

struct Queu{
	int q[1000];
	int current_size = 0, start = -1, end = -1;
	
	void push(int x){
		if(current_size == 1000){
			cout << "The queu is full" << endl;
			return;
		}
		if(current_size == 0){
			start = 0; 
			end = 0;
		}
		q[end] = x;
		end = (end + 1) % 1000;
		current_size += 1;
	}
	
	int pop(){
		if(current_size == 0) cout << "The queu is empty";
		current_size = current_size - 1;
		int x = q[start];
		start = (start + 1) % 1000;
		return x;
	}

	int top(){
		if(current_size == 0) cout << "The queu is empty";
		return q[start];
	}

	int size(){
		return current_size;
	}
};

int main(){
	Queu q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(6);
	cout << "The current top element is: " << q.top() << endl;
	cout << "The poped element is: " << q.pop() << endl;
	cout << q.pop() << endl;
	cout << "The size of the queu is: " << q.size() << endl;
	return 0;
}



		

