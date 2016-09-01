#include "Node.h"
#include <iostream>


Node::Node()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

Node::Node(int value)
{
	key = value;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}
color Node::getColor()
{
	return c;
}
void Node::setColor(color val)
{
	c = val;
}


