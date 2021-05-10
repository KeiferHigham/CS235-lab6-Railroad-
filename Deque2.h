#ifndef LAB6RAILROAD2_DEQUE2_H
#define LAB6RAILROAD2_DEQUE2_H
#include "DequeInterface2.h"
#include "Car2.h"

using namespace std;

#define DEFAULT_CAPACITY 4
template <typename T>
class Deque : DequeInterface<T>  {
public:
    Deque() {
        capacity = DEFAULT_CAPACITY;
        numItems = 0;
        front_index = 0;
        rear_index = DEFAULT_CAPACITY - 1;
        data = new T[DEFAULT_CAPACITY];
    }
    ~Deque() {
        delete [] data;
    }
    void push_front(const T& value) {
        if(numItems >= capacity) {
            Reallocate();
        }
        front_index = (front_index - 1) % capacity;
        data[front_index] = value;
        ++numItems;
    }
    void Reallocate() {
        size_t newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        size_t old = front_index;

        for(size_t i = 0; i < numItems; ++i) {
            newData[i] = data[old];
            old = (old + 1) % capacity;
        }
        front_index = 0;
        rear_index = numItems - 1;
        capacity = newCapacity;
        swap(data,newData);
        delete [] newData;
    }
    void pop_front() {
        //Ill want to throw an error here to check if its empty

        numItems = numItems - 1;
        front_index = (front_index + 1) % capacity;
        return;
    }
    void push_back(const T& value) {
        if(numItems == capacity) {
            Reallocate();
        }
        numItems = numItems + 1;
        rear_index = (rear_index + 1) % capacity;
        data[rear_index] = value;
    }

    /** Remove the rear item of the deque */
    void pop_back(void) {
        if(numItems != 0) {
            numItems = numItems - 1;
            rear_index = rear_index -1 % capacity;
        }
        return;
    }


    /** Return the front item of the deque (Do not remove) */
    T& front(void) {
        // will want to put an if statement to throw error if array is empty
        return data[front_index];

    }

    /** Return the rear item of the deque (Do not remove) */
    T& back(void) {
        // Ill want to put an if statement right here to check if empty
        return data[rear_index];
    }

    /** Return the number of items in the deque */
    virtual size_t size(void) const {
        return numItems;
    }

    /** Return true if deque is empty */
    bool empty(void) const {
        if(numItems == 0) {
            return true;
        }

        return false;
    }

    /** Return item in deque at index (0 based) */
    T& at(size_t index) {
        // put an if else to makes sure that index isnt greater than or equal to nuitmes
        return data[(front_index + index) % capacity];
    }

    /** Return the deque items */
    virtual string toString(void) const {
        return "hello";
    }

private:
    int numItems;
    int front_index;
    int rear_index;
    T* data;
    int capacity;

};



#endif //LAB6RAILROAD2_DEQUE2_H
