/**
 * Write a function that takes in an integer array and 
 * returns the Kth smallest element.
 **/

#include<bits/stdc++.h>
using namespace std;

//Quickselect approach; O(n*logn) time , O(n) time on average
int partition(vector <int> &arr, int low, int high){
  int i = low - 1, pivot = arr[high];
  if(low < high){
    for(int j = low; j < high; j++){
      if(arr[j] < pivot){
        i++;
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[i + 1], arr[high]);
  }
  return i + 1;
}
int quickselect(vector<int> array, int k) {
  int position = k - 1;
	int low = 0, high = array.size() - 1;
	int pi = partition(array, low, high);
	while(pi != k - 1){
		if(pi > k - 1){
			pi = partition(array, low, pi - 1);
		}
		else{
			pi = partition(array, pi + 1, high);
		}
	}
  return array[pi];
}
int main(){
  int n, k;
  cin>>n>>k;
  vector <int> arr(n, 0);
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
  cout<<quickselect(arr, k)<<endl;
}