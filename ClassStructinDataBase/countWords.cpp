#include <iostream>
#include <vector>
#include <utility>

void freq1(std::istream &, size_t top)
{
    std::vector<std::pair<std::string, unsigned>> wordsFreq;
    while (is >> str)
    {
        std::find_if(wordsFreq)
    }
}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cout << "pass file" << stf::endl;
        return 1;
    }
    std::ifstream ifs(argv[1]);
    if (!ifs)
    {
        std::cout << "cant open" << std::endl;
        return 2;
    }
}