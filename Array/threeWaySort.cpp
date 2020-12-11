/*
  Given an array nums with n objects colored red, white, or blue, 
  sort them in-place so that objects of the same color are adjacent, 
  with the colors in the order red, white, and blue.
  Here, we will use the integers 0, 1, and 2 
  to represent the color red, white, and blue respectively.
*/
#include<bits/stdc++.h>
using namespace std;

//Approach1: O(n) time, 2 pointer approach
void sortColors1(vector<int>& nums) {
  int l = 0, i = 0, r = nums.size() - 1;
  while(i <= r){
      if(nums[i] == 0){
          swap(nums[i ++], nums[l ++]);
      }
      else if(nums[i] == 2){
          swap(nums[i], nums [r --]);
      }
      else
          i++;
  }
}
//Approach2: O(3*n) time, count array approach
void sortColors2(vector<int>& nums) {
  vector<int> count(3, 0);
  for(int i = 0; i < nums.size(); i++){
      count[nums[i]] ++;
  }
  int j = 0;
  for(int i = 0; i <= 2; i++){
    int k = j;
    while(j < k + count[i]){
        nums[j] = i;
        j++;
    }
  }  
}
int main(){
  int n;
  cin>>n;
  vector <int> nums(n, 0);
  for(int i = 0; i < n; i++)
    cin>> nums[i];
  sortColors1(nums);
  for(int i = 0; i < n; i++)
    cout<< nums[i];
}