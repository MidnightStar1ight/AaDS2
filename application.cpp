#include "application.h"

Application::Application() {}

int Application::exec()
{
    std::string str = "(8 (9 (5)(6) ) (1))";
    BinaryTree bt(str);
    bt.bybass(bt.getRoot(), 's');
    if (bt.getRoot() == nullptr) std::cout << "No root!" << std::endl;
    //else std::cout << bt.getRootNum();

    std::cout << "\n\n\n";
    //bt.showTree(bt.getRoot(), 0, 0);
    AVLTree avlt(bt);
    Node* r = avlt.getAVLRoot();
    avlt.showTree(avlt.getAVLRoot(), 0, 0);
    //std::cout << "\n\n\n AVL root: " << r;

    bt.deleteTree();
    //std::cout << "End!";
    return 0;
}

