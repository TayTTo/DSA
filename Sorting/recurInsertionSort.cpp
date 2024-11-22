#include <iostream>
using namespace std;

void insertion_sort(int *a, int i, int n){
	if (i == n) return;
	int j = i;
	while ( j > 0 && a[j] < a[j-1]){
		int tmp = a[j];
		a[j] = a[j-1];
		a[j-1] = tmp;
		j--;
	}
	insertion_sort(a, i + 1, n);
}
int main(){
	int a[] = {31, 34, 41, 632, 67, 15, 72, 97, 52, 83, 52};
	int n = sizeof(a)/sizeof(a[0]);
	insertion_sort(a, 0, n);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}
