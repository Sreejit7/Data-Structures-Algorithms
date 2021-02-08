/**
 * A peak element is an element that is strictly greater than its neighbors.
 * Given an integer array nums, find a peak element, 
 * and return its index. If the array contains multiple peaks, 
 * return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞.
 **/
#include<bits/stdc++.h>
using namespace std;

//Approach1: Linear Search, O(n) time
int findPeakElement(vector<int>& nums) {
    if(nums.size() == 1)
        return 0;
    if(nums[0] > nums[1])
        return 0;
    int n = nums.size();
    if(nums[n - 1] > nums[n - 2])
        return n - 1;
    for(int i = 1; i < n - 1; i ++){
        if(nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
            return i;
    }
    return n - 1;
}

//Approach2: Binary Search, O(log(n)) time
int peakElement(vector <int> &nums, int low, int high){
    if(low == high)
        return low;
    int mid = low + (high - low)/ 2;
    if(nums[mid] < nums[mid + 1])
        return peakElement(nums, mid + 1, high);
    return peakElement(nums, low, mid);
}
int findPeakElement2(vector<int>& nums) {
    if(nums.size() == 1)
        return 0;
    int n = nums.size();
    return peakElement(nums, 0, n - 1);
}

int main(){
  int n;
  cin>>n;
  vector <int> nums(n);
  for(int i = 0; i < n; i++){
    cin>> nums[i];
  }
  cout<<findPeakElement2(nums)<<endl;
}