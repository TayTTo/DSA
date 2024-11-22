#include <iostream>
using namespace std;

void bubleSort(int *a, int n){
	if(n == 1) return;
	for(int i = 0; i < n - 1; i++){
		if(a[i] > a[i+1]){
			int tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp;
		}
	}
	bubleSort(a, n - 1);
}

int main(){
	int a[] = {13, 42, 41, 63, 31, 67, 89, 71, 67, 65, 24, 92, 8, 94};
	int size = sizeof(a)/sizeof(a[0]);
	bubleSort(a, size);
	for(int i = 0; i < size; i++){
		cout << a[i] << " ";
	}
	return 0;
}
