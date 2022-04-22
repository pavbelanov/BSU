//#pragma once
#ifndef _VECTOR_H
#define _VECTOR_H

#include <algorithm>
#include <iostream>

template<typename T>
class Vector {
public:
    Vector() :  size(0), arr(nullptr) {}
    Vector(size_t size) : size(size), arr(new T[size]) {
    }
    
    Vector(const Vector<T>& vector) {
        this->size = vector.size;
        this->arr = new T[size];
        memcpy(this->arr, vector.arr, sizeof(T)*this->size);
    }
    Vector<T>& operator= (const Vector<T>& vector) {
        if(this != &vector){
            delete[] arr;

        this->size = vector.size;
        this->arr = new T[size];
        memcpy(this->arr, vector.arr, sizeof(T)*this->size);
        }
        return *this;
    }
    ~Vector(){
        delete[] arr;
        std::cout << "~Vector()\n";
    }
    void SetSize(size_t size) {
        T* new_arr = new T[size]{};

        if(this->arr){
            std::memcpy(new_arr, this->arr, sizeof(T)*std::min(size,this->size));
            delete[] this->arr;
        }
        for (int i = std::min(size, this ->size); i < size; i++){
            new_arr[i] = 0;
        }
        
        this->arr = new_arr;
        this->size = size;
    }

    size_t GetSize() const {
        return this->size;
    }

    void Append(T element) {
        SetSize(this->size + 1);
        this->arr[this->size - 1] = element;
    }

    T& operator[](size_t index) {
            if (index >= size)
                throw std::invalid_argument("Index is out of bounds");
            return this->arr[index];
        }

    const T& operator[](size_t index) const {
        if(index >= size)
            throw std::invalid_argument("index is out of bounds");

        return this->arr[index];
    }


private:
    size_t size;
    T* arr;
};

template<typename T> // перегрузка шаблон
std::ostream& operator << (std::ostream &os, const Vector<T>& vector)
{
    for(size_t i = 0; i<vector.GetSize(); i++)
        os<< vector[i] << " ";
    
    return os;
}

#endif
