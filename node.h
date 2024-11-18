#ifndef NODE_H
#define NODE_H

#include <type.h>

class Node
{
public:
    type data;
    int height;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Node();
    Node(type data);
    Node(type data, Node* parent);
    Node(type data, int height);
};

#endif // NODE_H
