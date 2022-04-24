#include <iostream>

int main()
{

    char character1{'a'};
    char character2{'b'};

    std::cout << character1 << std::endl;
    std::cout << character2 << std::endl;

    // 127 chars one byte in memory 2^8=256 different values
    char value = 65; // ascii of A
    std::cout << "value " << value << std::endl;

    std::cout << "value: " << value << std::endl;
    std::cout << "value(int):" << static_cast<int>(value) << std::endl;

    return 0;
}