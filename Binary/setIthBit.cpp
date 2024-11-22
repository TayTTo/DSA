#include <iostream>
using namespace std;

int setIthBit(int& n , int& k){
	return (n | (1 << k));
}

int main(){
	int n, k;
	cin >> n >> k;
	cout << setIthBit(n, k);
	return 0;
}
