#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <node.h>
#include <iostream>
#include <QFile>
#include <string>
#include <vector>

class BinaryTree
{
    Node* root = nullptr;
    //Node* rootBackup;
    //std::string str = "(8 (9 (5)) (1))";
    //const std::string file = "tree.txt";
    //QFile data(file);
    int charCount(std::string str, char ch);
    void deleteTree(Node*& root);
    std::vector<std::string> parseString(const std::string& input); // Да, эта функция из ChatGPT

public:
    void setRoot(Node*& root);
    //void setRootBackup(Node*& root);
    void addNode(type data, Node*& parent, std::string pos);
    Node* maxData(Node* root);
    Node* search(Node* root, int num);
    void deleteNode(Node*& root, int num);
    Node* getRoot();
    type getRootNum();
    void directBypass(Node* root);
    void symmetricBypass(Node* root);
    void reversedBypass(Node* root);
    void bybass(Node* root, char choice);
    void showTree(Node* tree, int level, bool isRight);
    BinaryTree();
    BinaryTree(std::string data);

    void deleteTree();
};

#endif // BINARYTREE_H
