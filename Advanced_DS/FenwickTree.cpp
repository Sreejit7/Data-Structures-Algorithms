#include<bits/stdc++.h>
#define p(k) (k & (-k))
using namespace std;
class FT{
  vector <int> ft;
  public:
  FT(int n, vector <int> arr){
    ft.resize(n + 1);
    for(int i = 1; i <= n; i++){
      update(i, arr[i - 1]);
    }
  }
  void update(int k, int x){
    while(k < ft.size()){
      ft[k] += x;
      k += p(k);
    }
  }
  int sum(int k){
    int s = 0;
    while(k >= 1){
      s += ft[k];
      k -= p(k);
    }
    return s;
  }
  void print(){
    for(int i = 1; i < ft.size(); i++)
      cout<< ft[i]<<" ";
    cout<<endl;
  }
};
int main(){
  vector <int> arr = {1, 3, 4, 8, 6, 1, 4, 2};
  FT ft(arr.size(), arr);
  ft.print();
}