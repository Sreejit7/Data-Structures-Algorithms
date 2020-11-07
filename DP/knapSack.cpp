/*
    We're given a knapsack with a particular capacity and an array of items with a value and a weight.
    We need to add items to the knapsack such that the total value of all the items in the knapsack is Maximum,
    while the total weight of items in the knapsack is not more than the knapsack capacity.
    We also need to return the index of items added into the knapsack.
*/

#include <bits/stdc++.h>
using namespace std;

//DP Approach: O(nc) time, O(nc) space
vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
    vector<vector<int>> maxValue(items.size()+1,vector<int>(capacity+1,0));
	for(int i = 1; i <= items.size(); i++){
		int currentWeight = items[i-1][1];
		int currentValue = items[i-1][0];
		for(int j = 0; j<= capacity; j++){
		  if(currentWeight <= j){
				maxValue[i][j] = max(maxValue[i-1][j - currentWeight] + currentValue,
									 maxValue[i-1][j]);
			}
			else
				maxValue[i][j] = maxValue[i-1][j];
		}
	}
	int i = items.size();
	int j = capacity;
	set <int> pickedItems;
	while(i > 0){
		if(maxValue[i-1][j] == maxValue[i][j])
			i--;
		else{
			pickedItems.insert(i-1);
			j-= items[i-1][1];
			i--;
		}
		if(j == 0)
			break;
	}
    return {
		{maxValue[items.size()][capacity]},
		vector<int>(pickedItems.begin(),pickedItems.end())
    };
}
int main(){
    int n,c;
    cin>>n>>c; //number of items provided , capacity of the knapsack
    vector<vector<int>> knapsack(n,vector<int>(2,0));
    for(int i = 0; i < n; i++){
        int v,w; //value and weight of each knapsack  item
        cin>>v>>w;
        knapsack[i][0] = v;
        knapsack[i][1] = w;
    }
    vector <vector<int>> res = knapsackProblem(knapsack,c); 
    cout<<"Maximum value in the knapsack:"<<res[0][0]<<"\n";
    cout<<"Items picked in the knapsack:"<<"\n";
    for(int i = 0; i< res[1].size(); i++)
        cout<<res[1][i]<<" ";
    cout<<endl;
}