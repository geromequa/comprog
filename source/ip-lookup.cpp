
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

struct TrieNode
{
    bool isEndOfWord;
    TrieNode *children[3]; // Fixed size array for binary alphabet
};

TrieNode *getNode()
{
    TrieNode *node = new TrieNode;
    node->isEndOfWord = false;
    // Initialize children to nullptr
    for (int i = 0; i < 3; i++)
        node->children[i] = nullptr;

    return node;
}

void insert(TrieNode *root, string key)
{
    TrieNode *current = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = (key[i] == '*' ? 2 : key[i] - '0');
        if (current->children[2])
        {
            current->isEndOfWord = true;
            return;
        }
        if (!current->children[index])
        {
            current->children[index] = getNode();
        }
        current = current->children[index];
        if (key[i + 1] == '*')
        {
            current->isEndOfWord = true;
        }
    }
    current->isEndOfWord = true;
}

bool search(TrieNode *root, string key)
{
    TrieNode *current = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = (key[i] == '*' ? 2 : key[i] - '0');
        if (current->children[2])
        {
            return true;
        }
        if (!current->children[index])
            return false;
        current = current->children[index];
    }
    return (current != NULL && current->isEndOfWord);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m;
    cin >> n;
    TrieNode *root = getNode();
    rep(i, n)
    {
        string ip;
        cin >> ip;
        insert(root, ip);
    }
    cin >> m;
    rep(i, m)
    {
        string ip;
        cin >> ip;
        cout << (search(root, ip) ? "Yes" : "No") << endl;
    }
    return 0;
}