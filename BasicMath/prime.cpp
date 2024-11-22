#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;

int checkPrime(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if ( n % i == 0) return 0;
	}
	return 1;
}

int main(){
	int n;
	cin >> n;
	if(checkPrime(n) == 1) cout<<"True";
	else cout<<"False";
}



