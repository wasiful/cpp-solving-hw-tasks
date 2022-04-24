#include <bits/stdc++.h>
using namespace std;

class HuffTree
{
public:
    int val;
    char letter;
    HuffTree *left;
    HuffTree *right;

    HuffTree(int val, char c)
    {
        this->val = val;
        this->letter = c;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<pair<int, char>> FrequencyDect(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    // for (auto &t : mp)
    //     std::cout << t.first << " " << t.second << "\n";
    // print to see how mp looks like
    vector<pair<int, char>> v;

    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] != 0)
        {
            v.push_back(make_pair(mp[s[i]], s[i]));
            mp[s[i]] = 0;
        }
    }
    // print how v looks like before return

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    return v;
}

class Compare
{
public:
    bool operator()(HuffTree *a, HuffTree *b)
    {
        if (a->val > b->val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void print(priority_queue<HuffTree *, vector<HuffTree *>, Compare> q)
{
    while (q.size())
    {
        cout << q.top()->letter << " " << q.top()->val << endl;
        q.pop();
    }
}

HuffTree *makeTree(vector<pair<int, char>> &frq)
{
    priority_queue<HuffTree *, vector<HuffTree *>, Compare> q;
    for (int i = 0; i < frq.size(); i++)
    {
        q.push(new HuffTree(frq[i].first, frq[i].second));
    }
    // print(q);
    while (q.size() > 1)
    {
        HuffTree *left = q.top();
        q.pop();
        HuffTree *right = q.top();
        q.pop();

        HuffTree *nd = new HuffTree(left->val + right->val, '~');
        nd->left = left;
        nd->right = right;
        q.push(nd);
    }

    return q.top();
}

void InOrder(HuffTree *tree)
{
    if (tree)
    {
        InOrder(tree->left);
        cout << tree->val << endl;
        InOrder(tree->right);
    }
}

void getValues(HuffTree *root, string s, map<char, string> &vtr)
{

    if (!root)
    {
        return;
    }
    if (root->letter != '~')
    {
        vtr[root->letter] = s;
        return;
    }
    else
    {
        getValues(root->left, s + "0", vtr);
        getValues(root->right, s + "1", vtr);
    }
}

string decode(HuffTree *tree, string s, int &i)
{
    string str = "";
    while (i < s.size())
    {
        if (tree->letter != '~')
        {
            str += tree->letter;
            return str;
        }

        else if (s[i] == '0')
        {
            if (tree->left)
            {
                tree = tree->left;
                i++;
            }
            else
            {
                return str;
            }
        }

        else if (s[i] == '1')
        {
            if (tree->right)
            {
                tree = tree->right;
                i++;
            }
            else
            {
                return str;
            }
        }
    }
    return "";
}

// int main()
// {
//     FrequencyDect("aad");
// }

int main()
{
    string s;
    cin >> s;
    vector<pair<int, char>> frq = FrequencyDect(s);
    sort(frq.begin(), frq.end());
    /*
        for (int i = 0; i < frq.size(); i++)
        {
            cout << frq[i].first << " " << frq[i].second << endl;
        }
        */
    map<char, string> vtr;
    HuffTree *tree = makeTree(frq);
    // InOrder(tree);

    getValues(tree, "", vtr);

    string res = "";
    /*
    for (auto i : vtr)
    {
        cout << i.first << " " << i.second << endl;
         res += i.second;
    }*/

    for (auto i : s)
        res += vtr[i];

    cout << s << endl;
    cout << res << endl;

    string back = "";
    for (int i = 0; i < res.size();)
    {
        back += decode(tree, res, i);
    }
    cout << back << endl;
}