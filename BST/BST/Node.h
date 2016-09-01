#pragma once
#include "color.h"
class Node
{
public:
	int key;
	color c;
	Node *left;
	Node *right;
	Node *parent;
	Node(int value);
	Node();
	color getColor();
	void setColor(color);
};