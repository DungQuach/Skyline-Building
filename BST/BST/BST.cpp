#include "BST.h"
#include "Node.h"
#include <iostream>
#include "color.h"

//public method
void BST::HeightofTree()
{
	if (IsEmpty())
		std::cout << "No tree init\n";
	else
	{
		std::cout <<"The height of tree is "<< heightofTree(root)<<std::endl;
	}
}
BST::BST()
{
	NIL = new Node();
	NIL->setColor(color::BLACK);
}
void BST::ClearTree()
{
	root = nullptr;
}
void BST::Insert(int value)
{
	if (root)
		insertNode(root, value);
	else
	{
		root = new Node(value);
		root->parent = NIL;
		root->left = NIL;
		root->right = NIL;
		root->setColor(color::BLACK);
	}
}
void BST::Travel()
{
	if (IsEmpty())
		std::cout << "No tree init";
	else
	{
		std::cout << "Tree: \n";
		travel(root);
	}
	std::cout << std::endl;
}
Node* BST::Search(int value)
{
	if (root)
		return searchNode(root, value);
	else
	{
		std::cout << "No tree init\n";
		return root;
	}
}
bool BST::IsEmpty()
{
	return (!root);
}
void BST::Delete(Node* ref)
{
	deleteNode(ref);
}
void BST::Successor(int value)
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized";
	else
		findSuccessor(root, value);
}
void BST::Predecessor(int value)
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized";
	else
		findPredecessor(root, value);
}
void BST::Max()
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized\n";
	else
		Node* result = findMax(root);
}
void BST::Min()
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized\n";
	else
		Node* result = findMin(root);
}
Node* BST::ReturnRoot()
{
	return root;
}

