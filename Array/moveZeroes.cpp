/**
 * Given an array nums, write a function to move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 **/
#include<bits/stdc++.h>
using namespace std;

//Two pointer approach: O(n) time
void moveZeroes(vector<int>& nums) {
  int i = 0, j = 1;
  while(j < nums.size()){
    if(nums[i] == 0 && nums[j] != 0){
        swap(nums[i], nums[j]);
        i ++, j++;
    }
    else if(nums[i] == 0 && nums[j] == 0)
        j ++;
    else
        i ++, j ++;
  }
}
int main(){
  int n;
  cin>>n;
  vector <int> nums (n);
  for(int i = 0; i < n; i++){
    cin>> nums[i];
  }
  moveZeroes(nums);
  for(int i: nums)
    cout<<i<<" ";
  cout<<endl;
}