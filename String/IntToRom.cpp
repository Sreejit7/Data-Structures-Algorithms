//Given an Integer value, convert it to its equivalent Roman expression.

#include<bits/stdc++.h>
using namespace std;

//Approach: O(n) time, O(1) space
string intToRoman(int num) {
  string res = "";
    int i = 0, v = 0, x = 0, l = 0, c = 0, d = 0, m = 0;
    m = num/1000;
    for(int k = 1; k <= m; k++)
      res += 'M';
    num %= 1000;
    if(num >= 900){
      res += "CM";
      num += 100;
      num %= 1000;
    }
    
    d = num/500;
    for(int k = 1; k <= d; k++)
      res += 'D';
    num %= 500;
    if(num >= 400){
      res += "CD";
      num += 100;
      num %= 500;
    }
    c = num/100;
    for(int k = 1; k <= c; k++)
      res += 'C';
    num %= 100;
    if(num >= 90){
      res += "XC";
      num += 10;
      num %= 100;
    }
    l = num/50;
    for(int k = 1; k <= l; k++)
      res += 'L';
    num %= 50;
    if(num >= 40){
      res += "XL";
      num += 10;
      num %= 50;
    }
    x = num/10;
    for(int k = 1; k <= x; k++)
      res += 'X';
    num %= 10;
    if(num == 9){
      res += "IX";
      num += 1;
      num %= 10;
    }
    v = num/5;
    for(int k = 1; k <= v; k++)
      res += 'V';
    num %= 5;
    if(num == 4){
      res += "IV";
      num += 1;
      num %= 5;
    }
    i = num;
    for(int k = 1; k <= i; k++)
      res += 'I';
  return res;
}
int main(){
  int num;
  cin>>num;
  cout<<intToRoman(num)<<endl;
}