#include <iostream>
// boolean (true or false) takes 8 bits in the memory
int main()
{

    bool red_light{true};
    bool green_light{false};

    if (red_light == true)
    {
        std::cout << "stop" << std::endl;
    }
    else
    {
        std::cout << "keep moving" << std::endl;
    }

    if (green_light)
    {
        std::cout << "the light is green" << std::endl;
    }
    else
    {
        std::cout << "Light not green" << std::endl;
    }

    std::cout << "size of boolean " << sizeof(bool) << std::endl;

    return 0;
}