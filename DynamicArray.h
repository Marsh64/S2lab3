#ifndef LABORATORY_WORK_3_DYNAMICARRAY_H
#define LABORATORY_WORK_3_DYNAMICARRAY_H

template <class T>
class DynamicArray {
private:
    T *array;
    int size;
    int filled;
public:
    class IndexOutOfRange {
    };

    //Создание объекта
    DynamicArray() {
        array = nullptr;
        size = 0;
        filled = 0;
    }

    explicit DynamicArray(int newSize) {
        if (newSize < 0) { newSize = 0; }

        array = new T[newSize];
        size = newSize;
        filled = 0;
    }

    //Уадаление объекта
    ~DynamicArray() {
        delete[] array;
        array = nullptr;
        size = 0;
        filled = 0;
    }

    void Delete_DynamicArray() {
        delete[] array;
        array = nullptr;
        size = 0;
        filled = 0;
    }

    //Операции
    void Append(T item) {
        if (filled == size) {
            Resize(100);
        }

        array[filled] = item;
        filled += 1;
    };
    void Resize(int newSize) {
        if (newSize < 0) { throw IndexOutOfRange(); }

        if (newSize == 0) {
            delete[] array;
            array = nullptr;
            size = 0;
            return;
        }// удаление массива
    };
    int GetSize(){
        return size;
    }
    int GetFilled(){
        return filled;
    }
    T GetElement(int index){
        return array[index];
    }


    DynamicArray<T> &operator = (DynamicArray<T> dynamicArray) {
        Resize(dynamicArray.GetSize());
        size = dynamicArray.GetSize();
        filled = dynamicArray.GetFilled();
        for (int i = 0; i < filled; i++){
            array[i] = dynamicArray.array[i];
        }
        return *this;
    }
};

#endif //LABORATORY_WORK_3_DYNAMICARRAY_H
