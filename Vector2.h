
#ifndef LAB6RAILROAD2_VECTOR2_H
#define LAB6RAILROAD2_VECTOR2_H
#include "Deque2.h"

template<typename T>
class Vector
{

public:

    T& at(size_t index) {
        return vector.at(index);
    }

    void push_back(const T &value) {
        vector.push_back(value);
    }
    void popback() {
        vector.pop_back();
    }
    size_t Size() {
        return vector.size();
    }
    T& Back() {
        return vector.back();
    }












private:
    Deque<T> vector;











};



#endif //LAB6RAILROAD2_VECTOR2_H
