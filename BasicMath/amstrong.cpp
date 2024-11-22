#include <iostream>
#include <math.h>
using namespace std;

int asmtrong(int n){
	int tmp = n, sum = 0, cnt = int(log10(n) + 1);
	while(n > 0){
		sum = sum + pow((n % 10), cnt);
		n /= 10;
	}
	if(tmp == sum) return 1;
	else return 0;
}


int main(){
	int n;
	cin >> n;
	if(asmtrong(n) == 1) cout << "True";
	else cout << "False";
	return 0;
}
