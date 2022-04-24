#include <iostream>

int main()
{
    int scores[10];

    std::cout << "scores[0] " << scores[0] << std::endl;
    std::cout << "scores[0] " << scores[1] << std::endl;
    for (size_t i{0}; i < 10; ++i)
    {
        std::cout << "scores " << i << scores[i] << std::endl;
    }

    int sco[10];
    sco[0] = 20;
    sco[1] = 29;
    sco[2] = 40;

    for (size_t j{0}; j < 10; ++j)
    {
        std::cout << "sco " << j << "   " << sco[j] << std::endl;
    }

    for (size_t k{0}; k < 10; ++k)
    {
        sco[k] = k * 10;
        std::cout << "sco " << k << "   " << sco[k] << std::endl;
    }

    double salaries[5]{12.7, 7.5, 13.2, 8.1, 9.3};
    for (size_t k{0}; k < 5; ++k)
    {
        std::cout << "sco " << k << "   " << salaries[k] << std::endl;
    }
    // will not be able change if const is there
    const int class_sizes[]{12, 32, 42, 343, 132};

    for (auto value : class_sizes)
    {
        std::cout << "value " << value << std::endl;
    }

    int srs[]{2, 3, 4, 345, 43};
    int sum{0};
    for (int element : srs)
    {
        sum += element;
    }
    std::cout << "sum of all results " << sum << std::endl;

    return 0;
}