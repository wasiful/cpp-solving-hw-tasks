#include <iostream>

int main()
{

    int num1{2};
    int num2{7};
    int num3{4};
    int num4{6};
    int num5{8};
    int num6{12};
    int num7{3};

    // addition and subtraction has left to right associativity
    // check operation associativity in wiki
    // or use brackets
    int result = num1 + num2 * num3 - num4 / num5 - num6 + num7;
    std::cout << " result " << result << std::endl;

    result = num1 + (num2 * num3) - (num4 / num5) - num6 + num7;
    std::cout << " result braced" << result << std::endl;

    return 0;
}