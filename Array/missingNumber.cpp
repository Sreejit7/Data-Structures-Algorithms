/**
 * Given an array nums containing n distinct numbers in the range [0, n], 
 * return the only number in the range that is missing from the array.
 **/

#include<bits/stdc++.h>
using namespace std;
//Approach1: Count array (O(n) time & space)
int missingNumber(vector<int>& nums) {
  int n = nums.size();
  vector <bool> count(n + 1, false);
  for(int elem: nums){
    count[elem] = true;
  }
  for(int i = 0; i <= n; i++){
    if(count[i] == false)
      return i;
  }
  return n;
}
//Approach2: Sorting (O(n*log(n)) time)
int missingNumber(vector<int>& nums) {
  int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
      if(nums[i] != i)
        return i;
    }
    return n;
}
//Approach3: Bit Manipulation (O(n) time)
int missingNumber3(vector<int>& nums) {
  int n = nums.size();
  int missing = n;
  for(int i = 0; i < n; i++){
      missing ^= nums[i] ^ i;
  }
  return missing;
}