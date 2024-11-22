#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

void fre(int *a, int n){
	unordered_map<int, int> map;
	for(int i = 0; i < n; i++) map[a[i]]++;
	int maxFre = INT_MIN, minFre = INT_MAX;
	int maxEle = INT_MIN, minEle = INT_MAX;
	for(auto it : map){
		int count = it.second;
		int element = it.first;

		if(count > maxFre) {
			maxEle = element;
			maxFre = count;
		}
		if(count < minFre) {
			minEle = element;
			maxFre = count;
		}
	}
	cout << "The highest frequence element is: " << maxEle << endl;
	cout << "The lowest frequence element is: " << minEle << endl;
}



int main(){
	int arr[] = {10, 5, 10, 15, 10, 5, 1, 2, 6, 9, 9, 1, 5, 6, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	fre(arr, n);
	return 0;
}
