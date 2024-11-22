#include <iostream>
using namespace std;

int linearSearch(int *a, int n, int k){
	for(int i = 0; i < n; i++){
		if(a[i] == k) return 1;
	}
	return 0;
}

int main(){
	int a[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
	int n = sizeof(a)/sizeof(a[0]);
	int k = 2;
	if(linearSearch(a, n ,k) == 1) cout << "True";
	else cout << "False";
	return 0;
}
	
