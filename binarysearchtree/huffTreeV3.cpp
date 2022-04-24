#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

#define EMPTY_STRING ""

struct Node
{
    char chletter;
    int frequency;
    Node *left, *right;
};

Node *getNode(char chletter, int frequency, Node *left, Node *right)
{
    Node *node = new Node();

    node->chletter = chletter;
    node->frequency = frequency;
    node->left = left;
    node->right = right;

    return node;
}

struct Comparison
{
    bool operator()(const Node *l, const Node *r) const
    {

        return l->frequency > r->frequency;
    }
};

bool isLeaf(Node *root)
{
    return root->left == nullptr && root->right == nullptr;
}

void encode(Node *root, string str, unordered_map<char, string> &hufCod)
{
    if (root == nullptr)
    {
        return;
    }

    if (isLeaf(root))
    {
        hufCod[root->chletter] = (str != EMPTY_STRING) ? str : "1";
    }

    encode(root->left, str + "0", hufCod);
    encode(root->right, str + "1", hufCod);
}

void decode(Node *root, int &index, string str)
{
    if (root == nullptr)
    {
        return;
    }

    if (isLeaf(root))
    {
        cout << root->chletter;
        return;
    }

    index++;

    if (str[index] == '0')
    {
        decode(root->left, index, str);
    }
    else
    {
        decode(root->right, index, str);
    }
}

void HuffTree(string inputLetters)
{

    if (inputLetters == EMPTY_STRING)
    {
        return;
    }

    unordered_map<char, int> frequency;
    for (char chletter : inputLetters)
    {
        frequency[chletter]++;
    }

    priority_queue<Node *, vector<Node *>, Comparison> pquee;

    for (auto pair : frequency)
    {
        pquee.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pquee.size() != 1)
    {

        Node *left = pquee.top();
        pquee.pop();
        Node *right = pquee.top();
        pquee.pop();

        int sum = left->frequency + right->frequency;
        pquee.push(getNode('\0', sum, left, right));
    }

    Node *root = pquee.top();

    unordered_map<char, string> hufCod;
    encode(root, EMPTY_STRING, hufCod);

    cout << "Huffman Codes are:\n"
         << endl;
    for (auto pair : hufCod)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << "\nThe original string is:\n"
         << inputLetters << endl;

    string str;
    for (char chletter : inputLetters)
    {
        str += hufCod[chletter];
    }

    cout << "\nThe encoded string is:\n"
         << str << endl;
    cout << "\nThe decoded string is:\n";

    if (isLeaf(root))
    {
        while (root->frequency--)
        {
            cout << root->chletter;
        }
    }
    else
    {
        int index = -1;
        while (index < (int)str.size() - 1)
        {
            decode(root, index, str);
        }
    }
}

int main()
{
    string inputLetters = "kolotoc";
    HuffTree(inputLetters);

    return 0;
}