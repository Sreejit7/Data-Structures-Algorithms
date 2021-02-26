/**
 * Problem:
 * You are given a perfect binary tree where all leaves are on the same level, 
 * and every parent has two children. 
 * The binary tree has the following definition:
    struct Node {
      int val;
      Node *left;
      Node *right;
      Node *next;
    }
  Populate each next pointer to point to its next right node. 
  If there is no next right node, the next pointer should be set to NULL.
  Initially, all next pointers are set to NULL.
 **/

/** The visual representation of the problem would look like this:-
 *                  
 *                          1 --> NULL
 *                        /   \
  *                     2 ---> 3 --> NULL
  *                   /  \   /  \
 *                  4 -> 5->6 -> 7 -> NULL
 * 
 * So as you can see, the node appearing next to the right in this representation has to be denoted as the next node,
 * and the next node of the right-most node at every level would be NULL.
 * Let's get started with the approach and the code.
 **/

#include<bits/stdc++.h>
using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

/** Approach 1: Level order Traversal 
  As we can see, the node which appears rightnext to a node on the SAME LEVEL of the Binary Tree is the next pointer.
  So, we can do a Level-by-level traversal of the tree and at every level, until we reach the last node of the level.
  For the last node, the next pointer would naturally be NULL. 
  For storing the values of all the nodes of a particular level at a time, we can use a queue.  
**/

Node* connect(Node* root) {
  if(root == NULL || root->left == NULL) // if the root is NULL or a single node, we can return it directly.
    return root;
    queue<Node *> nodes;
    Node *node = root;
    Node *temp = node;
    nodes.push(node);
    while(!nodes.empty()){
      int size = nodes.size();
      node = nodes.front();
      nodes.pop();
      size--;
      while(size > 0){   //while loop for traversing through a level. We keep dequeing nodes and enqueing their children nodes.
        node->next = nodes.front();
        if(node->left != NULL){
          nodes.push(node->left), nodes.push(node->right);
        }
        node = node->next;
        nodes.pop(); 
        size --;
      }
      node->next = NULL; //when we reach the end of a level, next is NULL
      if(node->left != NULL)
        nodes.push(node->left), nodes.push(node->right);
    }
  return temp;
}

// Time complexity: O(N) where N = Number of nodes in the Binary Tree, as we traverse through all the nodes once.
// Space complexity: O(2^D) where D = maximum depth of the Binary Tree. (the queue will have max size at the deepest level)

/** Approach 2: Recursion.
 * Recursion is a widely used technique for solving Tree related problems. 
 * If we are doing similar operation on each node of the tree, we can use recursion. 
 * In this case, the similar operation is assigning a next node to each node. 
 * There's a pattern in which we assign a next node for each node, particularly for all the left children and all the right children.
 * For every Left child, the next node is always the Right child of the same Parent. 
 * For every Right child, it's either the Left Child of the Parent's next node, or NULL if the Parent's next node is NULL.
 * 
 * We can build our recursive function based on these two conditions, keeping track of the child & parent nodes 
 * and whether the child node is a Left Child or a Right Child. Let's build our recursive function ->
 **/

void rightPointerHelper(Node* node, Node* parent, bool isLC){
    if(node == NULL)
      return;
    if(isLC){
      node->next = parent->right;
    }
    else{
      if(parent->next != NULL)
        node->next = parent->next->left;
    }
    rightPointerHelper(node->left, node, true);  //for left child, isLC = true
    rightPointerHelper(node->right, node, false); //for right child, isLC = false
}

// Main function
Node* connect(Node* root) {
  if(root == NULL || root->left == NULL)
    return root;
  rightPointerHelper(root->left, root, true); //Calling the recursive function on both sides of the root
  rightPointerHelper(root->right, root, false);
  return root;
}

// Time complexity: O(N) where N = Number of nodes in the Binary Tree, as we traverse through all the nodes once.
// Space complexity: O(log(N)) where N = Number of nodes in the Binary Tree & log(N) is the depth of the tree, as it's the average size of the recursion call stack.
