#include <iostream>

int main()
{
    int value{5};
    value = value + 1;
    std::cout << value << std::endl;

    value = value - 1;
    std::cout << value << std::endl;

    std::cout << value++ << std::endl;
    std::cout << value++ << std::endl;
    std::cout << value++ << std::endl;

    --value;
    std::cout << value << std::endl;
    return 0;
}
