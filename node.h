#ifndef NODE_H
#define NODE_H

#include <type.h>

class Node
{
public:
    type data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Node();
    Node(type data, Node* parent);
};

#endif // NODE_H
