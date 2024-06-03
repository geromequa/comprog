#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
using weighted_graph = vector<vector<P>>;

struct UnionFind
{
    vector<ll> par, siz;
    UnionFind(ll n) : par(n), siz(n, 1)
    {
        rep(i, n) par[i] = i;
    }

    ll root(ll x)
    {
        if (par[x] == x)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool unite(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }

    ll size(ll x)
    {
        return siz[root(x)];
    }
};

auto comp = [](const tuple<ll, ll, ll> &a, const tuple<ll, ll, ll> &b)
{
    return get<2>(a) > get<2>(b);
};

ll icecream(priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, decltype(&comp)> q, ll n)
{
    ll cost = 0;
    UnionFind uf(n + 1);
    while (uf.size(0) != n + 1)
    {
        auto [a, b, p] = q.top();
        q.pop();
        if (uf.same(a, b))
        {
            continue;
        }
        uf.unite(a, b);
        cost += p;
    }
    return cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m;
    cin >> n >> m;

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, decltype(comp)> q(comp);
    rep(i, n)
    {
        ll a;
        cin >> a;
        q.push(make_tuple(i, n, a));
    }
    rep(i, m)
    {
        ll a, b, p;
        cin >> a >> b >> p;
        q.push(make_tuple(a, b, p));
    }
    cout << icecream(q, n) << endl;

    return 0;
}
