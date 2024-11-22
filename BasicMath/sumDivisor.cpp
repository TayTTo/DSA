#include <iostream>
#include <math.h>
using namespace std;

int sumOfDivisor(int n){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sqrt(i); j++){
			if ( i % j == 0) {
				sum += j;
				if( j != i / j){
					sum += i/j;
				}
			}
		}
	}
	return sum;
}

//Optimal way
int sumOfDivisor1(int n){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += (n/i) * i;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	cout << sumOfDivisor1(n);
	return 0;
}

