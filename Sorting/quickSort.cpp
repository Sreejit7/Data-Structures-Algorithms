/*
    Implementation of Quick Sort Algorithm
    for sorting an input array.

    Time complexity: O(nlog(n)) time (avg case), O(n*n) time (worst case).
*/

#include<bits/stdc++.h>
using namespace std;
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
void quickSort(vector <int> &arr, int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
int main(){
  int n;
  cin>>n;
  vector <int> arr(n, 0);
  for(int i = 0; i < n; i++)
    cin>>arr[i];
  quickSort(arr, 0, n - 1);
  cout<<"Sorted Array:"<<"\n";
  for(int i = 0; i < n; i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
}
