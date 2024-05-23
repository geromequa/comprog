
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
    // TODO implement topSort
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
        ll n, h;
        cin >> n >> h;
        Graph G(n);
        bool connected = true;
        rep(j, h)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
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
