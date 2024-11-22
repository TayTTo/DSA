#include <iostream>
#include <vector>
using namespace std;

//BruteForce One
//void frequent(int *a, int n){
//	for(int i = 0; i < n; i++){
//		int check = 0;
//		for(int j = 0; j < i; j++){
//			if(a[i] == a[j]){ 
//				check = 1;
//				break;
//			}
//		}
//		if(check == 0){
//			int cnt = 0;
//			for(int j = 0; j < n; j++){
//				if(a[i] == a[j]) cnt++;
//			}
//			cout << a[i] << " " << cnt << endl;
//		}
//	}
//}

void frequent(int *a, int n){
	vector<int> visited(n, 0);
	for(int i = 0; i < n; i++){
		if(visited[i] == 1) continue;
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(a[i] == a[j]){
				visited[j] = 1;
				cnt++;
			}
		}
		cout << a[i] << " " << cnt << endl;
	}
}




int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	frequent(arr, n);
	return 0;
}
