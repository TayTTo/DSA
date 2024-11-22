#include <iostream>
using namespace std;

int toggle_ith_bit(int& n, int& i){
	return (n ^ (1<<i));
}

int main(){
	int n, i;
	cin >> n >> i;
	cout << toggle_ith_bit(n, i);
	return 0;
}
