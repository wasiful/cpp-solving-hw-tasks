#include <iostream>
#include <string>
#include <bitset>
#include <stdio.h>

using namespace std;

char strToChar(const char *str)
{
    char parsed = 0;
    for (int i = 0; i < 8; i++)
    {
        if (str[i] == '1')
        {
            parsed |= 1 << (7 - i);
        }
    }
    return parsed;
}

int main()
{
    char letter = ' ', playAgain = 'Y';
    string word = " ";

    cout << "\t**Binary To Text Convertor 1.0**\n\n";

    while (playAgain == 'Y')
    {

        cout << "Please Enter A Binary Number: ";

        getline(cin, word, '\n');

        cout << "\nThe String Value For '" << word << "' Is \n";

        for (unsigned int wordPosition = 0; wordPosition < word.size(); ++wordPosition)
        {

            letter = word[wordPosition];

            bitset<8> binary(letter);

            cout << binary;
        }
        cout << "\n\nWould You Like To Convert Any Another Binary Number? (Y/N)";

        cin >> playAgain;

        if (playAgain != 'Y')
        {
            cout << "\n\nExiting program.";
            playAgain = 'N';
        }
        cin.ignore();
    }

    return 0;
}
