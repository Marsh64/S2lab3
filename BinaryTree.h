#ifndef LABORATORY_WORK_3_BINARYTREE_H
#define LABORATORY_WORK_3_BINARYTREE_H
#include "DynamicArray.h"


template<class T, class K>
class BinaryTree {
private:
    typedef struct Info{
        K key;
        T item;
    } Info;
    typedef struct Node{
        Info info;
        Node* left;
        Node* right;
    } Node;

    Node* root;

    void DeleteElementFirst(struct Node* temp, struct Node* temparent){
        if (temp == temparent->left)
            temparent->left = nullptr;
        else
            temparent->right = nullptr;

        delete temp;
    }
    void DeleteElementSecond(struct Node* temp, struct Node* temparent){
        struct Node* tempchild = nullptr;
        if (temp->left == nullptr)
            tempchild = temp->right;
        else
            tempchild = temp->left;

        if (temp == temparent->left)
            temparent->left = tempchild;
        else
            temparent->right = tempchild;

        delete temp;
    }
    void DeleteElementThird(struct Node* temp){
        Node* nxttemparent = temp;
        Node* nxttemp = temp->right;
        while(nxttemp->left != nullptr){
            nxttemparent = nxttemp;
            nxttemp = nxttemp->left;
        }

        temp->info.key = nxttemp->info.key;
        temp->info.item = nxttemp->info.item;

        if (nxttemp->left == nullptr && nxttemp->right == nullptr)
            DeleteElementFirst(nxttemp, nxttemparent);
        else
            DeleteElementSecond(nxttemp, nxttemparent);
    }

public:
    class WrongKey{};

    BinaryTree(){
        root = nullptr;
    }

    struct Node* AddNote(K key, T item, Node* tree){
        if (tree == nullptr){
            tree = new Node;
            tree->info.key = key;
            tree->info.item = item;
            tree->left = nullptr;
            tree->right = nullptr;
        }else if (key < tree->info.key)
            tree->left = AddNote(key, item, tree->left);
        else if (key == tree->info.key)
            throw WrongKey();
        else
            tree->right = AddNote(key, item, tree->right);
        return tree;
    }//добавление узла в бинарное дерево, tree - указатель на корень в самом начале

    struct Node* SearchElement(K key){
        Node* temp = new Node;
        Node* search = nullptr;
        temp = root;
        while(temp != nullptr && search == nullptr){
            if (key < temp->info.key)
                temp = temp->left;
            else if (key > temp->info.key)
                temp = temp->right;
            else
                search = temp;
        }
        return search;
    }//Поиск элемента по ключу

    void DeleteElement(K key){
        Node* temp = new Node;
        Node* search = nullptr;
        Node* temparent = nullptr;
        temp = root;

        while(temp != nullptr && search == nullptr){
            if (key < temp->info.key){
                temparent = temp;
                temp = temp->left;
            }
            else if (key > temp->info.key){
                temparent = temp;
                temp = temp->right;
            }
            else
                search = temp;
        }

        if (search == nullptr)
            throw WrongKey();
        else{
            if (temp->left == nullptr && temp->right == nullptr)
                DeleteElementFirst(temp, temparent);
            else if (temp->left == nullptr || temp->right == nullptr)
                DeleteElementSecond(temp, temparent);
            else if (temp->left != nullptr && temp->right != nullptr)
                DeleteElementThird(temp);
        }
    }//Удаляет узел с этим ключом





};


#endif //LABORATORY_WORK_3_BINARYTREE_H
