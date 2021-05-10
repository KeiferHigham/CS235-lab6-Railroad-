#ifndef LAB6RAILROAD2_CAR2_H
#define LAB6RAILROAD2_CAR2_H
#include <iostream>

using namespace std;

struct Car {
    unsigned int id;

    Car() {
        id = 0;
    }
    ~Car(){}
    void SetCar(unsigned int car) {
        id = car;
    }

    bool operator==(const Car car) {
        return this->id == car.id;
    }

    bool operator!=(const Car car) {
        return this->id != car.id;
    }

};

#endif //LAB6RAILROAD2_CAR2_H
