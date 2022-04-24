#include <iostream>

int main()
{
    float number1{1.3234345456453453353453453453f};                // after 7 digits it prints garbage value
    double number2{1.4454433453453453453453453456463};             // upto 15 digits
    long double number3{1.3453453453453453453455345345345345345L}; // upto 20 digits
    double number5{1.3534e-18};                                    // multiplied by ten to the power eighteen

    std::cout << "sizeof float :" << sizeof(float) << std::endl;
    std::cout << "sizeof double :" << sizeof(double) << std::endl;
    std::cout << "sizeof long double:" << sizeof(long double) << std::endl;

    // how many digits it can show!!

    std::cout << "num1 is :" << number1 << std::endl;
    std::cout << "num2 is :" << number2 << std::endl;
    std::cout << "num3 is :" << number3 << std::endl;
    std::cout << "num5 is :" << number5 << std::endl;

    float number4{1932423423423424234242.0f}; // be aware of narrowing conversions
    // float cant print more than 7 digit so error!
    // if the suphix 'f' is not used at the end than it will be taken as a double
    std::cout << "num4 is :" << number4 << std::endl;

    return 0;
}