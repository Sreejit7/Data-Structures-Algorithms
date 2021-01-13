#include<bits/stdc++.h>
using namespace std;
class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

//Approach: O(max(d1, d2)) time, O(1) space
int getDepth(AncestralTree *node, AncestralTree *topAncestor){
	int depth = 0;
	while(node != topAncestor){
		node = node->ancestor;
		depth++;
	}
	return depth;
}
AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
 int 	depth1 = getDepth(descendantOne, topAncestor),
			depth2 = getDepth(descendantTwo, topAncestor);
	int maxDepth = max(depth1, depth2), minDepth = min(depth1, depth2);
	AncestralTree *deeper = (maxDepth == depth1)? descendantOne: descendantTwo;
	AncestralTree *higher = (maxDepth == depth1)? descendantTwo: descendantOne;
	while(maxDepth != minDepth){
		deeper = deeper->ancestor;
		maxDepth--;
	}
	while(deeper != higher){
		deeper = deeper->ancestor;
		higher = higher->ancestor;
	}
	return deeper;
}

//Approach: O(d) time, O(d) space
AncestralTree *getYoungestCommonAncestor2(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
  unordered_set <AncestralTree *> ancestors;
	while(descendantOne!= topAncestor){
		ancestors.insert(descendantOne->ancestor);
		descendantOne = descendantOne->ancestor;
	}
	while(descendantTwo!= topAncestor){
		if(ancestors.find(descendantTwo) != ancestors.end()){
				return descendantTwo;
		}
		descendantTwo = descendantTwo->ancestor;
	}
  return topAncestor;
}
