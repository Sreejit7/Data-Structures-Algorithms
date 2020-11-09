/**
 *  
 *  We have an array for which the ith element is the price of a given stock on day i.
    If we were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), 
    we have to design an algorithm to find the maximum profit.
    Note that we cannot sell a stock before we buy one.
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices){
    //Approach1: O(n^2) time, O(n^2) space
        int n = prices.size(),maxProfit = 0;
    /*  vector<vector<int>> profit(n,vector<int>(n,0));
        for(int i=0; i<n-1; i++){
            for(int j = i+1; j < n; j++){
                int profit = prices[j] - prices[i];
                if(profit > maxProfit)
                    maxProfit = profit;
            }
        }
    */
    //Approach2: O(n) time, O(1) space         
        if(n <=1)
            return 0;
        int minPrice = prices[0],minIdx = 0,maxIdx = 1;
        for(int i = 1; i< n; i++){            
            maxProfit = max(prices[i] - minPrice,maxProfit);
            if(prices[i] - minPrice == maxProfit){
                maxIdx = i;
            }
            if(prices[i] < minPrice){
                minPrice = prices[i];
                minIdx = i;
            }
        }
        cout<<"Buy on: Day "<<minIdx<<"\n";
        cout<<"Sell on: Day "<<maxIdx<<"\n";
        cout<<"Maximum profit: ";
        return maxProfit;
}
int main(){
    int n;
    cin>>n;
    vector<int> prices(n,0);
    for(int i = 0; i < n; i++){
        int in;
        cin>>in;
        prices[i] = in;
    }
    cout<<maxProfit(prices)<<"\n";
}