#include "Node.h"
#include <iostream>


Node::Node()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	max = -1;
}

Node::Node(int value,int ceil)
{
	key = value;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	high = ceil;
}
color Node::getColor()
{
	return c;
}
void Node::setColor(color val)
{
	c = val;
}


