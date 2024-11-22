#include <iostream>
using namespace std;

void checkOddOrEven(int& n){
	if((n & 1) == 1) cout << "Odd";
	else cout << "Even";
}

int main(){
	int n;
	cin >> n;
	checkOddOrEven(n);
	return 0;
}
