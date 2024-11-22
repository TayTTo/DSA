#include <iostream>
using namespace std;

int count_number_of_set_bit(int n){
	int count = 0;
	while(n != 0){
		n = n & (n - 1);
		count++;
	}
	return count;
}

//int count_number_of_set_bit(int n){
//	int count = 0;
//	while(n > 1){
//		count += n & 1;
//		n = (n >> 1);
//	}
//	if(n == 1) count += 1;
//	return count;
//}

int main(){
	int n;
	cin >> n;
	cout << count_number_of_set_bit(n);
	return 0;
}
