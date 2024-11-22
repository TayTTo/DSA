#include <iostream>
using namespace std;

void buble_sort(int *a, int n){
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < i - 1; j++){
			if(a[j] > a[j + 1]){
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j+1] = tmp;
			}
		}
	}

	cout << "After buble sort: "<< endl;
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

int main(){
	int a[] = {12, 53, 21, 32, 43, 89, 1, 0, 31, 46, 87};
	int size = sizeof(a) / sizeof(a[0]);
	buble_sort(a, size);
	return 0;
}
