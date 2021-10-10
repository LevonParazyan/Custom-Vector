#include <iostream>
#include "Vector.h"
using std::cout;

void Vector::clear() {
    size = 0;
}

void Vector::insert(int pos, int val) {
    if (pos > size) return;
    buffer[pos - 1] = val;
}

void Vector::erase(int pos) {
        if(pos > size - 1) return;
        for (int i = pos - 1; i < size - 1; ++i) {
            buffer[i] = buffer[i + 1];
        }
    --size;
}

int Vector::get_size() const {
    return size;
}

void Vector::pop_back() {
    --size;
}

void Vector::get_data() {
    cout << "SIZE:" << size << std::endl << "CAPACITY:" << capacity << std::endl;
}

Vector::Vector() {
    capacity = 5;
    size = 0;
    buffer = new int[capacity];
}

// Vector::Vector(int size_, int capacity_) {
//     size = size_;
//     capacity = capacity_;
//     cout << size << ',' << capacity;
// }

void Vector::push_back(int val){
    if(size == capacity) {
        capacity *= 2;
        int * tmp = new int[capacity];
        for (int i = 0; i < size; ++i) {
            tmp[i] = buffer[i];
        }
        delete [] buffer;
        buffer = tmp;
    }
    buffer[size] = val;
    ++size;
}

int Vector::operator[](int index) {
    return buffer[index];
}

int main() {
    Vector vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i * 3);
        cout << vec[i] << ',';
    }
    cout << std::endl;
    vec.erase(3);
    for (int i = 0; i < vec.get_size(); i++) {
        cout << vec[i] << ',';
    }
    cout << std::endl;
    vec.get_data();
    return 0;
}