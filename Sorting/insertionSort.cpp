#include <iostream>
using namespace std;

void insertion_sort(int *a, int n){
	for(int i = 0; i < n; i++){
		int j = i;
		while( j > 0 && a[j] < a[j - 1]){
			int tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
			j--;
		}
	}
	cout << "After insertion sort: " << endl;
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

int main(){
	int a[] = {12, 53, 21, 32, 43, 89, 1, 0, 31, 46, 87};
	int size = sizeof(a) / sizeof(a[0]);
	insertion_sort(a, size);
	return 0;
}
