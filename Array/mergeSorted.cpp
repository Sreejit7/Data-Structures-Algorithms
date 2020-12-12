/*
  Given two sorted arrays, 
  we need to merge them with O(1) extra space into a sorted array.
*/

#include<bits/stdc++.h>
using namespace std;

//Approach1: O(m*n) time
vector <int> mergeSorted(vector<int> &a, vector <int> &b){
  int m = a.size(), n = b.size();
  a.resize(m + n);
  int i = 0, j = 0;
  while(i < m || j < n){
    if(a[i] < b[j])
      i++;
    else{
      for(int k = i + m; k > i; k--){
        a[k] = a[k - 1];
      }
      a[i] = b[j];
      i++, j++;
    }
  }
  return a;
}
//Approach2: Gap method, O((n + m) * log(n + m)) time
void mergeSorted2(vector <int> &a, vector <int> &b){
  int m = a.size(), n = b.size(), i, j;
  int gap = ceil((m + n)/2);
  while (gap > 0)
  {
    for(i = 0; i + gap < m; i++){
      if(a[i] > a[i + gap])
        swap(a[i], a[i + gap]);
    }
    for(j = (gap > m)? gap - m: 0; i < m && j < n; i ++, j++){
      if(a[i] > b[j])
        swap(a[i], b[j]);
    }
    for(j = 0; j + gap < n; j ++){
      if(b[j] > b[j + gap])
        swap(b[j], b[j + gap]);
    }
    gap = ceil(gap / 2);
  }
  
}
int main(){
  vector <int> a = {1, 5, 9, 10, 15, 20};
  vector <int> b = {2, 3, 8, 13};
  mergeSorted2(a, b);
  for(int i: a)
    cout<< i <<" ";
  for(int i : b)
    cout<< i << " ";
  cout<<endl;
  /*vector <int> res = mergeSorted(a, b);
  for(int i = 0; i < res.size(); i++)
    cout<<res[i]<<" ";
  cout<<endl;*/
  
}