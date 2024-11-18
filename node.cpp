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

Node::Node(type data, int height = 0) {
    this->data = data;
    this->height = height;
}

int Node::heightDiff()
{
    if (!this->left && !this->right) return 0;
    if (!this->left) return this->right->height;
    if (!this->right) return this->left->height;
    return std::abs(this->left->height - this->right->height);
}
