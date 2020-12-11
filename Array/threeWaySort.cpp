#include<bits/stdc++.h>
using namespace std;
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