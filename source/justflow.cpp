#include <bits/stdc++.h>
#include <limits.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>; // value is capacity of edge (0 means no edge)

ll bfs(Graph &g, ll s, ll t, vector<ll> &parent, ll n)
{
    queue<ll> q;
    vector<bool> visited(n, false);
    parent[s] = -1;
    visited[s] = true;
    q.push(s);
    ll min_cap = LLONG_MAX;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll i = 0; i < n; i++)
        {
            if (g[u][i] > 0 && !visited[i])
            {
                visited[i] = true;
                parent[i] = u;
                min_cap = min(min_cap, g[u][i]);
                q.push(i);
                if (i == t)
                {
                    return min_cap;
                }
            }
        }
    }
    return 0;
}

ll max_flow(Graph &g, ll s, ll t, ll n)
{
    vector<ll> parent(n);
    Graph residual = g;
    ll flow = 0;
    ll path_flow = 0;
    while (path_flow = bfs(residual, s, t, parent, n))
    {
        for (ll v = t; v != s; v = parent[v])
        {
            ll u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }
        flow += path_flow;
    }
    return flow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;

    Graph g(n, vector<ll>(n, 0));
    rep(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a - 1][b - 1] += c;
        g[b - 1][a - 1] += c;
    }
    cout << max_flow(g, 0, 1, n) << endl;

    return 0;
}