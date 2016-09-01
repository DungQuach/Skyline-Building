#pragma once
#include "Node.h"
#include <vector>
class BST
{
private:
	void sweep(Node*, bool);
	Node *searchInterval(Node*,int,int);
	bool isOverlap(Node*, int,int);
	void transplant(Node*,Node*);
	void insertNode(Node*, int,int);
	void travel(Node*);
	Node* root;
	Node* findSuccessor(Node*, int);
	void findPredecessor(Node*, int);
	Node* searchNode(Node*, int);
	void deleteNode(Node*);
	Node* findMax(Node*);
	Node* findMin(Node*);
	void insertFixUp(Node*);
	void deleteFixUp(Node*);
	int heightofTree(Node*);
public:
	std::vector<int> criticalPoints;
	void HeightofTree();
	void leftRotate(Node*);
	void rightRotate(Node*);
	BST();
	void Sweep();
	Node* NIL;
	void ClearTree();
	Node* ReturnRoot();
	bool IsEmpty();
	void Travel();
	void Insert(int,int);
	void Delete(Node*);
	void Successor(int);
	void Predecessor(int);
	Node* Search(int);
	void SearchInterval( int, int);
	
	void Max();
	void Min();
};

