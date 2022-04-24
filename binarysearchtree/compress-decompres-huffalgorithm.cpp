#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

#define EMPTY_STRING ""

// A Tree node
struct Node
{
    char chletter;
    int frequency;
    Node *left, *right;
};

// Function to allocate a new tree node
Node *getNode(char chletter, int frequency, Node *left, Node *right)
{
    Node *node = new Node();

    node->chletter = chletter;
    node->frequency = frequency;
    node->left = left;
    node->right = right;

    return node;
}

// Comparisonarison object to be used to order the heap
struct Comparison
{
    bool operator()(const Node *l, const Node *r) const
    {
        // the highest priority item has the lowest frequencyuency
        return l->frequency > r->frequency;
    }
};

// Utility function to check if Huffman Tree contains only a single node
bool isLeaf(Node *root)
{
    return root->left == nullptr && root->right == nullptr;
}

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
    {
        return;
    }

    // found a leaf node
    if (isLeaf(root))
    {
        huffmanCode[root->chletter] = (str != EMPTY_STRING) ? str : "1";
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Traverse the Huffman Tree and decode the encoded string
void decode(Node *root, int &index, string str)
{
    if (root == nullptr)
    {
        return;
    }

    // found a leaf node
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

// Builds Huffman Tree and decodes the given input inputLetters
void HuffTree(string inputLetters)
{
    // base case: empty string
    if (inputLetters == EMPTY_STRING)
    {
        return;
    }

    // count the frequencyuency of appearance of each character
    // and store it in a map
    unordered_map<char, int> frequency;
    for (char chletter : inputLetters)
    {
        frequency[chletter]++;
    }

    // Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node *, vector<Node *>, Comparison> pq;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair : frequency)
    {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1)
    {
        // Remove the two nodes of the highest priority
        // (the lowest frequencyuency) from the queue

        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // create a new internal node with these two nodes as children and
        // with a frequencyuency equal to the sum of the two nodes' frequencyuencies.
        // Add the new node to the priority queue.

        int sum = left->frequency + right->frequency;
        pq.push(getNode('\0', sum, left, right));
    }

    // `root` stores pointer to the root of Huffman Tree
    Node *root = pq.top();

    // Traverse the Huffman Tree and store Huffman Codes
    // in a map. Also, print them
    unordered_map<char, string> huffmanCode;
    encode(root, EMPTY_STRING, huffmanCode);

    cout << "Huffman Codes are:\n"
         << endl;
    for (auto pair : huffmanCode)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << "\nThe original string is:\n"
         << inputLetters << endl;

    // Print encoded string
    string str;
    for (char chletter : inputLetters)
    {
        str += huffmanCode[chletter];
    }

    cout << "\nThe encoded string is:\n"
         << str << endl;
    cout << "\nThe decoded string is:\n";

    if (isLeaf(root))
    {
        // Special case: For input like a, aa, aaa, etc.
        while (root->frequency--)
        {
            cout << root->chletter;
        }
    }
    else
    {
        // Traverse the Huffman Tree again and this time,
        // decode the encoded string
        int index = -1;
        while (index < (int)str.size() - 1)
        {
            decode(root, index, str);
        }
    }
}

// Huffman coding algorithm implementation in C++
int main()
{
    string inputLetters = "kolotoc";
    HuffTree(inputLetters);

    return 0;
}