#include<bits/stdc++.h>
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

//Approach1: O(n) time by reversing the 2nd half of the LinkedList and then comparing from start and end
bool linkedListPalindrome(LinkedList *head) {
  int nodes = 0;
	LinkedList *node = head;
	while(node != NULL){
		nodes++;
		node = node->next;
	}
	if(nodes == 1)
		return true;
	int breaking = (nodes % 2 == 0)? (nodes / 2): (nodes / 2 + 1);
	int i = 0;
	node = head;
	while(i < breaking){
		i++;
		node = node->next;
	}
	LinkedList *prev = node;
	LinkedList *curr = node->next;
	while(curr != NULL){
		LinkedList *nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
	}
	LinkedList *tail = prev;
	i = 0;
	while(i < nodes / 2 && (head != NULL && tail != NULL)){
		if(head->value == tail->value){
			head = head->next;
			tail = tail->next;
			i++;
		}
		else
			return false;
	}
	return true;
}
//Approach2: Using stack, O(n) time & space
bool linkedListPalindrome2(LinkedList *head) {
  stack <int> nodes;
	LinkedList *node = head;
	while(node != NULL){
		nodes.push(node->value);
		node = node->next;
	}
	node = head;
	while(node != NULL && !nodes.empty()){
		if(nodes.top() == node->value){
			node = node->next;
			nodes.pop();
		}
		else
			return false;
	}
  return true;
}