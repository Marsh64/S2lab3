#include <iostream>
#include "BinaryTree.h"
#include "HeapArray.h"

int main() {
    /*
    BinaryTree<int, int> tree;
    for (int i = 0; i < 3; i++){
        int a, b;
        std::cout << "Введите " << i << " ключ элемента" << std::endl;
        std::cin >> a;
        std::cout << "Введите " << i << " Элемент" << std::endl;
        std::cin >> b;
        tree = tree.AddNote(a, b, tree.GetRoot());
    }

    std::cout << tree.ContainElement(3) << std::endl;
    std::cout << *(tree.SearchElement(2)) << std::endl;
    */

    HeapArray<int> tree;
    for (int i = 0; i < 4; i ++){
        int a;
        std::cout << "Введите " << i << " Элемент" << std::endl;
        std::cin >> a;
        tree.AddElement(a);
    }

    //std::cout << tree.FindElementBool(6) << std::endl;
    //std::cout << tree.FindElementBool(5) << std::endl;
    std::cout << tree.FindElement(0) << std::endl;
    std::cout << tree.FindElement(1) << std::endl;
    std::cout << tree.FindElement(2) << std::endl;
    std::cout << tree.FindElement(3) << std::endl;
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
