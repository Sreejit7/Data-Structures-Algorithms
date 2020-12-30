#include<bits/stdc++.h>
using namespace std;
// Given a non-empty array of integers nums, every element appears twice except for one. 
// Find that single one.

//Approach1: HashTable approach O(n) time & space
int singleNumber(vector <int> nums){
  unordered_map <int, int> count;
  for(int i = 0; i < nums.size(); i++){
      if(count.find(nums[i]) == count.end())
          count.insert({nums[i], 1});
      else
          count[nums[i]] ++;
  }
  for(auto x: count){
      if(x.second == 1)
          return x.first;
  }
  return - 1;
}
//Approach2: BIT Manipulation approach, O(n) time. [a ^ a = 0, b ^ 0 = b]
int singleNumber2(vector <int> nums){
  int single = 0;
  for(int i: nums){
    single ^= i;
  }
  return single;
}

int main(){
  int n;
  cin>>n;
  vector <int> nums(n, 0);
  for(int i = 0; i < n; i++)
    cin>> nums[i];
  cout<<singleNumber2(nums)<<"\n";
}