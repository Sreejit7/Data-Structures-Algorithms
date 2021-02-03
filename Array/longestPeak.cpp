/**
 * Write a function to calculate the length
 * of the longest peak in the array. 
 * A peak is a subarray where the values are first strictly increasing
 * until reaching a highest point and then strictly decreasing.
 **/

#include<bits/stdc++.h>
using namespace std;

//Approach1: O(n) time
int longestPeak(vector<int> array) {
	if(array.size() < 3)
		return 0;
  int breakPoint = 0,peakLength = 1, maxLength = 0;
	bool increasing = true, decreasing = false;
	int i = 0;
	while(i < array.size() - 1){
		if(increasing){
			if(array[i + 1] > array[i]){
				i++;
				peakLength++;
			}
			else if(array[i + 1] == array[i]){
				peakLength = 1;
				i ++;
			}
			else{
				if(peakLength > 1){
					decreasing = true;
					increasing = false;
					peakLength ++;
				}
				i++;
			}
		}
		else{
			if(array[i + 1] < array[i]){
				i++;
				peakLength++;
			}
			else{
				maxLength = max(peakLength, maxLength);
				increasing = true;
				decreasing = false;
				peakLength = 1;
				if(array[i + 1] == array[i])
					i ++;
			}
		}
	}
	
	if(i == array.size() - 1 && decreasing)
		return max(maxLength, peakLength);
	return maxLength;
}

//Approach2: Expanding both ways from a peak, O(n) time
bool isPeak(vector <int> &arr, int i){
	return (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]);	
}
int longestPeak2(vector<int> array) {
	if(array.size() < 3)
		return 0;
  int i = 1, leftIndex, rightIndex, maxLength = 0;
	while(i < array.size() - 1){
		if(!isPeak(array, i)){
			i++;
			continue;
		}
		leftIndex = i - 2;
		rightIndex = i + 2;
		while(leftIndex >= 0 && array[leftIndex + 1] > array[leftIndex])
			leftIndex --;
		while(rightIndex <= array.size() - 1 && array[rightIndex - 1] > array[rightIndex])
			rightIndex ++;
		maxLength = max(maxLength, rightIndex - leftIndex - 1);
		i = rightIndex;
	}
	return maxLength;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin>> arr[i];
  }
  cout<<longestPeak2(arr)<<endl;
}