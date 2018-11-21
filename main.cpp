#include <iostream>
#include <cstdlib>

#include "bst.cpp"

int main () {

    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    BST myTree;

    std::cout << "Printing the tree in order" << std::endl << "Before adding numbers" << std::endl;

    myTree.PrintInOrder();

    for (auto i: TreeKeys)
    {
        myTree.AddLeaf(i);
    }

    std::cout << "Printing the tree in order" << std::endl << "After adding numbers" << std::endl;
    myTree.PrintInOrder();
    std::cout << std::endl;

    std::cout << "The smallest value in the tree is " << myTree.FindSmallest() << std::endl;
    
    return 0;
}
