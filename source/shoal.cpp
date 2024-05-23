
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

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

bool shoal(Graph &G, ll n)
{
    vector<bool> visited(n, false);
    dfs(0, visited, G);
    for (bool v : visited)
    {
        if (!v)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << (shoal(G, n) ? "YES" : "NO") << endl;
    return 0;
}
