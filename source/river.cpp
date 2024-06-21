#include <bits/stdc++.h>
#include <limits.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>; // value is capacity of edge (0 means no edge)
const ll INF = LLONG_MAX;

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

    ll w, l;
    cin >> w >> l;

    Graph g(w * 2, vector<ll>(w * 2, 0)); // even nodes are start and odd nodes are end vertices for given vertex
    for (ll i = 0; i < (w - 1) * 2; i += 2)
    {
        ll cap;
        cin >> cap;
        g[i][i + 1] = cap;
    }
    g[0][1] = 100;
    g[w * 2 - 2][w * 2 - 1] = 100;
    for (ll i = 1; i < (w - 1) * 2; i += 2)
    {
        for (ll j = i + 1; j < min((i + l * 2), w * 2 - 1); j += 2)
        {
            g[i][j] = 100;
        }
    }
    cout << max_flow(g, 0, w * 2 - 1, w * 2) << endl;

    return 0;
}