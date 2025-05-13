#ifndef ANIMAL
#define ANIMAL
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal;
/*
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай», «Хомяк». С помощью конструктора установить имя каждого животного и его характеристики.
Реализуйте для каждого из классов функции:
Sound - издает звук животного (пишем текстом в консоль).
Show - отображает имя животного.
Type - отображает название его подвида.

*/

class Animal {
protected:
    string name;
public:
    Animal() = default;
    explicit Animal(const string& name) : name(name) {}

    virtual void Sound() const = 0;
    virtual void Show() const {
        cout << "Name: " << name << endl;
    }

    virtual void Type() const = 0;
    
    virtual bool CanFly() = 0;
    virtual bool CanSwim() = 0;
    virtual bool CanClimb() = 0;

    virtual ~Animal() = default; 

};
#endif // !ANIMAL