#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

void dfs(ll v, Graph &g, vector<bool> &visited, ll &counter)
{
    visited[v] = true;
    counter++;
    for (ll u : g[v])
    {
        if (!visited[u])
        {
            dfs(u, g, visited, counter);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;

    Graph g(n);
    rep(k, m)
    {
        ll i, j;
        cin >> i >> j;
        i--;
        j--;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    vector<bool> visited(n);
    ll max_counter = 0;
    ll counter = 0;
    rep(i, n)
    {
        if (!visited[i])
        {
            dfs(i, g, visited, counter);
            max_counter = max(max_counter, counter);
            counter = 0;
        }
    }
    cout << max_counter << endl;

    return 0;
}