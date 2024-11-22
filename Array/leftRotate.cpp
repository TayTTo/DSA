#include <iostream>
#include <iterator>
using namespace std;

void rotate(int *a, int n){
	int tmp = a[0];
	for(int i = 1; i < n; i++){
		a[i - 1] = a[i];
	}
	a[n - 1] = tmp;
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

int main(){
	int a[] = {1, 4, 4, 5, 6, 1, 7};
	int n = sizeof(a) / sizeof(a[0]);
	rotate(a, n);
	return 0;
}
