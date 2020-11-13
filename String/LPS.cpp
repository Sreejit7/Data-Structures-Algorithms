/**
 * Given a string, find its longest palindromic substring.
 **/

#include<bits/stdc++.h>
using namespace std;

//Approach 1: O(n^3) time, O(n) space

bool palindrome(string str){
	if(str.length() == 1)
		return true;
	else if(str.length() == 2 && str[0] == str[1])
		return true;
	int i = 0, j = str.length() - 1;
	while(i < j){
		if(str[i] != str[j])
			return false;
		i++; j--;
	}
	return true;
}
string longestPalindromicSubstring(string str) {
	if(str.empty() || palindrome(str))
		return str;
	string lps = "";
  for(int i = 0; i < str.length() - 1; i++){
		for(int j = 1; j <= str.length()-i; j++){
			string sub = str.substr(i, j);
			if(palindrome(sub) && sub.length() > lps.length())
				lps = sub;
		}
	}
  return lps;
}

//Approach 2: O(n^2) time , O(n) space
string longestPalindromicSubstring2(string str) {
  string lps = "";
	int n = str.length();
	for(int i = 0; i < str.length(); i++){
		string pre = "", post = "";
		int j = i - 1, k = i + 1;
		while(j >= 0 && k <= n-1){
			if(str[j] == str[k]){
				pre = str[j] + pre;
				post = post + str[k];
				j--; k++;
			}
			else
				break;
		}
		string current = pre + str[i] + post;
		if(current.length() > lps.length())
			lps = current;
	  pre = "", post = "";
	  j = i -1, k = i ;
		while(j >= 0 && k <= n-1){
			if(str[j] == str[k]){
				pre = str[j] + pre;
				post = post + str[k];
				j--; k++;
			}
			else
				break;
		}
	  current = pre + post;
		if(current.length() > lps.length())
			lps = current;
	}
	return lps;
}
int main(){
    string str;
    cin>>str;
    cout<<"Longest Palindromic Substring:"<<longestPalindromicSubstring2(str)<<endl;
}