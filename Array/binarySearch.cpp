#include <iostream>
using namespace std;

int binarySearch(int *a, int n, int k){
	int low = 0, high = n - 1;
	while (low < high){
		int mid = (low + high) / 2;
		if(a[k] == a[mid]) return 1;
		if(a[k] < a[mid]){
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return 0;
}

int main(){
	int a[] = {3, 4, 6, 7, 9, 12, 16, 17};
	int size = sizeof(a)/sizeof(a[0]);
	int k = 10;
	if(binarySearch(a, size, k) == 1) cout << "Yes";
	else cout << "No";
	return 0;
}
