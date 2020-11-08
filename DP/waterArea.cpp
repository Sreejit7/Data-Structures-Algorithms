/**
    We're given an array of non-negative integers 
    where each non-zero integer represents a pillar of width 1.
    Imagine water being poured over all pillars. 
    We need to write a function that returns the surface area of the water trapped between the pillars.
    Spilled water should be ignored.

**/

#include <bits/stdc++.h>
using namespace std;
//DP approach: O(n) time, O(n) space
int waterArea(vector<int> heights) {
	int n = heights.size(), area = 0;
  int maxLeft = 0, maxRight = 0;
	vector <int> maxes(heights.size(),0);
	for(int i = 0; i < n; i++){
		maxes[i] = maxLeft;
		maxLeft = max(maxLeft,heights[i]);
	}
	for(int i = n-1; i >= 0; i--){
		int minHeight = min(maxes[i],maxRight);
		if(heights[i] < minHeight)
			area += minHeight - heights[i];
		maxRight = max(maxRight,heights[i]);
	}
	return area;
}
//Approach 2: O(n) time, O(1) space
int waterArea2(vector<int> heights) {
  if(heights.size() <= 1)
		return 0;
	int left = 0, right = heights.size()-1, area = 0;
	int minHeight = min(heights[left],heights[right]);
	while(left < right){
		if(heights[left] <= minHeight){
				left++;
				if(heights[left] < minHeight)
					area += minHeight - heights[left];
				else
					minHeight = min(heights[left],heights[right]);
		}
		else{
			right--;
			if(heights[right] < minHeight)
					area += minHeight - heights[right];
				else
					minHeight = min(heights[left],heights[right]);
		}	
	}
	return area;
}
int main(){
    int n;
    cin>>n;
    vector <int> heights(n,0);
    for(int i = 0; i < n; i++){
        int in;
        cin>>in;
        heights[i] = in;
    }
    cout<<"Maximum water contained by the pillars: "<<waterArea2(heights)<<"unit\n";
}
