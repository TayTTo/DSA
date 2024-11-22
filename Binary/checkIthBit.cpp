#include <iostream>
using namespace std;

int check(int& n, int& k){
	if(((n >> k) & 1) != 0){
		return 1;
	}
	return 0;
}

int main(){
	int n, k;
	cin >> n >> k;
	if(check(n, k) == 1) cout << "Yes";
	else cout << "NO";
	return 0;
}
