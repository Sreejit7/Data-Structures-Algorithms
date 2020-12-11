/*
  Given an unsorted array of size n. 
  Array elements are in the range from 1 to n.
  One number from set {1, 2, …n} is missing 
  and one number occurs twice in the array. 
  Find these two numbers.
*/

#include<bits/stdc++.h>
using namespace std;

//Approach1: Sorting O(nlog(n)) time
vector <int> repeatandmissing(vector <int> &arr, int n){
  int repeat = 0, miss = 0;
  sort(arr.begin(), arr.end());
  for(int i = 0; i < arr.size(); i++){
    if((arr[i] != i + 1) && miss == 0)
      miss = i + 1;
    if(i > 0 && arr[i] == arr[i - 1])
      repeat = arr[i];
  }
  return {miss, repeat};
}
//Approach2: Mapping method O(n) time & space
vector <int> repeatandmissing2(vector <int> &arr, int n){
  int repeat = 0, miss = 0;
  unordered_map<int, int> count;
  for(int i = 0; i < arr.size(); i++){
    if(count.find(arr[i]) == count.end())
      count.insert({arr[i], 1});
    else
      repeat = arr[i];
  }
  for(int i = 1; i <= n; i++){
    if(count.find(i) == count.end())
      miss = i;
  }
  return {miss, repeat};
}
//Approach3: Negation marking method, O(n) time
vector <int> repeatandmissing3(vector <int> &arr, int n){
  int repeat = 0, miss = 0;
  for(int i = 0; i < arr.size(); i++){
    if(arr[abs(arr[i]) - 1] > 0){
      arr[abs(arr[i]) - 1] = - arr[abs(arr[i]) - 1];
    }
    else
      repeat = abs(arr[i]);
  }
  for(int i = 0; i < arr.size(); i++){
    if(arr[i] > 0)
      miss = i + 1;
  }
  return {miss, repeat};
}

int main(){
  
  int n;
  cin>> n;
  vector <int> arr(n, 0);
  for(int i = 0; i < n; i++)
    cin>> arr[i];
  vector <int> res = repeatandmissing(arr, n);
  cout<< res[0] <<" "<<res[1]<<"\n";
  res = repeatandmissing2(arr, n);
  cout<< res[0] <<" "<<res[1]<<"\n";
  res = repeatandmissing3(arr, n);
  cout<< res[0] <<" "<<res[1]<<"\n";
}