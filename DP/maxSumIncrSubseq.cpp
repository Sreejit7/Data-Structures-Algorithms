/*
	Write a function that takes in an array of non-negative integers and 
	returns the maximum possible sum of elements in a strictly increasing subsequence
	as well as the elements in that subsequence.
*/
#include <bits/stdc++.h>
using namespace std;

//Approach: O(n^2) Time, O(n) Space

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  vector <int> sum = array;
	vector <int> sequences (array.size(), INT_MIN);
	int maxIndex = 0;
	for(int i = 0; i < array.size(); i++){
		int current = array[i];
		for(int j = 0;j < i; j++){
			int previous = array[j];
			if(previous < current && sum[j] + current >= sum[i]){
				sum [i] = current + sum[j];
				sequences[i] = j;
			}
		}
		if(sum[i] > sum[maxIndex])
			maxIndex = i;
	}
	set <int> maxSubSeq;
	int i = maxIndex;
	while(sequences[i]!= INT_MIN){
		maxSubSeq.insert(array[i]);
		i = sequences[i];
	}
	maxSubSeq.insert(array[i]);
  return {
      {sum[maxIndex]}, // Sum of sequence.
      {vector<int>(maxSubSeq.begin(),maxSubSeq.end())}  // Elements of the sequence.
  };
}

int main(){
    vector <int> arr;
    int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int in;
		cin>>in;
		arr.push_back(in);
	}
	vector <vector<int>> res = maxSumIncreasingSubsequence(arr);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j< res[0].size(); j++){
			cout<<res[i][j];
		}
		cout<<" ";
	}

}