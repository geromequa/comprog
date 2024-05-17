#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

vector<ll> computePrefix(string pattern)
{
    ll m = pattern.length();
    vector<ll> longestPrefix(m);
    ll len = 0;
    ll i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            longestPrefix[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = longestPrefix[len - 1];
            }
            else
            {
                longestPrefix[i] = 0;
                i++;
            }
        }
    }
    return longestPrefix;
}

bool find(string s, string p)
{
    vector<ll> longestPrefix = computePrefix(p);
    ll i = 0; // index for s
    ll j = 0; // index for p
    while (i < s.size())
    {
        if (p[j] == s[i])
        {
            j++;
            i++;
        }
        if (j == p.size())
        {
            return true;
        }
        else if (i < s.size() && p[j] != s[i])
        {
            if (j != 0)
                j = longestPrefix[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;
    string s, t;
    rep(i, n)
    {
        char c;
        cin >> c;
        s.push_back(c);
    }
    rep(i, m)
    {
        char c;
        cin >> c;
        t.push_back(c);
    }
    if (n > m)
    {
        s = s + s;
        while (t.size() <= s.size())
        {
            t = t + t;
        }
        if (find(t, s))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    else
    {
        t = t + t;
        while (s.size() <= t.size())
        {
            s = s + s;
        }
        if (find(s, t))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
