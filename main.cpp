#include "binarytree.h"


int main(int argc, char *argv[])
{
    std::string str = "(8 (9 (5)(6) ) (1))";
    BinaryTree bt(str);
    bt.bybass(bt.getRoot(), 's');
    if (bt.getRoot() == nullptr) std::cout << "No root!" << std::endl;
    //else std::cout << bt.getRootNum();

    std::cout << "\n\n\n";
    bt.showTree(bt.getRoot(), 0, 0);
    std::cout << "\n\n\n";

    bt.deleteTree();
    std::cout << "End!";
    return 0;
}
