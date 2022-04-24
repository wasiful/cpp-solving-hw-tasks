#include <iostream>

const int pen{10};
const int marker{20};
const int eraser{30};
const int rectangle{40};
const int circle{50};
const int eclipse{60};

int main()
{
    int tool{circle}; // what ever tool is given here will be activated

    if (tool == pen)
    {
        std::cout << "using pen" << std::endl;
    }
    else if (tool == marker)
    {
        std::cout << "using marker" << std::endl;
    }
    else if (tool == eraser)
    {
        std::cout << "using eraser " << std::endl;
    }
    else if (tool == rectangle)
    {
        std::cout << "using rectangle " << std::endl;
    }
    else if (tool == circle)
    {
        std::cout << "using circle " << std::endl;
    }
    else if (tool == eclipse)
    {
        std::cout << "using eclipse " << std::endl;
    }
    std::cout << "keep painting " << std::endl;
    return 0;
}