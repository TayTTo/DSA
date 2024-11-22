#include <iostream>
using namespace std;

struct Queue {
	int* arr;
	int start, end, current_size, max_size;

//	Queu(){
//		arr = new int[16];
//		start = -1;
//		end = -1;
//		current_size = 0;
//	}

	Queue(int max_size){
		this->max_size = max_size;
		arr = new int[max_size];
		start = -1;
		end = -1;
		current_size = 0;
	}

	void push(int x){
		if(current_size == max_size){
			cout << "The capacity is full";
			return;
		}
		if(end == -1){
			start = 0;
			end = 0;
		} else {
			end = (end + 1) % max_size;
		}
		arr[end] = x;
		current_size++;
	}

	int Top(){
		if(current_size == 0){
			cout << "The queue is empty";
			return -1;
		}
		return arr[start];
	}

	int pop(){
		if(current_size == 0){
			cout << "The queu is empty";
		}
		int poped = arr[start];
		if(current_size == 1){
			start = -1;
			end = -1;
		} else {
			start = (start + 1) % max_size;
		}
		current_size--;
		return poped;
	}

	int size(){
		return current_size;
	}
};

int main(){
    Queue q(100);
    q.push(1);
    q.push(2);
    q.push(4);
    q.push(5);
    cout << q.Top() << endl;
    cout << "The size of the queue is: " << q.size() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "The top element is: " << q.Top() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "The top element is: " << q.Top() << endl;
    cout << "The size is: " << q.size() << endl;
    return 0;
}

		

