
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int checkStringBalance(vector<pair<int, int>> &asc, vector<pair<int, int>> &desc)
{
    sort(asc.begin(), asc.end());

    sort(desc.rbegin(), desc.rend(), [](pair<int, int> a, pair<int, int> b)
         { return a.first + a.second < b.first + b.second; });
    int y = 0;
    int x = 0;
    rep(i, asc.size())
    {
        if (y - asc[i].first < 0)
            return 0;
        y += asc[i].second;
    }
    rep(i, desc.size())
    {
        if (y - desc[i].first < 0)
            return 0;
        y += desc[i].second;
    }
    return y + x == 0;
}
pair<int, int> parseString(string &s)
{
    int lowest = 0;
    int current = 0;
    rep(c, s.size())
    {
        if (s[c] == ')')
        {
            current--;
            lowest = min(lowest, current);
        }
        else if (s[c] == '(')
        {
            current++;
        };
    }
    return make_pair(abs(lowest), current);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;
    string s;
    vector<string> strings;
    vector<pair<int, int>> asc;
    vector<pair<int, int>> desc;

    rep(i, t)
    {
        pair<int, int> current;
        cin >> s;
        strings.push_back(s);
        current = parseString(s);
        (current.second >= 0) ? asc.push_back(current) : desc.push_back(current);
    }
    cout << (checkStringBalance(asc, desc) ? "YES" : "NO") << endl;
    return 0;
}