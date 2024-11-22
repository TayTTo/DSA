#include <algorithm>
#include<iostream>
#include <stack>
#include <string>
using namespace std;

int prio (char n){
	if(n == '^') return 3;
	else if ( n == '*' || n == '/') return 2;
	else if ( n == '+' || n == '-') return 1;
	else return -1;
}

string prefixToInfix(string& s) {
	string ans = "";
	reverse(s.begin(), s.end());
	stack<char> st;
	int size = s.size();
	for(int i = 0; i < size; i++) {
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
			ans = ans + s[i];
		}
		else if (s[i] == ')') {
			st.push(s[i]);
		}
		else if (s[i] == '(') {
			while ( !st.empty() && st.top() != ')') {
				ans = ans + st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			if(s[i] == '^') {
				while (!st.empty() && prio(s[i]) <= prio(st.top())){
					ans = ans + st.top();
					st.pop();
				}
			}	
			else {
				while (!st.empty() && prio(s[i]) < prio(st.top())) {
					ans = ans + st.top();
					st.pop();
				}
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		ans = ans + st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
							
								
	
int main(){
	string s;
	cin >> s;
	string ans = prefixToInfix(s);
	cout << ans;
	return 0;
}
