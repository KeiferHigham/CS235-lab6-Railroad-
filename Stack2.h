#ifndef LAB6RAILROAD2_STACK2_H
#define LAB6RAILROAD2_STACK2_H
#include "Deque2.h"

using namespace std;
template<typename T>

class Stack {

public:

    bool empty() {
      return  stack.empty();
    }

    size_t Size() {
      return  stack.size();
    }

    void push(const T& value) {
        stack.push_back(value);

    }


    void pop() {
        stack.pop_back();
    }

    T& back() {
      return  stack.back();
    }
    T& top() {
        return stack.back();

    }

    size_t StackSize() {
        return Size();
    }


private:

    Deque<T> stack;

};


#endif //LAB6RAILROAD2_STACK2_H
