#include "application.h"

Application::Application() {}

void Application::input() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cout << "Incorrect input!" << std::endl;
        return;
    }
    return;
}

int Application::exec()
{
    //std::string str = "(10 (11 (12)))";
    std::string str = "(9 (6 (3 (1 (2)) (4 (5))) (8 (7))) (17 (16 (12 (11 (10)) (14 (13) (15)))) (20 (19 (18)) (21))))";
    BinaryTree bt(str);
    bt.bybass(bt.getRoot(), 's');
    if (bt.getRoot() == nullptr) std::cout << "No root!" << std::endl;
    std::cout << "\n\n\n";
    bt.showTree(bt.getRoot(), 0, 0);
    AVLTree avlt(bt);
    Node* root = avlt.getAVLRoot();


    /*
    avlt.insert(20, root);
    avlt.insert(2, root);
    avlt.insert(3, root);
    avlt.insert(4, root);
    avlt.insert(30, root);
    avlt.insert(25, root);

    //avlt.showTree(avlt.getAVLRoot(), 0, 0);
    avlt.bybass(root, 'd');
    std::cout << std::endl;
    avlt.bybass(root, 's');
    std::cout << std::endl;
    avlt.bybass(root, 'r');
    std::cout << std::endl;
    avlt.bybass(root, 'w');
    std::cout << std::endl;
    std::cout << "Element search: " << avlt.search(root, 10) << std::endl;
    std::cout << "\n\n\n";
    avlt.remove(root, 12);
    avlt.showTree(avlt.getAVLRoot(), 0, 0);
    */

    type choice = 1;
    while (choice) {
        type element = 0;
        std::cout << "\n\n" "------------------------------------------------------------------------------------------------------------------------" "\n";
        std::cout << "Choose your option:" "\n"
                     "1. Show tree" "\n"
                     "2. Add new element" "\n"
                     "3. Delete element" "\n"
                     "4. Search for element" "\n"
                     "5. Show different bypasses" "\n"
                     "0. Cancel this moratorium!" "\n\n"
                     "Your choice: ";
        std::cin >> choice;
        input();

        std::cout << "\n\n";
        if (choice == 1) {
            avlt.showTree(root, 0, 0);
        }
        else if (choice == 2) {
            std::cout << "Enter an element to add: ";
            std::cin >> element;
            input();
            if (avlt.search(root, element)) std::cout << "\n" "This element already exists!" << std::endl;
            else {
                avlt.insert(element, root);
                std::cout << "\n" "A new element has been added!" << std::endl;
            }
        }
        else if (choice == 3) {
            std::cout << "Enter an element to delete: ";
            std::cin >> element;
            input();
            avlt.remove(root, element);
            std::cout << "\n" "This element has been viped from the tree!" << std::endl;
        }
        else if (choice == 4) {
            std::cout << "Enter an element to search: ";
            std::cin >> element;
            input();
            if (avlt.search(root, element))
                std::cout << "\n" "This element has been found!" << std::endl;
            else
                std::cout << "\n" "There is no such element!" << std::endl;
        }
        else if (choice == 5) {
            avlt.bybass(root, 'd');
            std::cout << std::endl;
            avlt.bybass(root, 's');
            std::cout << std::endl;
            avlt.bybass(root, 'r');
            std::cout << std::endl;
            avlt.bybass(root, 'w');
            std::cout << std::endl;
        }

    }

    bt.deleteTree();
    avlt.deleteTree();
    return 0;
}

