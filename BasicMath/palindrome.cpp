#include <iostream>
using namespace std;

bool palindrome(int n){
	int temp = n, palindrome = 0;
	while(n > 0){
		palindrome = palindrome * 10 + n % 10;
		n /= 10;
	}
	if(temp == palindrome) return true;
	else return false;
}

int main(){
	int n;
	cin >> n;
	if(palindrome(n) == true){
		cout<<"True";
	}
	else cout << "False";
	return 0;
}

