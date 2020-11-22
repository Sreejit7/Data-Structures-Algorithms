//Given a Roman expression, convert it to its equivalent Integer.

#include<bits/stdc++.h>
using namespace std;

//Approach: O(n) time, O(1) space
int romanToInt(string s) {
  int res = 0;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
              case 'I':
                res += 1;
                break;
              case 'V':
                res += 5;
                break;
              case 'X':
                res += 10;
                break;
              case 'L':
                res += 50;
                break;
              case 'C':
                res += 100;
                break;
              case 'D':
                res += 500;
                break;
              case 'M':
                res += 1000;
                break;
            }
            if(i > 0){
              if((s[i] == 'V' || s[i] == 'X') && s[i-1] == 'I')
                res -= 2;
              else if((s[i] == 'L' || s[i] == 'C') && s[i-1] == 'X')
                res -= 20;
              else if((s[i] == 'D' || s[i] == 'M') && s[i-1] == 'C')
                res -= 200;
            }
        }
  return res;
}
int main(){
  string Roman;
  cin>>Roman;
  cout<<romanToInt(Roman)<<endl;
}