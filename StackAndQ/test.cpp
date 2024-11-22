#include <iostream>
using namespace std;

struct Queue {
    int* arr;
    int start, end, current_size, max_size;

    Queue(int max_size) {
        this->max_size = max_size;
        arr = new int[max_size];
        start = -1;
        end = -1;
        current_size = 0;
    }

    void push(int x) {
        if (current_size == max_size) {
            cout << "The capacity is full\n";
            return;
        }
        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % max_size;
        }
        arr[end] = x;
        current_size++;
    }

    int Top() {
        if (current_size == 0) {
            cout << "The queue is empty\n";
            return -1; // Or throw an exception
        }
        return arr[start];
    }

    int pop() {
        if (current_size == 0) {
            cout << "The queue is empty\n";
            return -1; // Or throw an exception
        }
        int popped = arr[start];
        if (current_size == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % max_size;
        }
        current_size--;
        return popped;
    }

    int size() {
        return current_size;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
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
