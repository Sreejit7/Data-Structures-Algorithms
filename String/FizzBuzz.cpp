/**
 * Write a program that outputs the string representation of numbers from 1 to n.
 * But for multiples of three it should output “Fizz” instead of the number and 
 * for the multiples of five output “Buzz”. 
 * For numbers which are multiples of both three and five output “FizzBuzz”.
 **/
#include<bits/stdc++.h>
using namespace std;

//Approach1: Naive if else statement O(n) time
vector<string> fizzBuzz(int n) {
  vector <string> res;
  for(int i = 1; i <= n; i++){
    if(i % 3 == 0 && i % 5 == 0)
        res.push_back("FizzBuzz");
    else if(i % 3 == 0)
        res.push_back("Fizz");
    else if(i % 5 == 0)
        res.push_back("Buzz");
    else
        res.push_back(to_string(i));
  }
  return res;
}

//Approach2: String concatenation O(n) time
vector<string> fizzBuzz2(int n) {
  vector <string> res(n, "");
  for(int i = 1; i <= n; i++){
    if(i % 3 == 0)
        res[i - 1] += "Fizz";
    if(i % 5 == 0)
        res[i - 1] += "Buzz";
    if(res[i - 1] == "")
        res[i - 1] += to_string(i);
  }
  return res;
}

//Approach3: Using Hashtable O(n) time, O(n*n) time in worst case
vector<string> fizzBuzz3(int n) {
  map <int, string> fizzbuzz;
  fizzbuzz.insert({3, "Fizz"});
  fizzbuzz.insert({5, "Buzz"});
  vector <string> res(n, "");
  for(int i = 1; i <= n; i++){
    for(auto x: fizzbuzz){
      if(i % x.first == 0)
        res[i] += x.second;
    }
    if(res[i] == "")
      res[i] = to_string(i);
  }
  return res;
}

int main(){
  int n;
  cin>>n;
  vector <string> res = fizzBuzz2(n);
  for(string s: res)
    cout<<s<<" ";
  cout<<endl;
}