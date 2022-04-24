#include <iostream>

int main()
{
    // size_t is for Unsigned int representation which can only show positive numbers

    for (unsigned int i{0}; i < 16; ++i)
    {
        std::cout << i << " write C 10 times " << std::endl;
    }

    for (size_t i{0}; i < 5; ++i)
    {
        std::cout << i << " write using size_t " << std::endl;
    }

    size_t j{0};
    const size_t compareCount{10};
    for (; j < compareCount; ++j)
    {
        std::cout << j << " write using j out side " << std::endl;
    }

    std::cout << j << " J outside, no j in first condition and compare count instead of traditional limit and j can be used outside condition " << std::endl;

    return 0;
}