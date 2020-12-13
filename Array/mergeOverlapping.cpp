/*
  Given an array of intervals where intervals[i] = [starti, endi], 
  merge all overlapping intervals, and return an array 
  of the non-overlapping intervals that cover all the intervals in the input.
*/
#include<bits/stdc++.h>
using namespace std;

//Approach: O(nlog(n)) time
static bool sortTasks(vector <int> &a, vector <int> &b){
  if(a[0] == b[0])
    return a[1] < b[1];
  return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end(), sortTasks);
  vector<vector<int>> mergedIntervals;
  mergedIntervals.push_back(intervals[0]);
  int j = 0;
  for(int i = 1; i < intervals.size(); i++){
    if(intervals[i][0] < mergedIntervals[j][1])
      mergedIntervals[j][1] = max(mergedIntervals[j][1], intervals[i][1]);
    else{
      mergedIntervals.push_back(intervals[i]);
      j++;
    }
  }
  return mergedIntervals;
}

int main(){
  vector <vector <int>> intervals = {{1, 4}, {1, 4}, {8, 10}, {15, 18}};
  vector<vector<int>> res = merge(intervals);
  for(auto x: res){
    cout<<x[0]<<" "<<x[1]<<endl;
  }
}