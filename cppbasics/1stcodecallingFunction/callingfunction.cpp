#include <iostream>

int addnumber(int first_param, int second_param)
{
    int result = first_param + second_param;

    return result;
}

int main()
{
    int first_number{3};
    int second_number{7};

    std::cout << "First number:" << first_number << std::endl;
    std::cout << "Second number:" << second_number << std::endl;
    int sum = first_number + second_number;
    std::cout << "sum:" << sum << std::endl; // prints 13+7=20

    sum = addnumber(25, 7);
    std::cout << "sum:" << sum << std::endl; // using 1st addnumber function it prints 25+7=32

    return 0;
}