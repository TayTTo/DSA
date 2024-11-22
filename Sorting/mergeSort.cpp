#include <iostream>
#include <vector>
using namespace std;

void merge(int *a, int low, int mid, int high){
	vector<int> temp;
	int left = low;
	int right = mid + 1;

	while(left <= mid && right <= high){
		if(a[left] <= a[right]){
			temp.push_back(a[left]);
			left++;
		}
		else{
			temp.push_back(a[right]);
			right++;
		}
	}
	while(left <= mid){
		temp.push_back(a[left]);
		left++;
	}
	
	while(right <= high){
		temp.push_back(a[right]);
		right++;
	}
	for(int i = low; i <= high; i++) {
		a[i] = temp[i - low];
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
	int a[] = {1, 23, 41, 42, 63, 12, 52, 67, 51, 13, 5153, 727, 93};
	int n = sizeof(a) / sizeof(a[0]);
	mergeSort(a, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}
