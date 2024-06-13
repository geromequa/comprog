#include <bits/stdc++.h>
#include <math.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
using weighted_graph = vector<vector<ll, ll>>;
const ll INF = 1e9;

vector<ll> dijkstra(const weighted_graph &g, ll start)
{
    ll n = g.size();
    vector<ll> dist(n, INF);
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

        for (auto [to, len] : g[v])
        {
            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
                pq.push(make_pair(dist[to], to));
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n;

    vector<pair<ll, ll>> input(n);
    rep(i, n)
    {
        ll d, c;
        cin >> d >> c;
        input[i] = make_pair(d, c);
    }
    weighted_graph g(n);
    cin >> m;
    rep(i, m)
    {
        ll a, b, weight;
        cin >> a >> b;
        weight = pow(abs(input[a - 1].first - input[b - 1].first), 2) + pow(abs(input[a - 1].second - input[b - 1].second), 2);
        g.emplace_back(a - 1, b - 1, weight);
        g.emplace_back(b - 1, a - 1, weight);
    }
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i, n)
    {
        dist[i] = dijkstra(g, i);
    }
    ll q;
    cin >> q;
    rep(i, q)
    {
        ll a, b;
        cin >> a >> b;
        if (dist[a - 1][b - 1] == INF)
        {
            cout << "BRIBE DM WITH FOOD" << endl;
        }
        else
        {
            cout << dist[a - 1][b - 1] << endl;
        }
    }
    return 0;
}
