#include <iostream>
int main()
{

    short int var1{10};
    short int var2{20};

    char var3{40};
    char var4{50};

    auto result1 = var1 + var2;
    auto result2 = var3 + var4;

    std::cout << "size of 1r " << sizeof(result1) << std::endl;
    std::cout << "size of 2r " << sizeof(result2) << std::endl;

    return 0;
}