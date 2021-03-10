/**
 * Problem Statement:
 * Given an array nums containing n distinct numbers in the range [0, n], 
 * return the only number in the range that is missing from the array.
 **/

#include<bits/stdc++.h>
using namespace std;

/*Approach 1: Count array
  This is a very simple approach, where we build a boolean count array,
  for keeping count of all the elements in the [0, n] range in the array.
  i) We traverse the whole array and for every element, we make count[elem] = true.
  ii) Finally, we traverse the count array and return where we find a false value. 
  
  Time complexity: O(n), Space complexity: O(n) where n = given input range
  */

int missingNumber(vector<int>& nums) {
  int n = nums.size();
  vector <bool> count(n + 1, false);
  for(int elem: nums){
    count[elem] = true;
  }
  for(int i = 0; i <= n; i++){
    if(count[i] == false)
      return i;
  }
  return n;
}

/*Approach 2: Sorting
  This is another simple enough approach where we -
  i) Sort the elements in ascending order. (You can do in descending order too).
        So now, ideally, the difference between two adjacent elements will be 1.
        Another thing to notice is that nums[i] will be i until we reach the gap point, 
        from where onwards nums[i] will be i + 1. 
  ii) Now we traverse the array and find out the index where this gap occurs i.e. nums[i] becomes i + 1 for the first time. 
  That is the number which is missing.
  If we don't find such an index in the array, then it must be n which is missing. 

  Time complexity: Sorting takes O(nlogn) time, and traversing takes O(n), so the overall Time Complexity: O(nlogn).
  Space complexity: O(1) as we didn't use any extra space.*/

int missingNumber2(vector<int>& nums) {
  int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
      if(nums[i] != i)
        return i;
    }
    return n;
}

/*Approach 3: Bit Manipulation
  This is a very cool approach, using the XOR property of Bit manipulation that A ^ A = 0 and 0 ^ A = A.
  Here, we have all the numbers in range[0, n] in indices [0, n - 1] with 1 missing number being replaced by n.
  So, if we XOR all array indices and their respective values, we'll find a pair for every value except the missing value.
  (As it's missing, we'll only have the index!) We'll initialize the missing number as n,
  so if every number between 0 to n - 1 exists in the array, we'll be left with n, and that's of course the missing number. 
  
  Time complexity: O(n).
  Space complexity: O(1)
  */

int missingNumber3(vector<int>& nums) {
  int n = nums.size();
  int missing = n;
  for(int i = 0; i < n; i++){
      missing ^= nums[i] ^ i;
  }
  return missing;
}

/*Approach 4: Mathematics, Gauss Formula
  We must not forget Maths while solving DSA problems! 
  Remember the formula for the sum of all natural numbers from 1 to n?
  It's n*(n + 1) / 2.  Using this, we can easily solve this problem. 
  We have the value of n, we have the array elements. 
  So we can just sum up the array elements and subtract that value from the sum of all numbers from [0, n],
  and we'll have the missing number with us. 

  Time complexity: O(n).
  Space complexity: O(1)
  */

int missingNumber4(vector<int>& nums) {
  int n = nums.size();
  int totalSum = (n * (n + 1)) / 2;
  int arraySum = 0;
  for(int i = 0; i < n; i++){
      arraySum += nums[i];
  }
  return totalSum - arraySum;
}

int main(){
  int n; //range of array
  cin>>n;
  vector <int> nums(n);
  for(int i = 0; i < n; i ++)
    cin>> nums[i];
  int missing = missingNumber3(nums);
  cout<<"Missing Number: "<<missing<<endl;
}