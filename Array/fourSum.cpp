/**
 * Given four lists A, B, C, D of integer values, 
 * compute how many tuples (i, j, k, l) there are 
 * such that A[i] + B[j] + C[k] + D[l] = 0.
 **/
#include<bits/stdc++.h>
using namespace std;

//Approach: O(n ^ 4) time
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
  int count = 0;
  for(int a: A){
      for(int b: B){
          for(int c: C){
              for(int d: D){
                  if(a + b + c + d == 0)
                      count ++;
              }
          }
      }
  }
  return count;
}
//Approach: O(n ^ 3) time, O(n) space
int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> nums;
    for(int d: D){
        nums[d] ++;
    }
    int count = 0, current;
    for(int a: A){
        for(int b: B){
            for(int c: C){
                count += nums[-(a + b + c)];
            }
        }
    }
    return count;
}
//Approach: O(n * n) time, O(n) space
int fourSumCount3(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
  unordered_map<int, int> nums;
  for(int c: C){
      for(int d: D){
          nums[c + d] ++;
      }
  }
  int count = 0;
  for(int a: A){
      for(int b: B){                
              count += nums[-(a + b)];
      }
  }
  return count;
}
int main(){
  int n;
  cin>>n;
  vector <int> A(n), B(n), C(n), D(n);
  for(int i = 0; i < n; i ++){
    cin>> A[i] >> B[i] >> C[i] >> D[i];
  }
  cout<<fourSumCount3(A, B, C, D)<<endl;
}