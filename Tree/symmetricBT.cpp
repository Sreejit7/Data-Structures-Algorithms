/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 **/

#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


//Approach1: Iterative solution, O(n) time & space
bool isSymmetric(TreeNode* root) {
  if(root == NULL)
      return true;
    queue <TreeNode *> nodes;
    TreeNode *node1, *node2;
    nodes.push(root);
    nodes.push(root);
    while(!nodes.empty()){
      node1 = nodes.front();
      nodes.pop();
      node2 = nodes.front();
      nodes.pop();
      if(node1 == NULL && node2 == NULL)
        continue;
      else if(node1 == NULL || node2 == NULL)
        return false;
      if(node1->val == node2->val){
        nodes.push(node1->left);
        nodes.push(node2->right);
        nodes.push(node1->right);
        nodes.push(node2->left);
      }
      else
        return false;
    }
    return true;
}

//Approach2: Recursion, O(n) time & space
bool symmetricHelper(TreeNode *node1, TreeNode *node2){
    if (node1 == NULL && node2 == NULL)
      return true;
    else if(node1 == NULL || node2 == NULL)
      return false;
    if(node1->val == node2->val)
      return symmetricHelper(node1->left, node2->right) && symmetricHelper(node1->right, node2->left);

    return false;
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL)
      return true;
    return symmetricHelper(root->left, root->right);
}