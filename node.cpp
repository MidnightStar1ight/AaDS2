#include "node.h"

Node::Node() {}

Node::Node(type data)
{
    this->data = data;
    this->height = 1;
}

Node::Node(type data, Node* parent = nullptr) {
    this->data = data;
    this->parent = parent;
}

Node::Node(type data, int height = 0) {
    this->data = data;
    this->height = height;
}

int Node::heightDiff()
{
    if (!this->left && !this->right) return 0;
    if (!this->left) return this->right->height;
    if (!this->right) return -this->left->height;
    return this->right->height - this->left->height;
}

void Node::fixHeight()
{
    int hl, hr;
    if (!this->left)
        hl = 0;
    else
        hl = this->left->height;
    if (!this->right)
        hr = 0;
    else
        hr = this->right->height;
    this->height = (hl>hr ? hl : hr)+1;
}
