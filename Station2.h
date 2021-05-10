
#ifndef LAB6RAILROAD2_STATION2_H
#define LAB6RAILROAD2_STATION2_H

#include "Vector2.h"
#include "Queue2.h"
#include "Stack2.h"
#include "Car2.h"
#include <sstream>

template<typename T>

class Station {
public:

    void AddCar(Car car) {
        tableCar = car;
        return;
    }
    Car GetCar() {
        return tableCar;
    }

    void RemoveStation() {
        train.push_back(tableCar);
        tableCar.id = 0;
    }
    void AddStack() {
        stack.push(tableCar);
        tableCar.id = 0;
        cout << stack.top().id << endl;
    }

    void AddQueue() {
        queue.push(tableCar);
        tableCar.id = 0;

    }
    void RemoveQueue() {
       string error = "Remove:queue Queue empty!";
        if(queue.Empty()) {
            throw error;
        }
        if(tableCar.id != 0) {
            throw error;
        }
        else {
            tableCar = queue.front();
            queue.pop();
        }
    }

    void RemoveStack() {
        string error = "Remove:stack Stack empty!";
        if(stack.empty()) {
            throw error;
        }
        if(tableCar.id != 0) {
            throw error;
        }
        else {
            tableCar = stack.back();
            stack.pop();
        }
    }

    T& TopStack() {
            return stack.top();

    }
    bool StackEmpty() {
        bool error = true;
        bool good = false;
        if(stack.empty()) {
            return error;
        }

            return good;

    }

    bool QueueEmpty() {
        bool error = true;
        bool good = false;
        if(queue.Empty()) {
            return error;
        }
        return good;
    }

    T& TopQueue() {
        return queue.front();
    }

    size_t SizeQueue() {
        return queue.size();
    }
    size_t SizeStack() {
        return stack.StackSize();
    }


    string FindCar(unsigned int value) {
        int i = stack.StackSize();
            for(int i =0; i < stack.StackSize(); ++i) {
            if(stack.top().id == value) {
                string index = to_string(i);
                string numVal = to_string(value);
                string output;
                output = "Find " + numVal + " Stack[" + index + "]";
                return output;
            }
            stack.pop();

        }

        for(int i = 0; i < queue.size(); ++i) {
            if(queue.at(i).id == value) {
                string index = to_string(i);
                string numVal = to_string(value);
                string output = "Find " + numVal + " Queue[" + index + "]";
                return output;
            }
        }

        return "Find Value Not Found!";
    }

    string PrintQueue() {
        string output = "";

        for(int i = 0; i < queue.size(); ++i) {
            output = output + " " + to_string(queue.at(i).id);
        }
        return output;
    }

  string PrintStack() {
        string output = "";
        Stack<T> stackBack;
        Stack<T> stackBack2;

        while(!stack.empty()) {
            output = output + " " + to_string(stack.top().id);
            stackBack.push(stack.top());
            stackBack2.push(stack.top());
            stack.pop();
        }


        string output2 = "";
        while(!stackBack2.empty()) {
            output2 = output2 + " " + to_string(stackBack2.top().id);
            stackBack2.pop();
        }

        while(!stackBack.empty()) {
            stack.push(stackBack.top());
            stackBack.pop();
        }

        return output2;
    }

    size_t SizeTrain() {
        return train.Size();
    }

    string PrintTrain() {
        string output = "";
         for(int i = 0; i < train.Size(); ++i) {
             output = output + to_string(train.at(i).id) + " ";
         }
         return output;
    }






private:
    T tableCar;
    Queue<T> queue;
    Stack<T> stack;
    Vector<T> train;




};




#endif //LAB6RAILROAD2_STATION2_H
