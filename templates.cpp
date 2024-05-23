#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

// knuth morris pratt algorithm
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

// depth first search
void dfs(ll v, vector<bool> &visited, Graph &G)
{
    visited[v] = true;
    for (ll u : G[v])
    {
        if (!visited[u])
        {
            dfs(u, visited, G);
        }
    }
}