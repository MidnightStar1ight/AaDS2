#include "node.h"


Node::Node(type data, Node* parent = nullptr) {
    this->data = data;
    this->parent = parent;
}
