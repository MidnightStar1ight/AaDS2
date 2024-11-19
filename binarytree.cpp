#include "binarytree.h"

int BinaryTree::charCount(std::string str, char ch)
{
    int count = 0;
    for (char i: str) {
        if (i == ch) count++;
    }
    return count;
}

void BinaryTree::addNode(type data, Node*& parent, std::string pos)
{
    if (pos == "root") this->root = new Node(data, nullptr);
    else if (pos == "left") parent->left = new Node(data, parent);
    else if (pos == "right") parent->left = new Node(data, parent);
    else std::cout << "Sheesh, node ain't been added";
}

Node *BinaryTree::maxData(Node *root)
{
    if (root) {
        if (root->right)
            return maxData(root->right);
        return root;
    }
    else return nullptr;
}

Node *BinaryTree::search(Node *root, int num)
{
    if (root != nullptr) {
        if (num == root->data)
            return root;
        if (num < root->data)
            return search(root->left, num);
        else
            return search(root->right, num);
    }
    else {
        std::cout << "Value is not found" << std::endl;
        return nullptr;
    }
}

void BinaryTree::deleteNode(Node *&root, int num)
{
    Node* del = search(root, num);
    if (!del) return;
    if (!del->left && !del->right) {
        if (del->parent) {
            if (del == del->parent->left)
                del->parent->left = nullptr;
            else
                del->parent->right = nullptr;
        }
        delete del;
        return;
    }
    if (del->left && !del->right) {
        if (del->parent) {
            if (del == del->parent->left)
                del->parent->left = del->left;
            else
                del->parent->right = del->left;
        }
        delete del;
        return;
    }
    if (!del->left && del->right) {
        if (del->parent) {
            if (del == del->parent->left)
                del->parent->left = del->right;
            else
                del->parent->right = del->right;
        }
        delete del;
        return;
    }
    if (del->left && del->right) {
        std::swap(del->data, maxData(del->left)->data);
        del = maxData(del->left);
        if (del->parent) {
            if (del == del->parent->left)
                del->parent->left = del->left;
            else
                del->parent->right = del->left;
        }
        delete del;
        return;
    }
}

Node *BinaryTree::getRoot()
{
    return this->root;
}

type BinaryTree::getRootNum()
{
    return this->root->data;
}

void BinaryTree::directBypass(Node* root) {
    if (root) {
        std::cout << root->data << " ";
        directBypass(root->left);
        directBypass(root->right);
    }
}

void BinaryTree::symmetricBypass(Node* root) {
    if (root) {
        symmetricBypass(root->left);
        std::cout << root->data << " ";
        symmetricBypass(root->right);
    }
}

void BinaryTree::reversedBypass(Node* root) {
    if (root) {
        reversedBypass(root->left);
        reversedBypass(root->right);
        std::cout << root->data << " ";
    }
}

void BinaryTree::wideBypass(Node *root)
{
    std::queue<Node*> elements;
    elements.push(root);
    while (!elements.empty()) {
        root = elements.front();
        elements.pop();
        std::cout << root->data << " ";
        if (root->left)
            elements.push(root->left);
        if (root->right)
            elements.push(root->right);
    }
}

void BinaryTree::bybass(Node *root, char choice)
{
    if (choice == 'd') {
        std::cout << "Tree with direct bypass: ";
        directBypass(root);
    }
    else if (choice == 's') {
        std::cout << "Tree with symmetric bypass: ";
        symmetricBypass(root);
    }
    else if (choice == 'r') {
        std::cout << "Tree with reversed bypass: ";
        reversedBypass(root);
    }
    else if (choice == 'w') {
        std::cout << "Tree with wide bypass: ";
        wideBypass(root);
    }
    else std::cout << "Wrong choice!" << std::endl;
}

