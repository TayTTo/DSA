#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondLargestElement(int n, vector<int>& a){
	if(n < 2) return -1;
	int max = INT_MIN, second_max = INT_MIN;
	int i;
	for(i = 0; i < n; i++){
		if(max < a[i]){
			second_max = max;
			max = a[i];
		}
		else if(second_max < a[i] && a[i] != max){
			second_max = a[i];
		}
	}
	return second_max;
}
	
int secondSmallestElement(int n, vector<int>& a){
	if(n < 2) return -1;
	int min = INT_MAX, second_min = INT_MAX;
	int i;
	for(i = 0; i < n; i++){
		if(min > a[i]){
			second_min = min;
			min = a[i];
		}
		else if( second_min > a[i] && a[i] != min){
			second_min = a[i];
		}
	}
	return second_min;
}

void getSecondOrderElements(int n, vector<int>& a) {
    // Write your code here.
    cout << secondLargestElement(n, a) << " ";
    cout << secondSmallestElement(n, a) << endl;
}


int main(){
	vector<int> a = {3 ,4, 5, 2};
	int n = a.size();
	getSecondOrderElements(n, a);
	return 0;
}
