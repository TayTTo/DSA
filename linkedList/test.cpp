#include <iostream>
using namespace std;

int main(){
	int x = 2;
	int* y = &x;
	int* z = y;
	cout << y << " " << *y << endl;
	cout << z << " " << *z;
	return 0;
}
