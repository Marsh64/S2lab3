#ifndef LABORATORY_WORK_3_HEAPARRAY_H
#define LABORATORY_WORK_3_HEAPARRAY_H
#include "BinaryHeap.h"

template <class T>
class HeapArray : BinaryHeap<T>{
private:
    int SIZE = 100;
    T* heap;
    int HeapSize;

    int IsParent(int parent, int child){
        int temp = 0;
        if (parent == 0)
            return 1;


        while (child >= parent){
            if (child == parent){
                temp = 1;
            }
            child = (child - 1)/2;
        }

        return temp;
    }
public:
    class IndexOutOfRange{};
    HeapArray(){
        HeapSize = 0;
        heap = new T[SIZE];
    }

    void Resize(){
        if (HeapSize == SIZE){
            SIZE += 100;
        }
    }
    void AddElement(T item){
        Resize();
        int i, parent;
        i = HeapSize;
        parent = (i - 1)/2;
        heap[i] = item;

        while (true){
            if (heap[parent] >= heap[i]){
                break;
            }else{
                T temp = heap[parent];
                heap[parent] = heap[i];
                heap[i] = temp;
                i = parent;
                parent = (i - 1)/2;
            }
        }
        HeapSize ++;
    }
    T FindElement(int key){
        if (key >= HeapSize || key < 0){
            throw IndexOutOfRange();
        }

        return heap[key];
    }
    int FindElementBool (int item){
        int temp = 0;
        for (int i = 0; i < HeapSize; i++){
            if (item == heap[i])
                temp = 1;
            if (temp == 1)
                break;
        }

        return temp;
    }
    void MaxHeapify(int i){
        int right, left, temp;
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < HeapSize){
            if(heap[i] < heap[left]){
                temp = heap[left];
                heap[left] = heap[i];
                heap[i] = temp;
                MaxHeapify(left);
            }
        }
        if (right < HeapSize){
            if (heap[i] < heap[right]){
                temp = heap[right];
                heap[right] = heap[i];
                heap[i] = temp;
                MaxHeapify(right);
            }
        }
    }
    void DeleteElement(int key){
        if (key >= HeapSize || key < 0){
            throw IndexOutOfRange();
        }

        for (int i = key; i < HeapSize - 1; i++){
            heap[i] = heap[i + 1];
        }
        //delete heap[HeapSize - 1];
        HeapSize --;

        if (key == 0){
            MaxHeapify(key);
        }else{
            MaxHeapify((key - 1)/2);
        }
    }
    HeapArray<T>* GetTree(T searched){
        int k = -1;
        for (int i = 0; i < HeapSize; i++){
            if (heap[i] == searched) {
                k = i;
                break;
            }
        }//в k будет находиться индекс искомого элемента
        if (k != -1){
            T* newHeaparr1 = new T[HeapSize];
            int newHeap1size = 1;
            newHeaparr1[0] = searched;
            for (int i = k; i < HeapSize; i++){
                if (IsParent(k, i) == 1){
                    newHeaparr1[newHeap1size] = heap[i];
                    newHeap1size++;
                }
            }

            T* newHeaparr = new T[newHeaparr1];
            for (int i = 1; i < newHeap1size; i ++){
                newHeaparr[i] = newHeaparr1[i];
            }

            HeapArray<T>* newheap;
            newheap->heap = newHeaparr;
            newheap->HeapSize = newHeap1size;
            newheap->SIZE = SIZE;
            return newheap;
        }else
            return nullptr;
    }//вернет указатель на массив поддерева в начале которого лежит число вершин
    int ContainTree(HeapArray<T> searched){
        if (searched.HeapSize > HeapSize)
            return 0;

        int temp = 1;
        for (T* itm : searched.heap){
            temp *= FindElementBool(&itm);
        }
        return temp;
    }


};


#endif //LABORATORY_WORK_3_HEAPARRAY_H
