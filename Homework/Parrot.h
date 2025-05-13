#pragma once
#include "Animal.h"

class Parrot : public Animal {
public:

    Parrot() = default;
    explicit Parrot(const string& name) : Animal(name) {}

    void Sound() const override {
        cout << "Squawk! Squawk!" << endl;
    }

    void Type() const override {
        cout << "Type: Parrot" << endl;

    }


    bool CanFly() override { return true; }
    bool CanSwim() override { return false; }
    bool CanClimb() override { return false; }

};
