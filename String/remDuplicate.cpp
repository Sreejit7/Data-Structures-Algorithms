/*
  Given a string s, remove duplicate letters so that 
  every letter appears once and only once. 
  You must make sure your result is the smallest in lexicographical order 
  among all possible results.
*/

#include<bits/stdc++.h>
using namespace std;
//Approach: O(n^2) time in worst case, O(n) space
string removeDuplicateLetters(string s) {
  stack <char> unique;
  unordered_set <char> visited;
  vector <int> count(26, 0);
  for(char c: s){
    count[c - 'a'] ++;
  }
  vector <char> charArr(s.begin(), s.end());
  for(char c: charArr){
    count[c - 'a']--;
    if(visited.find(c) != visited.end())
      continue;
    while(!unique.empty() && unique.top() > c && count[unique.top() - 'a'] > 0){
      visited.erase(unique.top());
      unique.pop();
    }
    unique.push(c);
  }
  string res;
  while(!unique.empty()){
    res.insert(res.begin(),unique.top());
    unique.pop();
  }
  return res;
}
int main(){
  string str;
  cin>>str;
  cout<<removeDuplicateLetters(str)<<endl;
}