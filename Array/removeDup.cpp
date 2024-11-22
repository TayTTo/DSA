#include <iostream>
#include <set>
using namespace std;

int rm(int *a, int n){
	int i = 0;
	for(int j = 1; j < n; j++){
		if(a[i] != a[j]){
			a[i+1] = a[j];
			i++;
		}
	}
	return i + 1;
}


//int rm(int *a, int n){
//	set<int> st;
//	for(int i = 0; i < n; i++){
//		st.insert(a[i]);
//	}
//	int k = st.size();
//	int j = 0;
//	for(auto x: st){
//		a[j++] = x;
//	}
//	return k;
//}

int main(){
	int a[] = {1 ,2 ,2 ,3 ,3 ,3 ,4 ,4 ,5 ,5};
	int n = sizeof(a) / sizeof(a[0]);
	int k = rm(a, n);
	cout << k;
	for(int i = 0; i < k; i++){
		cout << a[i] << " ";
	}
	return 0;
}
