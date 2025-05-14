#include <iostream>
#include "Animal.h"
#include "AnimalUtil.h"
#include "Parrot.h"
#include "Dog.h"
#include "Cat.h"

#include "String.h"
#include "BitString.h"
#define PART_ONE

using namespace std;
/*
Задание 1
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай». С помощью конструктора установить имя каждого животного и его характеристики.

Задание 2
Описать базовый класс «Строка».

Методы:

конструктор без параметров;+
конструктор, принимающий в качестве параметра C-строку (заканчивается нулевым байтом);+
конструктор копирования;+
оператор присваивания;+
получение длины строки;+
очистка строки (сделать строку пустой);+
деструктор;+
конкатенация строк (перегрузить операторы + и +=);+
проверка на равенство (= =) и на неравенство (!=).+


Описать класс «Битовая строка» производный от класса «Строка».

(Строки данного класса могут содержать только символы '0' и '1'). Если в основе инициализирующей строки встретятся любые символы, отличные от допустимых, то «Битовая строка» становится пустой. Содержимое строки рассматривается как двоичное представление целого числа со знаковым разрядом. Отрицательные числа хранятся в дополнительном коде.

Методы:

конструктор без параметров;
конструктор, принимающий в качестве параметра C-строку;
конструктор копирования;
оператор присваивания;
деструктор;
изменение знака числа (перевод числа в дополнительный код);
сложение битовых строк (перегрузить операторы + и +=);
проверка на равенство (= =) и на неравенство (!=).

*/
int main()
{
#ifdef ANIMAL
	size_t size = 3;
	Animal** animals = new Animal * [size];
	string line(15, '-');
	animals[0] = new Dog("Sophia");
	animals[1] = new Cat("Lapa");
	animals[2] = new Parrot("Parry");

	for (size_t i = 0; i < size; i++) {
		PrintAnimalInfo(animals[i]);
		cout << line << endl;
	}
	
	for (size_t i = 0; i < size; ++i) {
		delete animals[i];
	}
	delete[] animals;
#endif // ANIMAL

#if defined(STRING) && defined(PART_ONE)

    String s1; 
    String s2("Hello ");
    String s3("World!");

    cout << "s1: " << s1;
    cout << "s2: " << s2;
    cout << "s3: " << s3;

    String s4 = s2 + s3;
    cout << "s4 = s2 + s3: " << s4;

    s2 += s3;
    cout << "s2 += s3: " << s2;

    cout << "s2 == s4: " << (s2 == s4 ? "true" : "false") << endl;
    cout << "s2 != s3: " << (s2 != s3 ? "true" : "false") << endl;


    String s5 = s4;
    cout << "s5 (copy of s4): " << s5;
    s5 = s3;
    cout << "s5 = s3: " << s5;


    s5.Clear();
    cout << "s5 after Clear(): " << s5;


    String s6;
    cout << "Enter sting: ";
    cin >> s6;
    cout << "You entered: " << s6;
    cout << "Len of your string: " << s6.GetSize() << endl;

    cout << "Capacity: " << s6.GetCapacity() << endl;

#endif // STRING and PART_ONE
#if defined(STRING) && defined(BINARY_STRING)

    cout << "=== BinaryString demo ===" << endl;
    BinaryString b1("01101");
    BinaryString b2("00011");

    cout << "b1: " << b1;
    cout << "b2: " << b2;

    BinaryString b3 = b1 + b2;
    cout << "b3 = b1 + b2: " << b3;

    b3.Negate();
    cout << "b3 after Negate(): " << b3;

#endif // STRING and BINARY_STRING
    }



