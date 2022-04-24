
#include <iostream>
#include <vector>

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input.at(i) << ' ';
    }
}

int main()
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    print(input);

    return 0;
}