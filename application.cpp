#include "application.h"

Application::Application() {}

int Application::exec()
{
    //std::string str = "(8 (9 (5)(6) ) (1))";
    std::string str = "(9 (6 (3 (1 (2)) (4 (5))) (8 (7))) (17 (16 (12 (11 (10)) (14 (13) (15)))) (20 (19 (18)) (21))))";
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

