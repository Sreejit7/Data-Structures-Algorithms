//Given a positive integer n, return the nth Fibonacci number.

#include<bits/stdc++.h>
using namespace std;
//Approach 1: O(2^n) time, O(n) space
int getNthFib(int n) {
  if(n <= 1)
		return 0;
	if(n == 2)
		return 1;
	else
		return getNthFib(n - 1) + getNthFib(n - 2);
}

//Approach2: Using DP , O(n) time & space
int getNthFib2(int n) {
  vector <int> fib(n, 0);
	fib[1] = 1;
	for(int i = 2; i < n; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
  return fib[n - 1];
}
//Approach3: O(n) time, O(1) space
int getNthFib3(int n) {
  int fibo[] = {0,1};
	int i = 2;
	while(i < n){
		int nextFib = fibo[0] + fibo[1];
		fibo[0] = fibo[1];
		fibo[1] = nextFib;
		i++;
	}
	if(n == 1)
		return fibo[0];
	return fibo[1];
}

int main(){
  int n;
  cin>>n;
  cout<<getNthFib3(n)<<endl;
}