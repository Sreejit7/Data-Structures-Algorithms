/**
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Approach1: O(n) time
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode *temp, *head = l2;
  if(l1 == NULL && l2== NULL)
      return NULL;
  else if(l1 == NULL)
      return l2;
  else if(l2 == NULL)
      return l1;
  if(l1->val <= l2->val)
      head = l1;
  while(l1 != NULL && l2 != NULL){
      if(l1->val <= l2->val){
          temp = l1->next;
          if(temp == NULL || temp->val > l2->val)
              l1->next = l2;
          l1 = temp;
      }
      else{
          temp = l2->next;
          if(temp == NULL || temp->val >= l1->val)
              l2->next = l1;
          l2 = temp;
      }
  }
  return head;
}