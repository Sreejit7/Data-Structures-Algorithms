/*
    Given an array of integers, 
    generate all permutations possible from the set of integers.
*/

#include<bits/stdc++.h>
using namespace std;
//Approach 1: O(n * n!) time, O(n * n!) space
void getPer(vector <int> arr, vector <int> perm, vector <vector<int>> *perms){
	if(arr.size() == 0 && perm.size() > 0){
		perms->push_back(perm);
	}
	else{
		for(int i = 0; i < arr.size(); i++){
			vector<int> newArr;
			newArr.insert(newArr.end(),arr.begin(),arr.begin() + i);
			newArr.insert(newArr.end(),arr.begin() + i + 1, arr.end());
			vector <int> newPerm = perm;
			newPerm.push_back(arr[i]);
			getPer(newArr, newPerm , perms);
		}
	}
}
vector<vector<int>> getPermutations(vector<int> array) {
  vector <vector <int>> perms;
  getPer(array, {}, &perms);
	return perms;
}

int main(){
  int n;
  vector <int> arr(n, 0);
  for(int i = 0; i < n; i++){
    cin>> arr[i];
  }
  vector <vector <int>> res = getPermutations(arr);
  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[0].size(); j++){
      cout<< res[i][j]<<" ";
    }
    cout<<endl;
  }
}