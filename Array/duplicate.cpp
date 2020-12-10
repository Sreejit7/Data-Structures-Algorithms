/**
 * Given an array of integers nums containing n + 1 integers 
 * where each integer is in the range [1, n] inclusive.
  There is only one duplicate number in nums,
  return this duplicate number.
 * 
 **/

#include<bits/stdc++.h>
using namespace std;
//Approach: Sorting , O(n log(n)) time
int findDuplicate(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int i;
  for(i = 1; i < nums.size(); i ++){
      if(nums[i] == nums[i - 1])
          break;
  }
  return nums[i];
}
// Approach: linear search O(n ^ 2) time
int findDuplicate2(vector<int>& nums) {
  for(int i = 1; i < nums.size(); i++){
    for(int j = 0; j <= i - 1; j ++){
      if(nums[j] == nums[i])
        return nums[i];
    }
  }
  return -1;
}
//Approach: using hash set O(n) time & space
int findDuplicate3(vector<int>& nums) {
  unordered_set<int> elems;
  for(int i = 0; i < nums.size(); i++){
    if(elems.find(nums[i]) == elems.end()){
      elems.insert(nums[i]);
    }
    else{
      return nums[i];
    }
  }
  return -1;
}
//Approach: Floyd's hare and tortoise, O(n) time
int findDuplicate(vector<int>& nums) {
  int hare = nums[0] , tortoise = nums[0];
  do{
    hare = nums[nums[hare]];
    tortoise = nums[tortoise];
  }while (hare != tortoise);

  tortoise = nums[0];
  while( hare != tortoise){
    hare = nums[hare];
    tortoise = nums[tortoise];
  }
  return hare;
}