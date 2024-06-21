#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

void buildTree(Graph &g, ll root, map<ll, vector<ll>> &edges, vector<bool> &isLeaf, ll n)
{
    queue<ll> q;
    q.push(root);
    vector<bool> visited(n);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        visited[u] = true;
        if (edges[u].size() > 1 || u == root)
        {
            isLeaf[u] = false;
        }
        for (ll v : edges[u])
        {
            if (!visited[v])
            {
                g[u].push_back(v);
                q.push(v);
            }
        }
    }
}

void dfs(ll v, vector<bool> &visited, Graph &G, vector<ll> &res)
{
    visited[v] = true;
    for (ll u : G[v])
    {
        if (!visited[u])
        {
            dfs(u, visited, G, res);
        }
        res[v] += res[u];
    }
    if (v != 0 && G[v].size() == 0)
    {
        res[v]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;
    Graph g(n);
    map<ll, vector<ll>> edges;
    rep(i, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<bool> isLeaf(n, true);
    buildTree(g, 0, edges, isLeaf, n);
    vector<ll> res(n, 0);
    vector<bool> visited(n);
    dfs(0, visited, g, res);
    ll q;
    cin >> q;
    vector<pair<ll, ll>> problems(q);
    rep(i, q)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << res[x] * res[y] << endl;
    }
    return 0;
}
