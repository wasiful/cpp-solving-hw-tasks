#include <iostream>

int main()
{

    int num1{2};
    int num2{7};

    int result = num1 + num2;
    std::cout << "addition result " << result << std::endl;

    result = num1 - num2;
    std::cout << "subtraction result " << result << std::endl;

    result = num1 * num2;
    std::cout << "multip result " << result << std::endl;

    result = num2 / num1; // Error cant take frac in int
    std::cout << "devide result " << result << std::endl;

    result = num2 % num1; // modules can do devide correctly and the result is remainder 1
    std::cout << "mod devide remainder result " << result << std::endl;

    return 0;
}