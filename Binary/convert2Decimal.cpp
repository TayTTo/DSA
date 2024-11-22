#include <iostream>
using namespace std;

int convert2Decimal(string n){
	int num = 0;
	int power_2 = 1;
	int length_of_string = n.length();
	for(int i = length_of_string - 1; i >= 0; i--){
		if(n[i] == '1'){
			num += power_2;
		}
		power_2 *= 2;
	}
	return num;
}

int main(){
	string n;
	cin >> n;
	cout << convert2Decimal(n);
	return 0;
}
