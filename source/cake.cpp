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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void build(vector<ll> &a, ll v, ll tl, ll tr, vector<ll> &t)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm, t);
        build(a, v * 2 + 1, tm + 1, tr, t);
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r, vector<ll> &t)
{
    if (l == tl && r == tr)
        return t[v];
    ll tm = (tl + tr) / 2;
    return gcd(query(v * 2, tl, tm, l, min(r, tm), t),
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, t));
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val, vector<ll> &t)
{
    if (tl == tr)
    {
        t[v] -= new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val, t);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val, t);
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<ll> t(4 * n);
    build(a, 1, 0, n - 1, t);

    while (q--)
    {
        char type;
        cin >> type;
        if (type == '?')
        {
            ll l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1, t) << endl;
        }
        else if (type == '!')
        {
            ll pos, val;
            string tutor;
            cin >> tutor >> val >> pos;
            update(1, 0, n - 1, pos - 1, val, t);
        }
    }

    return 0;
}
