#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

ll multiply(ll a, ll b)
{
    if (b == 1)
        return a;

    ll res = multiply(a + a, b / 2);
    if (b % 2 == 1)
        res += a;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll s;
    cin >> s;
    rep(i, s)
    {
        ll w, h, p;
        cin >> w >> h >> p;
        Graph g(w, vector<ll>(h, 0));
        rep(j, p)
        {
            ll x, y;
            cin >> x >> y;
        }
    }

    return 0;
}
