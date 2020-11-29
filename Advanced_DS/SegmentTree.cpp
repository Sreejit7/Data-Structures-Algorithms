#include<bits/stdc++.h>
#define lc(x) ((2*x) + 1)
#define rc(x) ((2*x) + 2)
using namespace std;
int middle(int a, int b){
    return (a + b)/ 2;
}
class ST{
  vector<int> st;
  public:
  ST(vector <int> arr, int n){
    st.resize(5*n);
    build(arr, 0, 0, n - 1);
  }
  int combine(int a, int b){
    
  }
  void build(vector <int> &arr, int x, int l, int r){
    if(l == r){
      st[x] = arr[l];
    }
    else{
      int mid = middle(l, r);
      build(arr, lc(x), l, mid);
      build(arr, rc(x), mid + 1, r);
      st[x] = combine(st[lc(x)], st[rc(x)]);
    }
  }
  void update(int pos, int val, int x, int l, int r){
    if(pos < l || pos > r)
      return;
    st[x] = val;
    if(l != r){
      int mid = middle(l, r);
      update(pos, val, lc(x), l, mid);
      update(pos, val, rc(x), mid + 1, r);
    }
  }
  int query(int x, int l, int r, int L, int R){
    if(L > r || R < l)
      return 0;
    if(L <= l && R >= r){
      return st[x];
    }
    int mid = middle(l, r);
    return combine(query(lc(x), l, mid, L, R), query(rc(x), mid + 1, r, L, R));
  }
};
int main(){
  int n, Q;
  cin>> n;
  vector<int> arr(n, 0);
  for(int i = 0; i < n; i++){
    int in;
    cin>>in;
    arr[i] = in;
  }
  ST st(arr,n);
  cin>>Q;
}