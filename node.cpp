#include "node.h"

Node::Node() {}

Node::Node(type data)
{
    this->data = data;
}

Node::Node(type data, Node* parent = nullptr) {
    this->data = data;
    this->parent = parent;
}

Node::Node(type data, int height = 1) {
    this->data = data;
    this->height;
}
