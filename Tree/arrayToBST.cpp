/**
 * Given an array where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more than 1.
 **/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//Binary Search method, O(n) time & O(log(n))space
static TreeNode* helper(vector<int> &nums, int low, int high){
  if(low > high)
      return NULL;
  int mid = low + (high - low)/2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = helper(nums, low, mid - 1);
  root->right = helper(nums, mid + 1, high);
  return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  return helper(nums, 0, nums.size() - 1);
}