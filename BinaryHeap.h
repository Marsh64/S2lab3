#ifndef LABORATORY_WORK_3_BINARYHEAP_H
#define LABORATORY_WORK_3_BINARYHEAP_H

template<class T>
class BinaryHeap {
public:
    virtual void AddElement(T item) = 0;//вставка элемента
    virtual T FindElement(int key) = 0;//поиск элемента по ключу
    virtual void DeleteElement(int key) = 0;//удаление объекта по ключу

    virtual void MaxHeapify(int key) = 0;
    //virtual BinaryHeap<T> GetTree(T item) = 0;//извлечение поддерева(по заданному элементу)

};


#endif //LABORATORY_WORK_3_BINARYHEAP_H
