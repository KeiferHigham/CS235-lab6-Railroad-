
#ifndef LAB6RAILROAD2_QUEUE2_H
#define LAB6RAILROAD2_QUEUE2_H
#include "Deque2.h"
template<typename T>
class Queue
{
public:


    void push(const T &value) {
        queue.push_back(value);
    }

    void pop() {
        queue.pop_front();
    }
    T& front() {
        return  queue.front();
    }

    size_t size() {
        return queue.size();
    }
    T& at(size_t index) {
        return queue.at(index);
    }
    bool Empty() {
        return queue.empty();
    }












private:
    Deque<T> queue;













};


#endif //LAB6RAILROAD2_QUEUE2_H
