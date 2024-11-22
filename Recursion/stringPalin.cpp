#include <iostream>
#include <string>
using namespace std;

//bool checkPalindrome(string s) {
//	int left = 0, right = s.length() - 1;
//	while(left < right){
//		if(!isalnum(s[left])) left++;
//		else if (!isalnum(s[right])) right--;
//		else if(tolower(s[left]) != tolower(s[right])) return false;
//		else{
//			left++;
//			right--;
//		}
//	}
//	return true;
//}

bool checkPalindrome(int i, string &str){
	if(i >= str.length()/2) return true;
	if(str[i] != str[str.length() - i - 1]) return false;
	return checkPalindrome(i + 1, str);
}



int main(){
	string str = "MADAM";
	//cin >> str;
	cout<<checkPalindrome(0, str);
	return 0;
}

