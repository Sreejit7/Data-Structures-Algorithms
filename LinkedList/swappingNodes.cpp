#include<bits/stdc++.h>
using namespace std;
/**
 * Problem Statement: You are given the head of a linked list, and an integer k.
  Return the head of the linked list after swapping the values of the kth node from the beginning 
  and the kth node from the end (the list is 1-indexed). **/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/*Approach1: Storing nodes with indices in HashMap

  We can store all the LinkedList nodes along with their indices in a HashMap.  
  Time Complexity: O(n) where n = number of nodes 
  Space Complexity:O(n) where n = number of nodes  */

ListNode* swapNodes(ListNode* head, int k) {
  unordered_map <int, ListNode*> indices;
  ListNode *node = head;
  int idx = 1;
  while(node != NULL){
    indices[idx] = node;
    node = node->next;
    idx ++;
  }
  swap(indices[k]->val, indices[idx - k]->val);
  return head;
}

/*Approach: Using two node pointers. 

  We use two ListNode pointers start & end for pointing at the kth & (n - k)th node respectively.
  We keep traversing nodes and keep increasing the count of nodes, starting from 0.
  When count reaches k, we initialize front = that node. We also initialize end = head. 
  If we keep making end = end->next at each stage, when the node traversal hits NULL, (end of the list)
  end will be pointing to the kth node from the end!
  Thus, we can pick both kth and (n - k)th nodes in ONE SINGLE TRAVERSAL.
  Now we just have to swap their values.

  Time Complexity: O(n) where n = number of nodes 
  Space Complexity: O(1)
*/

ListNode* swapNodes2(ListNode* head, int k) {
  ListNode *node = head;
  ListNode *start = NULL, *end = NULL;
  int nodeCount = 0;
  while(node != NULL){
    nodeCount ++;
    if(end != NULL)
      end = end->next;
    if(nodeCount == k){
      start = node;
      end = head;
    }
    node = node->next;
  }
  swap(start->val, end->val);
  return head;
}