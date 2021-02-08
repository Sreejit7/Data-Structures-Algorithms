/**
 * Write a function that takes in an Integer Array and
 * returns the largest range present in the array where
 * the difference between continuous elements in a range is less than or equal to 1. 
 * The range should be outputted as a 2 number vector,
 * where the first number is minimum & second number is maximum in the range.
 **/

#include<bits/stdc++.h>
using namespace std;

//Approach1: Sorting & linear scan, O(n*log(n)) time
vector<int> largestRange(vector<int> array) {
  vector <int> maxRange = {array[0], array[0]};
	int starting = 0, ending = 0;
	sort(array.begin(), array.end());
	int i = 1;
	while(i < array.size()){
		if(array[i] <= array[ending] + 1){
			ending++;
			i++;
		}
		else{
			if(maxRange[1] - maxRange[0] < ending - starting){
				maxRange[0] = array[starting];
				maxRange[1] = array[ending];
			}
			starting = ending + 1;
			ending++;
			i = ending + 1;
		}
	}
	if(maxRange[1] - maxRange[0] < ending - starting){
			maxRange[0] = array[starting];
			maxRange[1] = array[ending];
	}
  return maxRange;
}

//Approach2: Hash table & linear expansion, O(n) time & space
vector<int> largestRange2(vector<int> array) {
	int largest, smallest, range = 0;
	vector <int> maxRange = {array[0], array[0]};
	unordered_map<int, bool> nums;
	for(int num: array){
		nums[num] = false;
	}
	for(int num: array){
		if(nums[num])
			continue;
		nums[num] = true;
		largest = num;
		smallest = num;
		while(nums.find(largest + 1) != nums.end()){
			nums[largest + 1] = true;
			largest ++;
			range++;
		}
		while(nums.find(smallest - 1) != nums.end()){
			nums[smallest - 1] = true;
			smallest --;
			range++;
		}
		if(range > maxRange[1] - maxRange[0])
			maxRange[0] = smallest, maxRange[1] = largest;
		range = 0;
	}
	return maxRange;
}

int main(){
  int n;
  cin>>n;
  vector<int> nums;
  for(int i = 0; i < n; i++){
    cin>> nums[i];
  }
  vector <int> res = largestRange2(nums);
  cout<<res[0]<<" "<<res[1]<<endl;
}