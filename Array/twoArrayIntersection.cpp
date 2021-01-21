//Given two arrays, write a function to compute their intersection.

#include<bits/stdc++.h>
using namespace std;

//Approach1: Hash Table approach (O(n) time & space)
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  int n1 = nums1.size(), n2 = nums2.size();
  unordered_map <int, int> count;
  vector <int> intersection;
  if(n1 < n2){
    for(int i = 0; i < n1; i++){
      count[nums1[i]] ++;
    }
    for(int i = 0; i < n2; i++){
      if(count[nums2[i]] > 0){
        intersection.push_back(nums2[i]);
        count[nums2[i]] --;
      }
    }
  }
  else{
    for(int i = 0; i < n2; i++){
      count[nums2[i]] ++;
    }
    for(int i = 0; i < n1; i++){
      if(count[nums1[i]] > 0)
        intersection.push_back(nums1[i]);
        count[nums1[i]] --;
    }
  }
  return intersection;
}
//Approach2: Two-pointer approach (O(n*logn)) time
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
  int n1 = nums1.size(), n2 = nums2.size();
  vector <int> intersection;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(nums1[i] == nums2[j]){
            intersection.push_back(nums1[i]);
            i++, j++;
        }
        else if(nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
  return intersection;
}
int main(){
  int n1, n2;
  cin>>n1>>n2;
  vector <int> nums1(n1), nums2(n2);
  for(int i = 0; i < n1; i ++)
    cin>> nums1[i];
  for(int i = 0; i < n2; i ++)
    cin>> nums2[i];
  vector <int> res = intersect2(nums1, nums2);
  for(int item: res){
    cout<<item<<" ";
  }
  cout<<endl;
}