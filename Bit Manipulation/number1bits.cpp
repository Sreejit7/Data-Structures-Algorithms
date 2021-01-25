/**
 * Write a function that takes an unsigned integer and 
 * returns the number of '1' bits it has (also known as the Hamming weight).
 **/

#include<bits/stdc++.h>
using namespace std;
//Approach1: O(32) time
int hammingWeight(uint32_t n) {
  uint32_t mask = 1; int count = 0;
  for(int i = 0; i < 32; i++){
      if((n & mask) != 0)
          count++;
      mask <<= 1;
  }
  return count;
}
//Approach2: O(n) time where n = number of 1 bits
int hammingWeight2(uint32_t n) {
  int count = 0;
  while(n != 0){
      count++;
      n &= (n - 1);
  }
  return count;
}
int main(){
  uint32_t n;
  cin>>n;
  cout<<"Number of 1bits in "<<n<<" is:"<<hammingWeight2(n)<<endl;
}