#include <iostream>
using namespace std;

int binarySearch(int *a, int low, int high, int k){
	if(low > high) return 0;
	int mid = (low + high) / 2;
	if (a[mid] == k) return 1;
	else if(k < a[mid]) return binarySearch(a, low, mid - 1, k);
	return binarySearch(a, mid + 1, high, k);
}

int main(){
	int a[] = {3, 4, 6, 7, 9, 12, 16, 17};
	int n = sizeof(a) / sizeof(a[0]);
	int k = 89;
	if(binarySearch(a, 0, n - 1, k) == 1) cout << "Yes";
	else cout << "No";
	return 0;
}
