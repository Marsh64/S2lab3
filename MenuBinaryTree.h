#ifndef LABORATORY_WORK_3_MENUBINARYTREE_H
#define LABORATORY_WORK_3_MENUBINARYTREE_H
#include <complex>
#include <iostream>
#include "BinaryTree.h"
#include "DynamicArray.h"

using namespace std;

int chooseTypeBinaryTree();
int chooseFunctionBinaryTree();

template<class T, class K>
void inputBinaryTreeTyped(DynamicArray<BinaryTree<T, K>> *Arr);

template<class T, class K>
void functionBinaryTreeTyped(DynamicArray<BinaryTree<T, K>> *Arr);

void MenuBinaryTree();
void InputAndSaveBinaryTree(DynamicArray<BinaryTree<int, int>> *intArr,
                            DynamicArray<BinaryTree<float, float>> *floatArr,
                            DynamicArray<BinaryTree<int, complex<int>>> *complexArr);

void FunctionWithBinaryTree(DynamicArray<BinaryTree<int, int>> *intArr,
                            DynamicArray<BinaryTree<float, float>> *floatArr,
                            DynamicArray<BinaryTree<int, complex<int>>> *complexArr);

template<class T, class K>
void PrintBinaryTreeMassive(BinaryTree<T, K> *tree){
    auto root = tree->GetRoot();
    if (root == nullptr)
        return;

    cout << "[Ключ: " << root->info.key << " Значение: " << root->info.item << "]";
    BinaryTree<T, K> *treeLeft = root->left;
    BinaryTree<T, K> *treeRight = root->right;
    PrintBinaryTreeMassive(treeLeft);
    PrintBinaryTreeMassive(treeRight);
}

template<class T, class K>
void PrintBinaryTreeBeauty(BinaryTree<T, K> *tree, int prob){
    auto root = tree->GetRoot();
    if (root == nullptr)
        return;

    BinaryTree<T, K> *treeRight = root->right;
    PrintBinaryTreeMassive(treeRight, prob + 1);

    for (int i = 0; i < prob; i++)
        cout << "  ";
    cout << root->info.key;

    BinaryTree<T, K> *treeLeft = root->left;
    PrintBinaryTreeMassive(treeLeft, prob + 1);
}

#endif //LABORATORY_WORK_3_MENUBINARYTREE_H
