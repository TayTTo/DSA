#include<iostream>
#include <stack>
using namespace std;

string preToIn(string &s) {
	int i = s.size() - 1;
	stack<string> st;
	while ( i >= 0) {
		string temp(1, s[i]);
		if ( s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9' ){
			st.push(temp);
			i--;
		}
		else {
			string t1 = st.top(); st.pop();
			string t2 = st.top(); st.pop();
			st.push('(' + t1 + temp + t2 + ')');
			i--;
		}
	}
	return st.top();
}


int main(){
	string s;
	cin >> s;
	string ans = preToIn(s);
	cout << ans;
	return 0;
}
