/**
 *  Two strings are anagrams of each other if the letters of one string 
 *  can be rearranged to form the other string. 
 *  Given a set of words, group the anagrams together.
 **/

#include<bits/stdc++.h>
using namespace std;

//Approach 1: O(n^3*log(n)) time, O(n^2) space
map<char,int> count(string s){
  map <char,int> charCount;
  for(int i = 0; i < s.length(); i++){
    if(charCount.find(s[i]) == charCount.end()){
      charCount.insert({s[i],1});
    }
    else
    {
      charCount[s[i]]++;
    }
  }
  return charCount;
}
vector<vector<string>> groupAnagrams(vector<string> words) {
  unordered_set<string> visited;
  vector <vector <string>> res;
  for(int i = 0; i < words.size(); i++){
    if(visited.find(words[i]) == visited.end()){
      vector <string> current;
      current.push_back(words[i]);
      for(int j = i + 1; j < words.size(); j++){
        if(count(words[j]) == count(words[i])){
          current.push_back(words[j]);
          visited.insert(words[j]);
        }
      }
      res.push_back(current);
    }
  }
  return res;
}

//Approach2: O(n^2log(n)) time, O(n^2) space

vector<vector<string>> groupAnagrams2(vector<string> words) {
	unordered_map<string,vector<string>> anagrams;
  for(auto word: words){
		auto sortedWord = word;
		sort(sortedWord.begin(),sortedWord.end());
		if(anagrams.find(sortedWord) == anagrams.end()){
			anagrams[sortedWord] = vector<string>{word}; 
		}
		else{
			anagrams[sortedWord].push_back(word);
		}
	}
	vector<vector<string>> res;
	for(auto x: anagrams){
		res.push_back(x.second);
	}
  return res;
}

int main(){
  vector <string> words;
  int n;
  cin>>n;
  for(int i = 0; i < n; i++){
    string in;
    cin>>in;
    words.push_back(in);
  }
  vector<vector<string>> result = groupAnagrams2(words);
  for(int i = 0; i < result.size(); i++){
    for(int j = 0; j < result[i].size(); j++){
      cout<<result[i][j]<<" ";
    }
    cout<<"\t";
  }
  cout<<endl;
}