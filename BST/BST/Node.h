#pragma once
#include "color.h"
class Node
{
public:
	int key; //low of the interval
	color c;
	Node *left;
	Node *right;
	Node *parent;
	Node(int,int);
	Node();
	color getColor();
	void setColor(color);
	int max; // max of the interval in the subtree rooted this node
	int high; //high of the interval
};