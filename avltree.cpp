#include "avltree.h"

AVLTree::AVLTree() {}

AVLTree::AVLTree(BinaryTree bt)
{
    std::vector<type> nums;
    createBypass(nums, bt.getRoot());
    std::sort(nums.begin(), nums.end());


    //std::cout << "\nSorted vector: ";
    //for (type num: nums) std::cout << num << " ";

    this->root = createTree(nums, 0, nums.size()-1);
    //std::cout << "\navl root: " << this->root << "(" << getAVLRoot() << ")" << std::endl;
    setHeight(this->root);
}

Node *AVLTree::getAVLRoot()
{
    return this->root;
}

Node *AVLTree::insert(type num, Node *&node)
{
    if( !node ) return new Node(num);
    if( num<node->data )
        node->left = insert(num, node->left);
    else if( num>node->data )
        node->right = insert(num, node->right);
    else return node;
    setHeight(this->root);
    return balance(node);
}

Node *AVLTree::search(Node *node, type num)
{
    // Если узел пуст или ключ найден
    if (node == nullptr || node->data == num) {
        return node;
    }

    // Если ключ меньше, ищем в левом поддереве
    if (num < node->data) {
        return search(node->left, num);
    }

    // Иначе ищем в правом поддереве
    return search(node->right, num);
}

Node *AVLTree::findmin(Node *node)
{
    return node->left?findmin(node->left):node;
}

Node *AVLTree::removeMin(Node *node)
{
    if( node->left==0 )
        return node->right;
    node->left = removeMin(node->left);
    return balance(node);
}

Node *AVLTree::remove(Node *node, type num)
{
    if( !node ) return 0;
    if( num < node->data )
        node->left = remove(node->left, num);
    else if( num > node->data)
        node->right = remove(node->right, num);
    else {
        Node* q = node->left;
        Node* r = node->right;
        delete node;
        if( !r ) return q;
        Node* min = findmin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(node);
}

Node *AVLTree::rotateRight(Node *&node)
{
    Node* nodeLeft = node->left;
    node->left = nodeLeft->right;
    nodeLeft->right = node;
    node->fixHeight();
    nodeLeft->fixHeight();
    return nodeLeft;
}

Node *AVLTree::rotateLeft(Node *&node)
{
    Node* nodeRight = node->right;
    node->right = nodeRight->left;
    nodeRight->left = node;
    node->fixHeight();
    nodeRight->fixHeight();
    return nodeRight;
}
/*
Node *AVLTree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + std::max(height(y->left),
                        height(y->right));
    x->height = 1 + std::max(height(x->left),
                        height(x->right));

    // Return new root
    return x;
}

Node *AVLTree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + std::max(height(x->left),
                        height(x->right));
    y->height = 1 + std::max(height(y->left),
                        height(y->right));

    // Return new root
    return y;
}

int AVLTree::getBalance(Node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node *AVLTree::realInsert(Node *node, type key)
{
    // Perform the normal BST insertion
    if (node == nullptr)
        return new Node(key);

    if (key < node->data)
        node->left = realInsert(node->left, key);
    else if (key > node->data)
        node->right = realInsert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    // Update height of this ancestor node
    node->height = 1 + std::max(height(node->left),
                           height(node->right));

    // Get the balance factor of this ancestor node
    int balance = getBalance(node);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}
*/
Node *AVLTree::balance(Node *&node)
{
    node->fixHeight();

    if( node->heightDiff()==2 )
    {
        if( node->right->heightDiff() < 0 )
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    if( node->heightDiff()==-2 )
    {
        if( node->left->heightDiff() > 0  )
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

void AVLTree::setRoot(Node *newRoot)
{
    root = newRoot;
}

void AVLTree::createBypass(std::vector<type>& nums, Node *node)
{
    if (node) {
        createBypass(nums, node->left);
        nums.push_back(node->data);
        createBypass(nums, node->right);
    }
}

Node* AVLTree::createTree(std::vector<type>& nums, int left = 0, int right = 0)
{
    if (left > right)
        return nullptr;
    int mid = (left+right) / 2;

    Node* node = new Node(nums[mid], 0);

    node->left = createTree(nums, left, mid-1);
    node->right = createTree(nums, mid+1, right);

    return node;
}

int AVLTree::setHeight(Node* root)
{
    if (!root)
        return 0;
    else {
        root->height = std::max(setHeight(root->left), setHeight(root->right)) + 1;
        return std::max(setHeight(root->left), setHeight(root->right)) + 1;
    }
}

int AVLTree::height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}
