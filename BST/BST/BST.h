#pragma once
#include "Node.h"
class BST
{
private:
	void transplant(Node*,Node*);
	void insertNode(Node*, int);
	void travel(Node*);
	Node* root;
	void findSuccessor(Node*, int);
	void findPredecessor(Node*, int);
	Node* searchNode(Node*, int);
	void deleteNode(Node*);
	Node* findMax(Node*);
	Node* findMin(Node*);
	void insertFixUp(Node*);
	void deleteFixUp(Node*);
	int heightofTree(Node*);
public:
	void HeightofTree();
	void leftRotate(Node*);
	void rightRotate(Node*);
	BST();
	Node* NIL;
	void ClearTree();
	Node* ReturnRoot();
	bool IsEmpty();
	void Travel();
	void Insert(int);
	void Delete(Node*);
	void Successor(int);
	void Predecessor(int);
	Node* Search(int);
	void Max();
	void Min();
};

