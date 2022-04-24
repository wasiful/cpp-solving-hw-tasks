#include <iostream>
int main()
{

    int num1{40};
    int num2{45};

    std::cout << "value is " << num1 << std::endl;
    std::cout << "value is " << num2 << std::endl;

    std::cout << std::boolalpha;
    /* (!= == <= >= )*/
    std::cout << "comparing 1 and 2 " << (num1 < num1) << std::endl; // error dont miss out the bracket or operator mistake
    // result is false means 45 is not less than 40

    bool result = (num1 != num2);
    std::cout << num1 << "and " << num2 << " not equal " << result << std::endl;
    return 0;
}