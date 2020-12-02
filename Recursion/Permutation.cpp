/*
    Given an array of integers, 
    generate all permutations possible from the set of integers.
*/

#include<bits/stdc++.h>
using namespace std;
//Approach 1: O(n * n!) time [O(n^2 * n!) in worst case ], O(n * n!) space 
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

//Approach2: O(n * n!) time, O(n * n!) space

void helper(int idx, vector <int> &arr, vector <vector<int>> &perms){
	if(idx == arr.size() - 1){
		perms.push_back(arr);
	}
	else{
		for(int j = idx; j < arr.size(); j++){
			swap(arr[idx], arr[j]);
			helper(idx + 1, arr, perms);
			swap(arr[j], arr[idx]);
		}
	}
}
vector<vector<int>> getPermutations2(vector<int> array) {
  vector <vector <int>> res;
	helper(0, array, res);
  return res;
}

int main(){
  int n;
  vector <int> arr(n, 0);
  for(int i = 0; i < n; i++){
    cin>> arr[i];
  }
  vector <vector <int>> res = getPermutations2(arr);
  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[0].size(); j++){
      cout<< res[i][j]<<" ";
    }
    cout<<endl;
  }
}