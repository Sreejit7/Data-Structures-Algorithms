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
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> paths(m,vector<int>(n,1));
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(obstacleGrid[i][j]==1)
                    paths[i][j] = 0;
                else{
                    if(i == 0 && j == 0)
                        paths[i][j] = 1;
                    else if(i == 0)
                        paths[i][j] = paths[i][j-1];
                    else if(j == 0)
                        paths[i][j] = paths[i-1][j];
                    else
                        paths[i][j] = paths[i-1][j] + paths[i][j-1];
                }
            }
        }
        return paths[m-1][n-1];
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> obstacles;
    for(int i = 0; i< m; i++){
        vector<int> in(n,0);
        for(int j=0; j < n; j++){
            int input;
            cin>>input;
            in[j] = input;
        }
        obstacles.push_back(in);
    }
    cout<<"Paths without obstacles:"<<uniquePaths(m,n)<<"\n";
    cout<<"Paths with obstacles:"<<uniquePathsWithObstacles(obstacles)<<"\n";
}
