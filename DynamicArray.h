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
    DynamicArray(){
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
        if (filled < 0 || filled > size) {
            filled = 0;
            size = 0;
        }

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

        if (newSize == size){return;}// длина не изменится

        if (newSize < size){
            T *new_array = new T[newSize];
            for (int i = 0; i < newSize; i++){
                new_array[i] = array[i];
            }
            delete[] array;
            size = newSize;
            if (filled > newSize){filled = newSize;}
            array = new_array;
            return;
        }// укорачивание массива

        if (newSize > 0 && size == 0){
            T *new_array = new T[newSize];
            delete[] array;
            size = newSize;
            array = new_array;
        }//увеличение размера массива 0 длины

        if (newSize > size){
            T *new_array = new T[newSize];
            for (int i = 0; i < filled; i++){
                new_array[i] = array[i];
            }
            delete[] array;
            size = newSize;
            array = new_array;
            return;
        }// увеличение длины
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

    DynamicArray<T>* &operator = (DynamicArray<T>* dynamicArray) {
        Resize(dynamicArray->GetSize());
        size = dynamicArray->GetSize();
        filled = dynamicArray->GetFilled();
        for (int i = 0; i < filled; i++){
            array[i] = dynamicArray->array[i];
        }
        return *this;
    }
};

#endif //LABORATORY_WORK_3_DYNAMICARRAY_H
