/** 
 * Given an input string and a substring, 
 * wrap all instances of the substring in the string with _(underscore)s.
 * If two or more instances of the substring overlap, 
 * then only add _s before the first occurence and after the last occurence.
 **/

#include<bits/stdc++.h>
using namespace std;

//Approach: O(n * m)  time, O(n+m) space where m = length of input string.

string underscorifySubstring(string str, string subStr) {
  vector<pair<int,int>> positions, collapsed;
  int m = str.length(), n = subStr.length();
  for(int i = 0; i < m; i++){
    if(str.substr(i,n) == subStr)
      positions.push_back({i, i + n - 1});
  }
  int i = 0, start = positions[0].first, end = positions[0].second;
  while(i < positions.size() - 1){
    if(positions[i+1].first - end <= 1){
      end = positions[i+1].second;
      i++;
    }
    else{
      collapsed.push_back({start,end});
      start = positions[i+1].first;
      end = positions[i+1].second;
      i++;
    }
  }
  collapsed.push_back({start,end});
  string res = "";
  int k = 0;
  for(auto x: collapsed){
    res += str.substr(k, x.first - k) + "_" + str.substr(x.first, x.second - x.first + 1) + "_";
    k = x.second + 1;
  }
  res += str.substr(k, n - k);
  return res;  
}
int main(){
  string str, subStr;
  cout<<underscorifySubstring("testthis is a testtest to see if testestest it works","test")<<endl;
}
