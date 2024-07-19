#include <bits/stdc++.h>
#include <limits.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<ll>>;
using weighted_graph = vector<vector<ll, ll>>; // pair of to and len
const ll INF = LLONG_MAX;

struct point // for geometry
{
    ll x;
    ll y;
    point operator-(const point &other) const
    {
        return point{x - other.x, y - other.y};
    };
    point operator+(const point &other) const
    {
        return point{x + other.x, y + other.y};
    }
    point operator*(const ll scale)
    {
        return point{scale * x, scale * y};
    }
    bool operator==(const point &other) const
    {
        return x == other.x && y == other.y;
    }
    // dot product = cos(alpha) unit
    ll operator*(const point &other) const
    {
        return x * other.x + y * other.y;
    }
    // cross product = sin(alpha) unit
    ll operator%(const point &other) const
    {
        return x * other.y - y * other.x;
    }
    bool operator<(const point &other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

// Sorting Points via x or y coordinate
// vector<point> x_sorted, y_sorted;
// sort(x_sorted.begin(), x_sorted.end(), [](const point &a, const point &b) {return a.x < b.x;});
// sort(y_sorted.begin(), y_sorted.end(), [](const point &a, const point &b) {return a.y < b.y;});

ll squared_len(const point &a)
{
    return a.x * a.x + a.y * a.y;
}

ll squared_dist(const point &a, const point &b)
{
    return squared_len(a - b);
}

ll squared_min_dist(vector<point> &x_sorted, vector<point> &y_sorted)
{
    if (x_sorted.size() <= 4)
    {
        ll min_dist = numeric_limits<ll>::max();
        for (int i = 0; i < x_sorted.size(); i++)
        {
            for (int j = i + 1; j < x_sorted.size(); j++)
            {
                min_dist = min(min_dist, squared_dist(x_sorted[i], x_sorted[j]));
            }
        }
        return min_dist;
    }
    vector<point> l, r, ly, ry;
    ll mid = x_sorted.size() / 2;
    for (int i = 0; i < mid; i++)
        l.push_back(x_sorted[i]);
    for (int i = mid; i < x_sorted.size(); i++)
        r.push_back(x_sorted[i]);
    for (auto p : y_sorted)
    {
        if (p.x <= l.back().x)
            ly.push_back(p);
        else
            ry.push_back(p);
    }
    ll min_dist = min(squared_min_dist(l, ly), squared_min_dist(r, ry));
    ll mid_x = x_sorted[mid].x;
    vector<point> strip;
    for (auto p : y_sorted)
    {
        if (mid_x - min_dist <= p.x && p.x <= mid_x + min_dist)
        {
            strip.push_back(p);
        }
    }
    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < min(i + 16, (int)strip.size()); j++)
        {
            min_dist = min(min_dist, squared_dist(strip[i], strip[j]));
        }
    }
    return min_dist;
}

double distanceFromLineSegment(point s, point e, point p)
{ // start of line, end of line, point
    // Calculate coefficients A, B, C of the line equation Ax + By + C = 0
    double A = e.y - s.y;
    double B = s.x - e.x;
    double C = e.x * s.y - s.x * e.y;
    // Calculate the distance from the point to the line
    double distance = std::abs(A * p.x + B * p.y + C) / std::sqrt(A * A + B * B);
    return distance;
}

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

// Union find data structure
struct DisjointSet
{
    vector<int> parent;
    vector<int> size;

    DisjointSet(int maxSize)
    {
        parent.resize(maxSize);
        size.resize(maxSize);
        rep(i, maxSize)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int v)
    {
        if (v == parent[v])
        {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int get_size(int v)
    {
        return size[v];
    }
};