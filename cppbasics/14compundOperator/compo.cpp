#include <iostream>
int main()
{

    int value{45};

    value += 5;
    value -= 15;
    value *= 2;
    value /= 3;

    std::cout
        << "value is " << value << std::endl;

    return 0;
}