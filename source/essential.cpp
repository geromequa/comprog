#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
const ll INF = 1e9;
using edge = pair<ll, pair<ll, ll>>; // destination, weight, id
using weighted_graph = vector<vector<edge>>;

pair<vector<ll>, vector<vector<ll>>> dijkstra(const weighted_graph &g, ll start)
{
    ll n = g.size();
    vector<ll> dist(n, INF);
    vector<vector<ll>> prev(n);
    dist[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        ll v = pq.top().second;
        ll d_v = pq.top().first;
        pq.pop();

        if (d_v != dist[v])
            continue;

        for (auto edge : g[v])
        {
            ll to = edge.first;
            ll len = edge.second.first;

            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
                prev[to].clear();
                prev[to].push_back(v);
                pq.push(make_pair(dist[to], to));
            }
            else if (dist[v] + len == dist[to])
            {
                prev[to].push_back(v);
            }
        }
    }

    return make_pair(dist, prev);
}

void dfs(ll v, ll start, set<ll> &edge_ids, const vector<vector<ll>> &prev, const weighted_graph &g)
{
    if (v != start)
    {
        for (ll u : prev[v])
        {
            for (auto &e : g[u])
            {
                if (e.first == v)
                {
                    edge_ids.insert(e.second.second);
                }
            }
            dfs(u, start, edge_ids, prev, g);
        }
    }
}

set<ll> get_edge_ids(ll start, ll end, const vector<vector<ll>> &prev, const weighted_graph &g)
{
    set<ll> edge_ids;
    dfs(end, start, edge_ids, prev, g);
    return edge_ids;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;
    weighted_graph g(n);
    rep(i, m)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].push_back(make_pair(v, make_pair(w, i)));
        g[v].push_back(make_pair(u, make_pair(w, i)));
    }
    auto [distances, predecessors] = dijkstra(g, 0);
    set<ll> edge_ids = get_edge_ids(0, 1, predecessors, g);

    cout << edge_ids.size() << endl;
    for (ll id : edge_ids)
    {
        cout << id + 1 << ' ';
    }

    return 0;
}
