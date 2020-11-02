/*A robot is located at the top-left corner of a m x n grid

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?
*/
#include<bits/stdc++.h>
using namespace std;
 int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m,vector<int>(n,1));
        for(int i=1; i<m; i++){
            for(int j = 1; j<n; j++){
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n);
}
