/* 
    Given two strings, find the longest common sub-sequence of both strings.
    Sub-sequence means the characters are in same order in both strings, not necessarily adjacent.
*/

#include <bits/stdc++.h>
using namespace std;
//Approach 1: O(nm*min(n,m)) time & space
vector<char> longestCommonSubsequence(string str1, string str2) {
  int m = str1.length(), n = str2.length();
	vector<vector<string>> LCS(m+1,vector<string>(n+1,""));
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(str1[i-1] == str2[j-1]){
				LCS[i][j] = LCS[i-1][j-1] + str1[i-1];
			}
			else{
				string r = LCS[i][j-1], c= LCS[i-1][j];
				if(r.length() > c.length())
					LCS[i][j] = r;
				else
					LCS[i][j] = c;
			}
		}
	}
	vector <char> res;
	for(int k = 0; k < LCS[m][n].length(); k++){
		res.push_back(LCS[m][n][k]);
	}
  return res;
}
//Approach2: O(nm) time, O(nm) space
vector <char> buildSequence(vector<vector<vector<int>>> lcs);
vector<char> longestCommonSubsequence2(string str1, string str2) {
	int m = str1.length(), n = str2.length();
  vector<vector<vector<int>>> lcs(m+1,vector<vector<int>>(n+1,vector<int>(4,0)));
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(str1[i-1] == str2[j-1]){
				lcs[i][j] = {str1[i-1], lcs[i-1][j-1][1] + 1, i-1, j-1};
			}
			else{
				if(lcs[i-1][j][1] > lcs[i][j-1][1])
					lcs[i][j] = {-1, lcs[i-1][j][1], i-1, j};
				else
					lcs[i][j] = {-1, lcs[i][j-1][1], i, j-1};
			}	
		}
	}
	return buildSequence(lcs);
}
vector <char> buildSequence(vector<vector<vector<int>>> lcs){
	int i = lcs.size() - 1, j = lcs[0].size() - 1;
	vector<char> res;
	while(i != 0 && j != 0){
		vector<int> current = lcs[i][j];
		if(current[0] != -1){
			res.insert(res.begin(), current[0]);
		}
		i = current[2];
		j = current[3];
	}
	return res;
}
//Approach 3: O(nm) time, O(nm) space
vector <char> buildSequence2(vector<vector<int>> lengths, string str);
vector<char> longestCommonSubsequence(string str1, string str2) {
	int m = str1.length(), n = str2.length();
  	vector<vector<int>> lengths(m + 1, vector <int> (n + 1, 0));
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(str1[i - 1] == str2[j - 1]){
				lengths[i][j] = lengths[i-1][j-1] + 1;
			}
			else{
				int r = lengths[i][j - 1];
				int c = lengths[i - 1][j];
				lengths[i][j] = max(r,c);
			}
		}
	}
  return buildSequence2(lengths,str1);
}
vector <char> buildSequence2(vector<vector<int>> lengths, string str){
	vector <char> res;
	int i = lengths.size() - 1, j = lengths[0].size() - 1;
	while(i!= 0 && j!= 0){
		if(lengths[i-1][j] == lengths[i][j]){
			i--;
		}
		else if(lengths[i][j-1] == lengths[i][j]){
			j--;
		}
		else{
			res.insert(res.begin(),str[i-1]);
			i--; j--;
		}
	}
	return res;
}
int main(){
    string str1, str2;
    cin>> str1>> str2;
    vector <char> res = longestCommonSubsequence2(str1,str2);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
}