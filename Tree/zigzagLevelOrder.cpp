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

//Recursive approach: O(d*n) time where d = depth, n = number of nodes at deepest level
void zigzagHelper(bool oddLevel, queue <TreeNode *> &nodes, vector <vector<int>> &zigzag){
  if(nodes.empty())
    return;
  TreeNode *temp;
  vector <int> levelNodes;
  for(int i = nodes.size(); i > 0; i --){				
        temp = nodes.front();
        nodes.pop();						
        if(oddLevel)
          levelNodes.push_back(temp->val);
        else
          levelNodes.insert(levelNodes.begin(), temp->val);
        if(temp->left != NULL)
          nodes.push(temp->left);
        if(temp->right != NULL)
          nodes.push(temp->right);
      }
    zigzag.push_back(levelNodes);
    zigzagHelper(!oddLevel, nodes, zigzag);
}
vector<vector<int>> zigzagLevelOrderRecursive(TreeNode* root) {
  if(root == NULL)
    return {};
  queue<TreeNode *> nodes;
  vector <vector<int>> zigzag;
  nodes.push(root);
  zigzagHelper(true, nodes, zigzag);
  return zigzag;

}

//Iterative approach: O(d*n) time where d = depth, n = number of nodes at deepest level
vector<vector<int>> zigzagLevelOrderIterative(TreeNode* root) {
  if(root == NULL)
    return {};
  queue<TreeNode *> nodes;
  TreeNode *temp;
  vector <vector<int>> zigzag;
  vector <int> levelNodes;
  nodes.push(root);
  int oddLevel = 1;							
  while(!nodes.empty()){						
      for(int i = nodes.size(); i > 0; i --){				
        temp = nodes.front();
        nodes.pop();						
        if(oddLevel)
          levelNodes.push_back(temp->val);
        else
          levelNodes.insert(levelNodes.begin(), temp->val);
        if(temp->left != NULL)
          nodes.push(temp->left);
        if(temp->right != NULL)
          nodes.push(temp->right);
      }
    zigzag.push_back(levelNodes);
    levelNodes.clear();
    oddLevel = !oddLevel;
  }
  return zigzag;

}