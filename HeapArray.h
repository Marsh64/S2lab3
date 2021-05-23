#ifndef LABORATORY_WORK_3_HEAPARRAY_H
#define LABORATORY_WORK_3_HEAPARRAY_H
#include "BinaryHeap.h"

template <class T>
class HeapArray : BinaryHeap<T>{
private:
    int SIZE = 100;
    T* heap;
    int HeapSize;
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
    T* FindElement(int key){
        if (key >= HeapSize || key < 0){
            throw IndexOutOfRange();
        }

        return heap[key];
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
        delete heap[HeapSize - 1];
        HeapSize --;

        if (key == 0){
            MaxHeapify(key);
        }else{
            MaxHeapify((key - 1)/2);
        }
    }




};


#endif //LABORATORY_WORK_3_HEAPARRAY_H
