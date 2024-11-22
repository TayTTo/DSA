#include <iostream>
using namespace std;

void rotate_k_elements(int *a, int n, int k){
	k = k % n;
	int tmp[k];
	for(int i = 0; i < k; i++){
		tmp[i] = a[i];
	}
	for(int i = k; i < n; i++){
		a[i - k] = a[i];
	}
	for(int i = n - k; i < n; i++){
		a[i] = tmp[i - (n-k)];
	}
}

int main(){
	int a[] = {1,3,4,55,15,6,67,41,59};
	int n = sizeof(a) / sizeof(a[0]);
	int k = 3;
	rotate_k_elements(a, n, k);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}
