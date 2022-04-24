#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    ifstream file1;
    ofstream file2;
    file1.open("/home/wasif/Downloads/sample/tests/test0.huf", ifstream::binary);
    file2.open("/home/wasif/Downloads/sample/tests/writedata.txt", ofstream::binary);
    long size;
    file1.seekg(0, ifstream::end);
    size = file1.tellg();
    file1.seekg(0);
    char *a;
    a = new char[size];
    file1.read(a, size);
    for (int i = 0; i < size; i++)
    {
        bitset<8> binarya(a[i]);
        file2.write(&binarya.to_string<char, char_traits<char>, allocator<char>>()[i], size);
    }
    system("pause");
    return 0;
}
