#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int idata)
{
    struct Node *inner_node = new struct Node;
    inner_node->data = idata;
    inner_node->left = NULL;
    inner_node->right = NULL;
    return inner_node;
}

int main()
{
    struct Node *root = newNode(00000);
    root->left = newNode(0011100101);
    root->right = newNode(00001101);
    cout << root->left->data;
    return 0;
}