//private method
int BST::heightofTree(Node *current)
{
	if (current == NIL)
		return 0;
	else
	{
		int subtreeRight = heightofTree(current->right);
		int subtreeLeft = heightofTree(current->left);
		if(subtreeLeft > subtreeRight)
			return (1 + subtreeLeft);
		else
			return (1 + subtreeRight);
	}
}
void BST::travel(Node*root) //travel inorder -> return sorted order
{
	if (root == NIL)
		return;
	else
	{
		travel(root->left);
		if(root->getColor()==color::RED)
			std::cout << root->key << " Color: RED" <<std::endl;
		else
			std::cout << root->key << " Color: BLACK" << std::endl;
		travel(root->right);
	}
}
void BST::insertNode(Node* root, int value)
{
	Node *newNode = new Node(value);
	newNode->setColor(color::RED);
	newNode->right = NIL;
	newNode->left = NIL;
	if (value >= root->key)
	{
		if (root->right == NIL)
		{
			root->right = newNode;
			newNode->parent = root;
			insertFixUp(newNode);
		}
		else
			insertNode(root->right, value);
	}
	else
	{
		if (root->left == NIL)
		{
			root->left = newNode;
			newNode->parent = root;
			insertFixUp(newNode);
		}
		else
			insertNode(root->left, value);
	}
}
void BST::insertFixUp(Node* currentNode)
{
	while (currentNode->parent->getColor() == color::RED)
	{
		if (currentNode->parent == currentNode->parent->parent->left)
		{
			Node *uncle = currentNode->parent->parent->right;
			//Case 1: uncle is red
			if (uncle->getColor() == color::RED)
			{
				uncle->setColor(color::BLACK);
				currentNode->parent->setColor(color::BLACK);
				currentNode->parent->parent->setColor(color::RED);
				currentNode = currentNode->parent->parent;
			}
			else
			{
				//Case 2 : uncle is black and need-to-fix node is right child
				if (currentNode == currentNode->parent->right)
				{
					currentNode = currentNode->parent;
					leftRotate(currentNode);
				}
				//Case 3 : uncle is black and need-to-fix node is left child
				currentNode->parent->setColor(color::BLACK);
				currentNode->parent->parent->setColor(color::RED);
				rightRotate(currentNode->parent->parent);
			}
		}
		else
		{
			Node *uncle = currentNode->parent->parent->left;
			//Case 1: uncle is red
			if (uncle->getColor() == color::RED)
			{
				uncle->setColor(color::BLACK);
				currentNode->parent->setColor(color::BLACK);
				currentNode->parent->parent->setColor(color::RED);
				currentNode = currentNode->parent->parent;
			}
			else
			{
				//Case 2 : uncle is black and need-to-fix node is left child
				if (currentNode == currentNode->parent->left)
				{
					currentNode = currentNode->parent;
					rightRotate(currentNode);
				}
				//Case 3 : uncle is black and need-to-fix node is right child
				currentNode->parent->setColor(color::BLACK);
				currentNode->parent->parent->setColor(color::RED);
				leftRotate(currentNode->parent->parent);
			}
		}
		root->setColor(color::BLACK);
	}
}
void BST::findSuccessor(Node* root, int value)
{
	Node*current = searchNode(root, value);
	if (current == NIL)
		return;
	if (value == (findMax(root)->key))
	{
		std::cout << "This is the largest element" << std::endl;
		return;
	}
	else
	{
		if (current->right == NIL)
		{
			Node *temp = current->parent;
			if (temp == NIL)
				std::cout << "That is the only element" << std::endl;
			else
			{
				while (temp->parent != NIL && current != temp->left)
				{
					current = temp;
					temp = temp->parent;
				}
				std::cout << "Successor: " << temp->key << std::endl;
			}
		}
		else
		{
			Node* result = findMin(current->right);
			std::cout << "Successor: " << result->key << std::endl;
		}
	}
}
void BST::findPredecessor(Node* root, int value)
{
	Node*current = searchNode(root, value);
	if (current == NIL)
		return;
	if (value == (findMin(root)->key))
	{
		std::cout << "This is the smallest element" << std::endl;
		return;
	}
	else
	{
		if (current->left == NIL)
		{
			Node *temp = current->parent;
			if (!temp)
				std::cout << "That is the only element" << std::endl;
			else
			{
				while (temp->parent != NIL && current != temp->right)
				{
					current = temp;
					temp = temp->parent;
				}
				std::cout << "Predecessor: " << temp->key << std::endl;
			}
		}
		else
		{
			Node* result = findMax(current->left);
			std::cout << "Predecessor: " << result->key << std::endl;
		}
	}
}
Node* BST::searchNode(Node* root, int value)
{
	if (root == NIL)
	{
		std::cout << "No found matched\n";
		return root;
	}
	else
	{
		if (value == root->key)
		{
			std::cout << "Found it\n";
			return root;
		}
		else
		{
			if (value > root->key)
				searchNode(root->right, value);
			else
				searchNode(root->left, value);
		}
	}
}
void BST::deleteNode(Node* current)
{
	if ((current->left == NIL) || (current->right == NIL)) //deleted node has at most 1 non-leaf child
	{
		Node *child = current->right;
		if (child == NIL)
			child = current->left;
		if (current->getColor() == color::RED ) //current is red,child is black-> replace current with child
			transplant(current, child);
		else
		{
			if (child->getColor() == color::RED) //current is black,child is red-> replace current with child, recolor child with black
			{
				child->setColor(color::BLACK);
				transplant(current, child);
			}
			else
			{
				transplant(current, child); //current is black,child is black -> replace current with child and call fix up
				deleteFixUp(child);
			}
		}					
	}
	else //deleted node has 2 children
	{
		Node*pre = findMax(current->left);
		int temp = pre->key;
		pre->key = current->key;
		current->key = temp;
		deleteNode(pre);
	}
}

