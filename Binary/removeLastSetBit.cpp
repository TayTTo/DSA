#include <iostream>
using namespace std;

int remove_last_set_bit(int& n){
	return (n & (n - 1));
}

int main(){
	int n;
	cin >> n;
	cout << remove_last_set_bit(n);
	return 0;
}
