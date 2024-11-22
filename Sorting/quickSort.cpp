#include <iostream>
using namespace std;

int partition(int *a, int low, int high){
	int pivot = a[low];
	int i = low, j = high;
	while(i < j){
		while(a[i] <= pivot && i < high){
			i++;
		}
		while(a[j] > pivot && j > low){
			j--;
		}
		if(i < j){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	int tmp = a[low];
	a[low] = a[j];
	a[j] = tmp;
	return j; 
}

void qSort(int *a, int low, int high){
	if(low < high){
		int pIndex = partition(a, low, high);
		qSort(a, low, pIndex - 1);
		qSort(a, pIndex + 1, high);
	}
}

int main(){
	int a[] = {12, 42, 1, 5, 7, 4, 78, 62, 63, 27, 71, 914, 65};
	int n = sizeof(a)/sizeof(a[0]);
	qSort(a, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}