void BST::deleteFixUp(Node* current)
{
	//current is doubly black
	bool flag = true;
	while (flag)
	{
		if (current == root)
			flag = false;
		else
		{
			if (current->parent->left == current)
			{
				Node *sibling = current->parent->right;
				if (sibling->getColor() == color::BLACK) //sibling is black
				{
					if ((sibling->right->getColor() == color::BLACK) && (sibling->left->getColor() == color::BLACK)) //children of sibling are black
					{
						sibling->setColor(color::RED);
						current = current->parent;
					}
					else
					{
						if ((sibling->right->getColor() == color::BLACK) && (sibling->left->getColor() == color::RED)) //right child is black,left child is red
						{
							color temp = sibling->getColor();
							sibling->setColor(sibling->left->getColor());
							sibling->left->setColor(temp);
							rightRotate(sibling);
						}
						else//now right child of sibling is confirmed red
						{
							sibling->right->setColor(color::BLACK);
							color temp = current->parent->getColor();
							current->parent->setColor(sibling->getColor());
							sibling->setColor(temp);
							leftRotate(current->parent);
							flag = false;
						}
					}
				}
				else //sibling is red ->both children are black
				{
					color temp = current->parent->getColor();
					current->parent->setColor(sibling->getColor());
					sibling->setColor(temp);
					leftRotate(current->parent);
				}
			}
			else
			{
				Node *sibling = current->parent->left;
				if (sibling->getColor() == color::BLACK) //sibling is black
				{
					if ((sibling->right->getColor() == color::BLACK) && (sibling->left->getColor() == color::BLACK)) //children of sibling are black
					{
						sibling->setColor(color::RED);
						current = current->parent;
					}
					else
					{
						if ((sibling->left->getColor() == color::BLACK) && (sibling->right->getColor() == color::RED)) //left child is black,right child is red
						{
							color temp = sibling->getColor();
							sibling->setColor(sibling->right->getColor());
							sibling->right->setColor(temp);
							leftRotate(sibling);
						}
						else//now left child of sibling is confirmed red
						{
							sibling->left->setColor(color::BLACK);
							color temp = current->parent->getColor();
							current->parent->setColor(sibling->getColor());
							sibling->setColor(temp);
							rightRotate(current->parent);
							flag = false;
						}
					}
				}
				else //sibling is red ->both children are black
				{
					color temp = current->parent->getColor();
					current->parent->setColor(sibling->getColor());
					sibling->setColor(temp);
					rightRotate(current->parent);
				}
			}
		}
	}
}
Node* BST::findMax(Node* root)
{
	if (root->right != NIL)
		findMax(root->right);
	else
		return root;
}
Node* BST::findMin(Node* root)
{
	if (root->left != NIL)
		findMin(root->left);
	else
		return root;
}
void BST::leftRotate(Node* sample)
{
	Node *rightChild = sample->right;
	sample->right = rightChild->left;
	rightChild->left->parent = sample;
	if (sample == root)
		root = rightChild;
	else
	{
		if (sample->parent->left == sample)
			sample->parent->left = rightChild;
		else
			sample->parent->right = rightChild;
	}
	rightChild->parent = sample->parent;
	sample->parent = rightChild;
	rightChild->left = sample;
}
void BST::rightRotate(Node* sample)
{
	Node *leftChild = sample->left;
	sample->left = leftChild->right;
	leftChild->right->parent = sample;
	if (sample == root)
		root = leftChild;
	else
	{
		if (sample->parent->right == sample)
			sample->parent->right = leftChild;
		else
			sample->parent->left = leftChild;
	}
	leftChild->parent = sample->parent;
	sample->parent = leftChild;
	leftChild->right = sample;
}
void BST::transplant(Node* deletedNode,Node* replacedNode)
{
	if (deletedNode->parent == NIL)//deleted node is root
		root = replacedNode;
	else
	{
		if(deletedNode == deletedNode->parent->left)
			deletedNode->parent->left = replacedNode;
		else
			deletedNode->parent->right = replacedNode;
	}
	replacedNode->parent = deletedNode -> parent;
}