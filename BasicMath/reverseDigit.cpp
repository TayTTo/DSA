#include <iostream>
using namespace std;

int reverse(int n){
	int count = 0;
	int temp = n;
	while (temp > 0){
		int d = temp % 10;
		temp /= 10;

		if( d > 0 && n % d == 0){
			count++;
		}
	}

	return count;
}

int main(){
	int n;
	cin >> n;
	cout << reverse(n);
	return 0;
}
	
