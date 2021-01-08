/**
 * Given a singly linked list, group all odd nodes together 
 * followed by the even nodes. 
 * Please note here we are talking about the node number and not the value in the nodes.
 **/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Approach: O(n) time 

ListNode* oddEvenList(ListNode* head) {
  if(head == NULL)
      return head;
  ListNode *odd = head;
  ListNode *evenHead = head->next, *even = head->next;
  int nodes = 1;
  while(even != NULL){
    odd->next = even->next;
    if(odd->next == NULL){
        break; 
    }
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;
}