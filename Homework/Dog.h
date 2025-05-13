#pragma once


#include "Animal.h"

class Dog : public Animal {
public:
    Dog() = default;
    explicit Dog(const string& name) : Animal(name) {}

    void Sound() const override {
        cout << "Woof! Woof!" << endl;
    }

    void Type() const override {
        cout << "Type: Dog" << endl;
    }

    bool CanFly() override { return false; }
    bool CanSwim() override { return true; }
    bool CanClimb() override { return false; }

};
