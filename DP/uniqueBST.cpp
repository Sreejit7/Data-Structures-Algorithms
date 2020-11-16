/*

    Given an integer n, generate number of structurally unique BST's (binary search trees) that store values 1 ... n.

*/
#include<bits/stdc++.h>
using namespace std;

//Approach: O(n) time, O(1) space using Catalan Number
long binomial(int n,int r){
        if(r > n-r)
            r = n-r;
        long res = 1;
        for(int i = 0; i < r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }   
    int numTrees(int n) {
        long res =  binomial(2*n,n);
        return res/(n+1);
}
//Follow up: Generate all possible structurally unique BSTs from 1 ... n.
//Approach: O(n^2) time, O(n) space
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<TreeNode *> trees(int start, int end){
        vector <TreeNode *> result;
        if(start > end)
            result.push_back(0);
        else if(start == end){
            TreeNode *node = new TreeNode(start);
            result.push_back(node);
        }
        else{
            for(int i = start; i<= end; i++){
                vector <TreeNode *> left = trees(start,i-1);
                vector <TreeNode *> right = trees(i+1,end);
                int j,k;
                for(j = 0; j < left.size(); j++){
                    for(k = 0; k < right.size(); k++){
                        TreeNode *node = new TreeNode(i);
                        node->left  = left[j];
                        node->right = right[k];
                        result.push_back(node);
                    }
                }
            }
        }
        return result;
}
vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return trees(1,n);      
}