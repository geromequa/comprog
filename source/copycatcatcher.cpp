#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

vector<ll> computePrefix(vector<ll> pattern)
{
    ll m = pattern.size();
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

vector<ll> find(vector<ll> s, vector<ll> p)
{
    vector<ll> longestPrefix = computePrefix(p);
    vector<ll> positions;
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
            positions.push_back(i - p.size());
            j = 0;
            i -= p.size() - 1;
        }
        else if (i < s.size() && p[j] != s[i])
        {
            if (j != 0)
                j = longestPrefix[j - 1];
            else
                i = i + 1;
        }
    }
    return positions;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;
    vector<ll> source;
    vector<ll> source_copy;
    unordered_map<string, ll> keys;
    vector<string> input(n);
    rep(i, n)
    {
        string token;
        cin >> token;
        keys[token] = i;
        input[i] = token;
    }
    ll i = 0;
    for (string &token : input)
    {
        ll key = keys[token];
        if (token.size() == 1 && isalpha(token[0]))
        {
            source_copy.push_back(-1);
            source.push_back(key);
        }
        else
        {
            source_copy.push_back(key);
            source.push_back(key);
        }
    }
    ll q;
    cin >> q;
    ll ii = 5000;
    rep(i, q)
    {
        ll query_length;
        cin >> query_length;
        vector<ll> query;
        vector<ll> query_copy;
        rep(j, query_length)
        {
            string token;
            cin >> token;

            if (keys.find(token) == keys.end())
            {
                keys[token] = ii++;
            }
            ll key = keys[token];
            if (token.size() == 1 && isalpha(token[0]))
            {
                query_copy.push_back(-1);
                query.push_back(key);
            }
            else
            {
                query_copy.push_back(key);
                query.push_back(key);
            }
        }

        vector<ll> starting_points = find(source_copy, query_copy);
        bool found = false;
        for (ll i : starting_points)
        {
            bool b = true;
            unordered_map<ll, ll> m;
            unordered_set<ll> used_vars;
            for (ll tmp = i; tmp < query_length + i; tmp++)
            {
                if (source_copy[tmp] != -1)
                {
                    continue;
                }
                if (m.find(source[tmp]) == m.end())
                {
                    if (used_vars.find(query[tmp - i]) != used_vars.end())
                    {
                        b = false;
                        break;
                    }
                    used_vars.insert(query[tmp - i]);
                    m[source[tmp]] = query[tmp - i];
                }
                if (m[source[tmp]] != query[tmp - i])
                {
                    b = false;
                    break;
                }
            }
            if (b)
            {
                cout << "yes" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "no" << endl;
        }
    }
    return 0;
}