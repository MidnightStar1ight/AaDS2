#ifndef AVLTREE_H
#define AVLTREE_H

#include "binarytree.h"

class AVLTree : public BinaryTree
{
protected:
    Node* root = nullptr;
    void createBypass(std::vector<type>& nums, Node* node);
    Node* createTree(std::vector<type>& nums, type left, type right);
    int setHeight(Node* root);
    int height(Node* node);

public:
    AVLTree();
    AVLTree(BinaryTree bt);
    Node* getAVLRoot();
    Node* insert(type num, Node*& node);
    Node* search(Node* node, type num);

    Node* findmin(Node* node);
    Node* removeMin(Node* node);

    Node* remove(Node* node, type num);
    Node* rotateRight(Node*& node);
    Node* rotateLeft(Node*& node);
    /*
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    int getBalance(Node *N);
    Node* realInsert(Node* node, type key);
    */
    Node* balance(Node*& node);
    void setRoot(Node *newRoot);
};

#endif // AVLTREE_H
