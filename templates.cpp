#include <bits/stdc++.h>
#include <limits.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
using weighted_graph = vector<vector<ll, ll>>; // pair of to and len
const ll INF = LLONG_MAX;

// knuth morris pratt algorithm
vector<ll> computePrefix(string pattern)
{
    ll m = pattern.length();
    vector<ll> longestPrefix(m);
    ll len = 0;
    ll i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            longestPrefix[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = longestPrefix[len - 1];
            }
            else
            {
                longestPrefix[i] = 0;
                i++;
            }
        }
    }
    return longestPrefix;
}

bool find(string s, string p)
{
    vector<ll> longestPrefix = computePrefix(p);
    ll i = 0; // index for s
    ll j = 0; // index for p
    while (i < s.size())
    {
        if (p[j] == s[i])
        {
            j++;
            i++;
        }
        if (j == p.size())
        {
            return true;
        }
        else if (i < s.size() && p[j] != s[i])
        {
            if (j != 0)
                j = longestPrefix[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}

// depth first search
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

void floyd_warshall(vector<vector<ll>> &g, ll n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

void bellman_ford(vector<ll, ll> &edges, vector<ll> &weights, ll s, ll n)
{
    vector<ll> dist(n, INF);
    vector<ll> pre(n, -1);
    dist[s] = 0;
    rep(i, n - 1)
    {
        bool change = false;
        ll j = 0;
        for (auto [a, b] : edges)
        {
            if (dist[b] > dist[a] + weights[j])
            {
                dist[b] = dist[a] + weights[j];
                pre[b] = a;
                change = true;
            }
            j++;
        }
        if (!change)
            break;
    }
}

pair<vector<ll>, vector<ll>> dijkstra(const weighted_graph &g, ll start)
{
    ll n = g.size();
    vector<ll> dist(n, INF);
    vector<ll> prev(n, -1);
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
            ll len = edge.second;

            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
                prev[to] = v;
                pq.push(make_pair(dist[to], to));
            }
        }
    }

    return make_pair(dist, prev);
}