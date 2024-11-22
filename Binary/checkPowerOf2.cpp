#include <iostream>
using namespace std;

int check_power_of_2(int n){
	return (n & (n - 1));
}

int main(){
	int n;
	cin >> n;
	if(check_power_of_2(n) == 0) cout << "This is number of p2";
	else cout << "No";
	return 0;
}
