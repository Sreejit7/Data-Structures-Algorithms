/**
 * Write a function that takes in an array 
 * and returns whether it is Monotonic or not.
 * An array is monotonic if it is only increasing or decreasing (not strictly)
 * from Left to Right.
 **/
#include<bits/stdc++.h>
using namespace std;

//Approach1: Traverse once
bool isMonotonic(vector<int> array) {
  if(array.size() <= 1)
		return true;
	int i = 0, n = array.size();
	bool increasing = false;
	while(i < n - 1 && array[i + 1] == array[i])
		i++;
	if(array[i + 1] > array[i])
		increasing = true;
	if(increasing == true){
		while(i < n - 1 && array[i + 1] >= array[i])
			i++;
	}
	else{
		while(i < n - 1 && array[i + 1] <= array[i])
			i++;
	}
	if(i == n - 1)
		return true;
	return false;
}

//Approach2: Using negation
bool isMonotonic2(vector<int> array) {
	if(array.size() <= 1)
		return true;
  bool increasing = true, decreasing = true;
	for(int i = 0; i < array.size() - 1; i ++){
		if(array[i + 1] > array[i])
			decreasing = false;
		else if(array[i + 1] < array[i])
			increasing = false;
	}
	
	return (increasing || decreasing);
}
int main(){
  int n;
  cin>>n;
  vector <int> array(n);
  for(int i = 0; i < n; i++)
    cin>> array[i];
  cout<<(isMonotonic2(array)? "Monotonic": "Not monotonic")<<endl;
}