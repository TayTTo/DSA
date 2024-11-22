#include <iostream>
#include <vector>
using namespace std;

int move_zro_to_left(int *a, int n){
	vector<int> tmp;
	for(int i = 0; i < n; i++){
		if(a[i] != 0){
			tmp.push_back(a[i]);
		}
	}
	int size = tmp.size();
	for(int i = 0; i < size; i++){
		a[i] = tmp[i];
	}
	for(int i = size; i < n; i++){
		a[i] = 0;
	}
	return *a;
}

int main(){
	int a[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
	int n = sizeof(a)/sizeof(a[0]);
	move_zro_to_left(a, n);
	for(int i = 0; i < n; i++){
		cout << a[i];
	}
	return 0;
}
