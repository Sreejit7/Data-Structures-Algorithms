/*
    Given an array of non-empty integers, 
    where each integer represents the max. number of steps we can take in forward direction.
    Determine the min. no of jumps needed to reach the end of the array.
*/

#include<bits/stdc++.h>
using namespace std;
//Approach 1: O(n^2) time, O(n) space [DP approach]
int minNumberOfJumps(vector<int> array) {
  vector<int>jumps(array.size(),INT_MAX);
	jumps[0] = 0;
	for(int i = 0; i< array.size(); i++){
		int x = array[i];
		if(i+x >= array.size())
			x = array.size()-i-1;
		for(int j = i+1; j<= i+x ; j++){
			jumps[j] = min(jumps[j],jumps[i]+1);
		}
	}
  return jumps[array.size() - 1];
}
//Approach 2: O(n) time, O(1) space
int minNumberOfJumps2(vector<int> array) {
	if(array.size() == 1)
		return 0;
	int jumps = 0, maxReach = array[0], steps = array[0];
	int i = 1;
	while(i < array.size()-1){
		maxReach = max(maxReach, i + array[i]);
		steps--;
		if(steps == 0){
			steps = maxReach - i;
			jumps++;
		}
		i++;
	}
	return jumps+1;
 
}
int main(){
    int n;
    cin>>n;
    vector<int> array(n,0);
    for(int i = 0; i< n ; i++){
        int in;
        cin>>in;
        array[i] = in;
    }
    cout<<minNumberOfJumps2(array);
}