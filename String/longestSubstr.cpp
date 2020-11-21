/*
  Write a function that takes in a string & return its longest substring
  without duplicate characters.
*/

#include<bits/stdc++.h>
using namespace std;
//Approach: O(n) time & space
string longestSubstringWithoutDuplication(string str) {
  unordered_map<char,int> lastOcc;
  int i = 0, start = 0;
  string max = "";
  while(i < str.length()){
		if(lastOcc.find(str[i]) != lastOcc.end() && lastOcc[str[i]] >= start){
			string sub = str.substr(start, i - start);
			(sub.length() > max.length())?(max = sub): (max = max);
			start = lastOcc[str[i]] + 1;
			lastOcc[str[i]] = i;
		}
		else {
			lastOcc[str[i]] = i;
		}
		i++;
	}
	if(start == 0)
		return str;
	if(start < str.length() - 1){
		string sub = str.substr(start, str.length() - start);
		(sub.length() > max.length())?(max = sub): (max = max);
	}
	return max;
}

int main(){
  string str;
  cin>>str;
  cout<<longestSubstringWithoutDuplication(str)<<endl;
}