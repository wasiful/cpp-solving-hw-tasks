#include <iostream>

int main()
{

    int var1{123}; // this variable was declared
    std::cout << "var1 " << var1 << std::endl;

    var1 = 55; // but then this one assigned at its place
    std::cout << "var1 " << var1 << std::endl;

    std::cout << "--------------------------- " << std::endl;

    bool state{false};
    std::cout << std::boolalpha;
    std::cout << "state " << state << std::endl;

    state = true; // will show both false and true

    std::cout << "state " << state << std::endl;

    std::cout << "--------------------------- " << std::endl;

    auto var3{333u}; // when negative is assigned to positive array garbage value is added autometically
    var3 = -22;

    std::cout << "var3 " << var3 << std::endl;
    return 0;
}