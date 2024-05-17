
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

std::string frenzy(const std::string &s, std::unordered_map<char, ll> freq)
{
    std::unordered_set<char> visited;
    std::stack<char> stack;

    // Step 2: Iterate through the characters in the string
    for (char c : s)
    {
        // Decrease the frequency count for the current character
        freq[c]--;

        // If the character is already in the result stack, skip it
        if (visited.find(c) != visited.end())
        {
            continue;
        }

        // Ensure the stack maintains lexicographical order
        while (!stack.empty() && stack.top() < c && freq[stack.top()] > 0)
        {
            visited.erase(stack.top());
            stack.pop();
        }

        // Add the current character to the stack and mark it as visited
        stack.push(c);
        visited.insert(c);
    }

    // The stack now contains the lexicographically largest string
    std::string result;
    while (!stack.empty())
    {
        result = stack.top() + result;
        stack.pop();
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string s;
    cin >> s;
    unordered_map<char, ll> charCount(0);
    for (char &c : s)
    {
        charCount[c]++;
    }
    cout << frenzy(s, charCount) << endl;
    // content

    return 0;
}
