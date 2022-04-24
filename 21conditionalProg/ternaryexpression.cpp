#include <iostream>

int main() // instead of using if else we use this
{
    int max{};
    int min{};

    int a{34};
    int b{200};

    max = (b < a) ? a : b;
    min = (b > a) ? a : b;

    std::cout << "max " << max << std::endl;
    std::cout << "min " << min << std::endl;

    return 0;
}