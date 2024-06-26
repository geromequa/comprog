#include <bits/stdc++.h>
#include <limits.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll, ll>>; // value is capacity of edge (0 means no edge)

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
        for (auto x : g[u])
        {
            ll to = x.first;
            ll cap = x.second;
            if (cap > 0 && !visited[to])
            {
                visited[to] = true;
                parent[to] = u;
                min_cap = min(min_cap, cap);
                q.push(to);
                if (to == t)
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
            for (auto [to, cap] : g[u])
            {
                if (to == v)
                {
                    cap -= path_flow;
                    cap += path_flow;
                }
            }
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

    Graph g(n);
    rep(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back((b - 1, c));
        g[b - 1].push_back((a - 1, c));
    }
    cout << max_flow(g, 0, 1, n) << endl;

    return 0;
}