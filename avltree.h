#ifndef AVLTREE_H
#define AVLTREE_H

#include "binarytree.h"

class AVLTree : public BinaryTree
{
protected:
    Node* root = nullptr;
    void createBypass(std::vector<type>& nums, Node* node);
    Node* createTree(std::vector<type>& nums, type left, type right); // Создание дерева из вектора подходом "сверху вниз"
    int setHeight(Node* root);
public:
    AVLTree();
    AVLTree(BinaryTree bt);
    Node* getAVLRoot();

};

#endif // AVLTREE_H
