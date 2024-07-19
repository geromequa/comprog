#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, q;
    cin >> n >> q;
    vector<ll> inverters(n);
    rep(i, n)
    {
        cin >> hex >> inverters[i];
    }

    while (q--)
    {
        ll s, r;
        cin >> s >> r;
    }

    return 0;
}
