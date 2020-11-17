/*
    Two strings are anagrams of each other if the letters of one string 
    can be rearranged to form the other string. 
    Given a string, find the number of pairs of substrings of the string that are anagrams of each other.
*/

#include <bits/stdc++.h>
using namespace std;
//Approach: O(n^2) time, O(n) space
int anagramPairFinder(string s) {
    int n = s.length(), count = 0;
    unordered_map <string,int> anagrams;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n - i; j++){
            string current = s.substr(i,j);
            sort(current.begin(),current.end());
            if(anagrams.find(current) == anagrams.end())
                anagrams.insert({current,1});
            else{
                count += anagrams[current];
                anagrams[current] ++;
            }
        }
    }
    return count;
}
int main(){
    string s;
    cin>>s;
    cout<<anagramPairFinder(s)<<endl;
}
