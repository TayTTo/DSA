#include <iostream>
#include <map>
using namespace std;

int main(){
	int n;
	cin >>n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	map<int, int> mp;
	for(int i = 0; i < n; i++){
		mp[a[i]]++;
	}

	int q;
	cin >> q;
	while (q--) {
		int number;
		cin >> number;
		
		//fetch
		cout << mp[number] << endl;
	}
	return 0;
}
