#include<bits/stdc++.h>
using namespace std;
/*
  Given an array of non-negative integers,
  produce an output array of the same length where
  every element in the output array is the
  product of every other element in the input array.

*/

//Approach1: Brute force, O(n*n) time, O(1) space
vector<int> arrayOfProducts(vector<int> array) {
  vector <int> products(array.size(), 1);
	for(int i = 0; i < array.size(); i++){
		for(int j = 0; j < array.size(); j++){
			if(i != j)
				products[i] *= array[j];
		}
	}
	
  return products;
}

//Approach2: Division, O(n) time & space
vector<int> arrayOfProducts2(vector<int> array) {
  vector <int> products(array.size(), 1);
	int product = 1, flag = 0;
	for(int i = 0; i < array.size(); i++){
		if(array[i] == 0 && flag == 0){
			flag = 1;
			continue;
		}
		product *= array[i];
	}
	for(int i = 0; i < array.size(); i++){
		if(array[i] == 0 && product != 0)
			products[i] = product;
		else if(product != 0 && flag == 0)
			products[i] = product/array[i];
		else
			products[i] = 0;
	}
  return products;
}

//Approach3: LeftProduct & RightProduct array, O(n) time & space
vector<int> arrayOfProducts3(vector<int> array) {
  vector <int> leftProducts(array.size(), 1);
	vector <int> rightProducts(array.size(), 1);
	int lP = 1, rP = 1;
	for(int i = 1; i < array.size(); i++){
		leftProducts[i] = lP * array[i - 1];
		lP = leftProducts[i];
	}
	for(int i = array.size() - 2; i >= 0; i--){
		rightProducts[i] = rP * array[i + 1];
		rP = rightProducts[i];
	}
	vector <int> products;
	for(int i = 0; i < array.size(); i++){
		products.push_back(leftProducts[i] * rightProducts[i]);
	}
  return products;
}

int main(){
  int n;
  cin>> n;
  vector <int> arr(n, 0);
  for(int i = 0; i < n; i++)
    cin>> arr[i];
  vector <int> res = arrayOfProducts3(arr);
  for(int elem: res)
    cout<<elem<<" ";
  cout<<endl;
}