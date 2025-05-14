#include "BitString.h"

BinaryString::BinaryString(const char* str_user) : String() {
    if (!str_user || !IsValidBinary(str_user)) {
        SetStr("");
        return;
    }

       SetStr(str_user);  
}


BinaryString::~BinaryString() {
    cout << "Bin destr" << endl;
}



void BinaryString::Negate() {
    if (!str || GetSize() == 0) return;
    for (size_t i = 1; i < GetSize(); ++i) {
        str[i] = (str[i] == '0') ? '1' : '0';
    }
    for (int i = (int)GetSize() - 1; i > 0; --i) {
        if (str[i] == '0') {
            str[i] = '1';
            break;
        }
        else {
            str[i] = '0';
        }
    }
    str[0] = (str[0] == '0') ? '1' : '0';
}

bool BinaryString::IsValidBinary(const char* s)
{
    if (!s) return false;
    for (size_t i = 0; s[i]; ++i) {
        if (s[i] != '0' && s[i] != '1') return false;
    }
    return true;
}

int BinaryString::ToInt() const
{
    if (!str || GetSize() == 0) return 0;
    int res = 0;
    bool negative = (str[0] == '1');
    for (size_t i = 1; i < GetSize(); ++i) {
        res = (res << 1) | (str[i] - '0');
    }
    if (negative) {
        int mask = (1 << (GetSize() - 1)) - 1;
        res = (~res & mask) + 1;
        res = -res;
    }
    return res;
}

char* BinaryString::IntToBinary(int value, size_t width)
{
    if (width == 0) width = 1;
    if (width > 64) width = 64;
    char* buffer = new char[width + 1];
    buffer[width] = '\0';
    unsigned int absval = (value < 0) ? -value : value;
    for (int i = (int)width - 1; i >= 1; --i) {
        buffer[i] = (absval & 1) ? '1' : '0';
        absval >>= 1;
    }
    buffer[0] = (value < 0) ? '1' : '0';
    return buffer;
}
