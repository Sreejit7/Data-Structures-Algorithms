/*
  Given a Binary Search Tree (BST) with the root node root, 
  return the minimum difference between the values of any two different nodes in the tree. */

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//Approach: O(n) time & space, Inorder traversal
void build(TreeNode *node, vector <int> &arr){
        if(node == NULL){
            return;
        }
        else{
            build(node->left, arr);
            arr.push_back(node->val);
            build(node-> right, arr);
        }
}
int minDiffInBST(TreeNode* root) {
        vector<int> array = {};
        build(root, array);
        int minDiff = abs(array[1] - array[0]);
        for(int i = 1; i < array.size() - 1; i++){
            minDiff = min(abs(array[i + 1] - array[i]), minDiff);
        }
        return minDiff;
}

