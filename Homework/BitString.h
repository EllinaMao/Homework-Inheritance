#pragma once
#include "String.h"
#ifndef BINARY_STRING
#define BINARY_STRING

#pragma once
#include "String.h"

class BinaryString : public String {
private:
    static bool IsValidBinary(const char* s);

    int ToInt() const;

    static char* IntToBinary(int value, size_t width);

public:

    BinaryString() : String() {}


    explicit BinaryString(const char* str_user);


    BinaryString(const BinaryString& other) :String(other) {}

    ~BinaryString() override;


    void Negate();

    BinaryString& operator=(const BinaryString& other) {
        if (this != &other) {
            String::operator=(other);
        }
        return *this;
    }

    friend BinaryString operator+(const BinaryString& left, const BinaryString& right) {
        int a = left.ToInt();
        int b = right.ToInt();
        int sum = a + b;
        char* bin = IntToBinary(sum, std::max(left.GetSize(), right.GetSize()));
        BinaryString result(bin); 

        return result;
    }



    BinaryString& operator+=(const BinaryString& other) {
        *this = *this + other;
        return *this;
    }

    friend bool operator==(const BinaryString& left, const BinaryString& right) {
        if (!left.str || !right.str) return false;
        return strcmp(left.str, right.str) == 0;
    }

    friend bool operator!=(const BinaryString& left, const BinaryString& right) {
        return !(left == right);
    }

};


#endif // !BINARY_STRING