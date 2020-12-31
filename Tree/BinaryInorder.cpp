/**
 * Given the root of a binary tree, 
 * return the inorder traversal of its nodes' values.
 **/
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

//Recursive Solution O(n) time & space (worst case)
vector<int> inorderTraversal(TreeNode* root) {
  if(root == NULL)
      return {};
  vector <int> leftSub = inorderTraversal(root->left);
  vector <int> rightSub = inorderTraversal(root->right);
  vector <int> inOrder;
  inOrder.insert(inOrder.end(), leftSub.begin(), leftSub.end());
  inOrder.insert(inOrder.end(), root->val);
  inOrder.insert(inOrder.end(), rightSub.begin(), rightSub.end());
  
  return inOrder;
}

//Iterative method using Stack, O(n) time & space
vector<int> inorderTraversal2(TreeNode* root) {
  stack <TreeNode *> nodes;
  vector <int> inOrder;
  TreeNode *curr = root;
  while(curr != NULL|| !nodes.empty()){
      while(curr != NULL){
          nodes.push(curr);
          curr = curr->left;
      }
      curr = nodes.top();
      inOrder.push_back(curr->val);
      nodes.pop();
      curr = curr->right;
  }
  return inOrder;
}

//Morris Traversal: Without extra space, O(n) time
vector<int> inorderTraversal3(TreeNode* root) {
  stack <TreeNode *> nodes;
  vector <int> inOrder = {};
  TreeNode *curr = root;
  TreeNode *temp1, *temp2;
  while(curr != NULL){
      if(curr->left != NULL){
          temp1 = temp2 = curr->left;
          while(temp1->right != NULL)
              temp1 = temp1->right;
          temp1->right = curr;
          curr->left = NULL;
          curr = temp2;
      }
      else{
          inOrder.push_back(curr->val);
          curr = curr->right;
      }
  }
  return inOrder;
}
