#include<bits/stdc++.h>
using namespace std;
/**
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times. 
 **/

//Approach1: Hash Table, O(n) time & space
int majorityElement(vector<int>& nums) {
  unordered_map<int, int> count;
  for(int i = 0; i < nums.size(); i++){
      if(count.find(nums[i]) == count.end()){
          count.insert({nums[i], 1});
      }
      else
          count[nums[i]] ++;
  }
  int majority = nums[0];
  for(auto x: count){
      if(x.second > count[majority])
          majority = x.first;
  }
  return majority;
}

//Approach2: Sorting, O(n * log n) time
int majorityElement2(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int mid = floor(nums.size() / 2);
  return nums[mid];
}

//Approach3: Divide & Conquer, O(n * log n) time, O(log n) space
int count(vector <int> nums, int num, int low, int high){
  int c = 0;
  for(int i = low; i <= high; i++){
      if(nums[i] == num)
          c++;
  }
  return c;
}
int majorityHelper(vector <int> &nums, int low, int high){
  if(low == high)
      return nums[low];
  int mid = low + (high - low) / 2;
  int leftMajor = majorityHelper(nums, low, mid);
  int rightMajor = majorityHelper(nums, mid + 1, high);
  if(leftMajor == rightMajor)
      return leftMajor;
  if(count(nums, leftMajor, low, high) > count(nums, rightMajor, low, high)){
      return leftMajor;
  }
  return rightMajor;
}
int majorityElement3(vector<int>& nums) {
  return majorityHelper(nums, 0, nums.size() - 1);
}

//Approach4: Boyer-Moore voting algo, O(n) time 
int majorityElement4(vector<int>& nums) {
  int majority = nums[0], count = 1;
  for(int i = 1; i < nums.size(); i++){
    if(count == 0)
        majority = nums[i];
    if(nums [i] == majority)
        count++;
    else
        count --;
  }
  return majority;
}
int main(){
  int n;
  cin>>n;
  vector <int> nums (n);
  for(int i = 0; i < n; i++)
    cin>>nums[i];
  cout<<majorityElement4(nums)<<endl;

}