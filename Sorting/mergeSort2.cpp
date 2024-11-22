#include <iostream>
using namespace std;

void merge(int *a, int low, int mid, int high){
	int tmp[high];
	int left = low;
	int right = mid + 1;
	
	int i = 0;
	while(left <= mid && right <= high){
		if(a[left] <= a[right]){
			tmp[i] = a[left];
			left++;
			i++;
		}
		else{
			tmp[i] = a[right];
			right++;
			i++;
		}
	}
	while(left <= mid){
		tmp[i] = a[left];
		left++;
		i++;
	}
	while(right <= high){
		tmp[i] = a[right];
		right++;
		i++;
	}
	for(int j = low; j <= high; j++){
		a[j] = tmp[j - low];
	}
}

void mergeSort(int *a, int low, int high){
	if(low >= high) return;
	int mid = (low + high)/2;
	mergeSort(a, low, mid);
	mergeSort(a, mid + 1, high);
	merge(a, low, mid, high);
}

int main(){
	int a[] = {1, 13, 42, 65, 132, 67, 15, 72, 71, 73, 81, 88, 91, 30};
	int size = sizeof(a)/sizeof(a[0]);
	mergeSort(a, 0, size - 1);
	for(int i = 0; i < size; i++){
		cout << a[i] << " ";
	}
	return 1;
}

