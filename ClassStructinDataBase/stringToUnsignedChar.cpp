#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;

string BinaryStringToText(string binaryString)
{
    string text = "";
    stringstream sstream(binaryString);
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    return text;
}

int main()
{
    string binaryString = "01101111";
    cout << "Binary string: " << binaryString << "!\n";
    cout << "Result binary string to text: " << BinaryStringToText(binaryString) << "!\n";

    return 0;
}