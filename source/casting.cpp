
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

vector<int> solve(string s)
{
    string tmp = s;
    vector<int> switches;
    rep(i, s.size() - 1)
    {
        if (s[i] == 'B' && s[i] != s[i + 1])
        {
            swap(s[i], s[i + 1]);
            switches.push_back(i + 1);
        }
        else if (s[i] == 'B')
        {
            switches.push_back(i + 1);
            s[i] = 'W';
            s[i + 1] = 'W';
            i++;
        }
    }
    if (s.back() != 'B')
    {
        return switches;
    }
    vector<int> switches2;
    rep(i, tmp.size() - 1)
    {
        if (tmp[i] == 'W' && tmp[i] != tmp[i + 1])
        {
            swap(tmp[i], tmp[i + 1]);
            switches2.push_back(i + 1);
        }
        else if (tmp[i] == 'W')
        {
            switches2.push_back(i + 1);
            tmp[i] = 'B';
            tmp[i + 1] = 'B';
            i++;
        }
    }
    if (tmp.back() != 'W')
    {
        return switches2;
    }

    return {-1};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;
    rep(i, t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> switches = solve(s);
        if (switches.empty())
        {
            cout << "YES" << endl;
            cout << 0 << endl;
            cout << endl;
        }
        else if (switches[0] == -1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << switches.size() << endl;
            for (int i : switches)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        // content
    }
    return 0;
}
