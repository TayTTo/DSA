#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string convert2Binary(int n){
	string res = "";
	while(n != 1){
		if(n % 2 == 1) res += "1";
		else res += "0";
		n /= 2;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main(){
	int a;
	cin >> a;
	cout << convert2Binary(a);
	return 0;
}
