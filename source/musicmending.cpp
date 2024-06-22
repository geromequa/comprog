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

    ll n;
    cin >> n;
    ll start = 0;

    vector<ll> x;
    rep(i, n)
    {
        ll t;
        cin >> t;
        x.push_back(t - i);
    }
    sort(all(x));
    start = x[n / 2];
    ll cost = 0;
    rep(i, n)
    {
        cost += abs(start - x[i]);
    }
    cout << cost << endl;

    return 0;
}