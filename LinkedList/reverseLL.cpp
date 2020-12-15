/*
    Given the head of a singly Linked List, 
    reverse the Linked List in place (without extra space).
*/

#include<bits/stdc++.h>
using namespace std;
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};
//Approach: O(n) time 
LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList *prev = NULL;
	LinkedList *curr = head;
	while(curr != NULL){
		LinkedList *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
  return prev;
}
