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

    void DeleteElementFirst(Node* temp, Node* temparent){
        if (temp == temparent->left)
            temparent->left = nullptr;
        else
            temparent->right = nullptr;

        delete temp;
    }
    void DeleteElementSecond(Node* temp, Node* temparent){
        Node* tempchild = nullptr;
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
    void DeleteElementThird(Node* temp){
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
    void RoundTree(Node* tree, DynamicArray<Info>* arr){
        if (tree != nullptr) { //Пока не встретится пустой узел
            RoundTree(tree->left); //Рекурсивная функция для левого поддерева
            arr->Append(&tree->info);
            RoundTree(tree->right); //Рекурсивная функция для правого поддерева
        }
    }
public:
    class WrongKey{};

    BinaryTree(){
        root = nullptr;
    }
    Node* AddNote(K key, T item, Node* tree){
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
    Node* GetRoot(){
        return root;
    }
    T* SearchElement(K key){
        Node* temp = new Node;
        Node* search = nullptr;
        temp = root;
        T* tmp = new T;
        while(temp != nullptr && search == nullptr){
            if (key < temp->info.key)
                temp = temp->left;
            else if (key > temp->info.key)
                temp = temp->right;
            else
                search = temp;
        }

        if (search != nullptr){
            *tmp = search->info.item;
            return tmp;
        }else
            throw WrongKey();
    }//Поиск элемента по ключу
    int ContainElement(K key){
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

        if (search != nullptr)
            return 1;
        else
            return 0;
    }//Вхождение элемента
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
    BinaryTree<T, K>* GetTree(K key){
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

        if (search != nullptr){
            BinaryTree<T, K>* newtree;
            newtree->root = search;
            return newtree;
        }else
            throw WrongKey();
    }//поддерево по ключу
    DynamicArray<Info*>* RoundTree(Node* tree){
        tree = root;
        DynamicArray<Info*>* arr;

        RoundTree(tree, arr);
        return arr;
    }
    int ContainTree(BinaryTree<T, K> searched){
        if (searched.root == nullptr)
            return 0;
        if (ContainElement(searched.root->info.key) == 1){
            BinaryTree<T, K> mbtree = new BinaryTree<T, K>;
            mbtree.root = this->GetTree(searched.root->info.key);//здесь лежит уменьшенное исходное дерево, дальнеший поиск ведется в нем

            DynamicArray<Info*>* arrsearched = RoundTree(searched.root);
            int temp = 1;
            for (int i = 0; i < arrsearched->GetFilled(); i++){
                temp *= mbtree.ContainElement((arrsearched->GetElement(i))->key);//TODO в чем беда???????

                if (&(mbtree.SearchElement((arrsearched->GetElement(i)).key)) != arrsearched->GetElement(i).item)
                    temp = 0;

                if (temp == 0)
                    break;
            }

            return temp;
        }else
            return 0;
    }//Вхождение дерева

    void Balancing(){
        DynamicArray<Info*>* arr = RoundTree(root);

        Node* newroot = arr[arr->GetFilled()/2];
        for(int i = 0; i < arr->GetFilled(); i++){
            if (i == arr->GetFilled()/2)
                continue;

            newroot = this->AddNote((arr->GetElement(i)).key, (arr->GetElement(i)).item, newroot);
        }
        //вставить функцию удаления дерева
        root = newroot;
    }

    BinaryTree<T, K> &operator = (Node* tree) {
        this->root = tree;
        return *this;
    }

};


#endif //LABORATORY_WORK_3_BINARYTREE_H
