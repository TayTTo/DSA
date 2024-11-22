#include <cmath>
#include <iostream>
using namespace std;

long long addBinary(int a, int b){
	int carry = 0;
	int i = 0;
	int result= 0;
	while(a != 0 || b != 0){
		int bit1 = a % 10;
		int bit2 = b % 10;
		int sum = bit1 + bit2 + carry; 
		carry = sum / 2;
		int si = sum % 2;

		result = result + si*pow(10,i);
		i++;
		a/=10;
		b/=10;
	}
	return result;
}

int main(){
	int a = 111, b = 1011;
	cout << addBinary(a,b);
	return 0;
}