void BinaryTree::showTree(Node* tree, int level = 0, bool isRight = false)
{
    if (tree == NULL) return;
    showTree(tree->right, level + 1, true);

    if (!level) std::cout << "-->"; // марафет для корня дерева
    else std::cout << "   ";

    for (int i = 0; i < level; i++) {
        if (i + 1 == level) isRight ? std::cout << ".-->" : std::cout << "`-->"; // отступ для уровня
        else std::cout << "    ";
    }

    std::cout << tree->data << "\n";
    //std::cout << tree->height << "\n";
    //std::cout << tree->heightDiff() << "\n";

    showTree(tree->left, level + 1);
}

BinaryTree::BinaryTree() {
    this->root = nullptr;
}

BinaryTree::BinaryTree(std::string data)
{
    while (data.find(' ') != data.npos) data.erase(data.find(' '), 1);
    std::cout << "current string: " << data << std::endl;

    // Обработка ошибок
    if (charCount(data, '(') < charCount(data, ')')) {
        std::cout << "Error: unequal number of braces: ')' more than '('" << std::endl;
        return;
    }
    if (charCount(data, '(') > charCount(data, ')')) {
        std::cout << "Error: unequal number of braces: '(' more than ')'" << std::endl;
        return;
    }
    if (data[1] == '(' or data[1] == ')') {
        std::cout << "Error: tree without root" << std::endl;
        return;
    }
    for (int i = 0; i < data.size(); i++) {
        if (data[i]=='(' && data[i+1]=='(') {
            std::cout << "Error: node missing. Two '(' in a row" << std::endl;
            return;
        }
    }

    data.erase(0, 1);
    data.erase(data.size()-1, 1);
    //std::cout << "current string: " << data << std::endl;

    std::vector<std::string> vData = parseString(data);

    Node* currNode = nullptr;
    Node* tempNode = nullptr;

    for (std::string currSymbol: vData) {
        if (this->root == nullptr) {
            this->root = new Node(std::stod(currSymbol), nullptr);
            currNode = this->root;
            continue;
        }
        if (currSymbol == "(") {
            if ((currNode->left != nullptr) && (currNode->right != nullptr)) {
                std::cout << "Error: '" << currNode->data << "' has more than 2 childs" << std::endl;
                this->root = nullptr;
                return;
            }
            if (currNode->left == nullptr) {
                tempNode = currNode;
                currNode = currNode->left;
                currNode = new Node(0, tempNode);
                tempNode->left = currNode;
                //currNode->parent = tempNode;
            }
            else {
                /*
                tempNode = currNode;
                currNode = currNode->right;
                currNode->parent = tempNode;
                */
                tempNode = currNode;
                currNode = currNode->right;
                currNode = new Node(0, tempNode);
                tempNode->right = currNode;
            }
        }
        else if (currSymbol == ")")
            currNode = currNode->parent;
        else {
            //currNode = new Node(type(currSymbol), nullptr);
            currNode->data = std::stod(currSymbol);

        }
    }
}

void BinaryTree::deleteTree() {
    deleteTree(this->root);
}

void BinaryTree::deleteTree(Node*& root)
{
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    else root = nullptr;
}

std::vector<std::string> BinaryTree::parseString(const std::string &input)
{
    std::vector<std::string> result;
    std::string currentNumber;

    for (char ch : input) {
        if (std::isdigit(ch)) {
            // Если символ - цифра, добавляем его к текущему числу
            currentNumber += ch;
        } else {
            // Если текущий символ - не цифра и есть накопленное число, добавляем его в результат
            if (!currentNumber.empty()) {
                result.push_back(currentNumber);
                currentNumber.clear(); // Очищаем текущее число
            }
            // Добавляем символ (скобку) в результат
            if (ch == '(' || ch == ')') {
                result.push_back(std::string(1, ch));
            }
        }
    }

    // Если в конце осталась цифра, добавляем ее в результат
    if (!currentNumber.empty()) {
        result.push_back(currentNumber);
    }

    return result;
}
