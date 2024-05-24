
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

bool dfs(ll v, vector<bool> &visited, Graph &G)
{
    visited[v] = true;
    for (ll u : G[v])
    {
        if (!visited[u])
        {
            dfs(u, visited, G);
        }
        else
        {
            cout << "recheck hints" << endl;
            return false;
        }
    }
    return true;
}

void indiana(Graph &G)
{
    ll n = G.size();
    vector<ll> in(n, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll j : G[i])
        {
            in[j]++;
        }
    }
    queue<ll> q;
    for (ll i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        cout << v + 1 << " ";
        for (ll u : G[v])
        {
            in[u]--;
            if (in[u] == 0)
            {
                q.push(u);
            }
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;
    rep(i, t)
    {
        bool connected = true;
        ll n, h;
        cin >> n >> h;
        Graph G(n);
        rep(j, h)
        {
            ll a, b;
            cin >> a >> b;
            G[a - 1].push_back(b - 1);
        }
        vector<bool> visited(n, false);
        if (!dfs(0, visited, G))
        {
            continue;
        }
        for (bool v : visited)
        {
            if (!v)
            {
                cout << "missing hints" << endl;
                connected = false;
                break;
            }
        }
        if (connected)
        {
            indiana(G);
        }
    }
    return 0;
}
