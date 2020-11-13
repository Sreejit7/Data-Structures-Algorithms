/**
 * Sherlock considers a string to be valid if all characters of the string appear the same number of times. 
 * It is also valid if he can remove just  character at  index in the string,
 *  and the remaining characters will occur the same number of times. 
 * Given a string , determine if it is valid. 
 * If so, return YES, otherwise return NO.
**/
//Approach: O(n*log(n)) time, O(n) space
#include<bits/stdc++.h>
using namespace std;
string isValid(string str) {
    if(str.length() <= 1)
        return "YES";
    vector <int> count(26,0);
    for(int i = 0; i < str.length(); i++){
        count[str[i] - 97] ++;
    }
    sort(count.begin(),count.end());
    int idx = upper_bound(count.begin(),count.end(),0) - count.begin() ;
    if(count[25] - count[24] <= 1 && count[24] == count[idx])
        return "YES";
    else if(count[idx] == 1 && count[25] == count[idx+1] )
        return "YES";
    return "NO";
}
int main(){
   string str;
   cin>> str;
   cout<<isValid(str)<<endl;    
}
