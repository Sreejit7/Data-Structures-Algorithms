/*
    Given a list of non-negative integers representing the amount of money of each house, 
    determine the maximum amount of money you can rob tonight without alerting the police
    (Police will be alerted if two adjacent houses are broken into at the same night)
*/
//DP approach: O(n) T, O(n) Space
#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
        vector<int> amount(nums.begin(),nums.end());
        if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]);
        if(nums[0]>nums[1])
            amount[1] = nums[0];
        for(int i = 2; i < nums.size(); i++){
            amount[i] = max(amount[i-1],amount[i-2]+nums[i]);
        }
        return amount.back();
}

//Follow-up: Houses are arranged in circular order(First and last houses are adjacent)

int robAdv(vector <int> &nums){
        int n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];
        else if(n == 2)
            return max(nums[0],nums[1]);
        vector <int> nums2(nums.begin()+1,nums.end());
        vector <int> nums1(nums.begin(),nums.end()-1);
        vector<int>maxSum(n-1,0);
        maxSum[0] = nums1[0];
        maxSum[1] = max(nums1[0],nums1[1]);
        
        vector<int>maxSum2(n-1,0);
        maxSum2[0] = nums2[0];
        maxSum2[1] = max(nums2[0],nums2[1]);
        for(int i = 2; i< n-1; i++){
            maxSum[i] = max(maxSum[i-1],maxSum[i-2]+nums1[i]);
            maxSum2[i] = max(maxSum2[i-1],maxSum2[i-2]+nums2[i]);
        }
       return max(maxSum[n-2],maxSum2[n-2]);

}
int main(){
    vector <int> nums;
    int n;
    cin>>n;
    for(int i = 0; i< n; i++){
        int in;
        cin>>in;
        nums.push_back(in);
    }
    cout<<"When houses are arranged in linear order:"<<rob(nums)<<"\n";
    cout<<"When houses are arranged in circular order:"<<robAdv(nums)<<"\n";
}