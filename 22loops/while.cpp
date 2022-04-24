#include <iostream>

int main()
{

    const size_t count{10};
    size_t i{0};

    while (i < count)
    {
        std::cout << i << " write C 10 times " << std::endl;
        ++i; // increment outside condition
    }

    size_t j{9};

    do // it runs before testing condition
    {
        std::cout << j << " do while loop " << std::endl;
        ++j; // increment outside condition
    } while (j < count);

    return 0;
}