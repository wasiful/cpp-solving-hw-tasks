#include <iostream>

// signed,unsigned  (short|2byte  /  long|4byte / long long|8 byte)

int main()
{
    signed int value1{10}; // can take both positive and negative within the 4byte memory range
    signed int value2{-13214};

    std::cout << "value1 :" << value1 << std::endl;
    std::cout << "value2 :" << value2 << std::endl;

    std::cout << "size of v1=" << sizeof(value1) << std::endl;
    std::cout << "size of v2= " << sizeof(value2) << std::endl;

    unsigned int value3{-5 * -5}; // its fine as long the result is positive for unsigned
    std::cout << " v3= " << value3 << std::endl;
    std::cout << "size of v3= " << sizeof(value3) << std::endl;

    // using thesese modifiers we can maintain/restrict the size of memory an integer can take and also amount of integers that can be stored

    return 0;
}