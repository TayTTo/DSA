#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void countFreq(int *a, int n){
	vector<int> visited(n, 0);
	int maxFre = INT_MIN, minFre = INT_MAX;
	int maxEle = INT_MIN, minEle = INT_MAX; 
	for(int i = 0; i < n; i++){
		if(visited[i] == 1) continue;

		int count = 1;
		for(int j = i + 1; j < n; j++){
			if(a[i] == a[j]){
				count++;
				visited[j] = 1;
			}
		}
		cout << a[i] << " " << count << endl;
	}
}

int main(){
	int arr[] = {10, 5, 10, 15, 10, 5, 1, 2, 6, 9, 9, 1, 5, 6, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	countFreq(arr, n);
	return 0;
}
