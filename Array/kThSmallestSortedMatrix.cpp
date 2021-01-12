/**
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
 * find the kth smallest element in the matrix.
 **/

#include<bits/stdc++.h>
using namespace std;

//Approach: Min heap(O(n*n) time, O(k) space)
int kthSmallest(vector<vector<int>>& matrix, int k) {
  priority_queue <int> max_heap;
  int n = matrix.size();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      max_heap.push(matrix[i][j]);
      if(max_heap.size() > k)
        max_heap.pop();
    }
  }
  return max_heap.top();   
}
int main(){
  int n, k;
  cin>>n>>k;
  vector <vector <int>> matrix;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>> matrix[i][j];
    }
  }
  cout<<kthSmallest(matrix, k)<<endl;
}