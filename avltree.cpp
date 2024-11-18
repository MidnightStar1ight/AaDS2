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

    //std::cout << "\nNumber " << node->data << ": " <<  node << " created!";

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
