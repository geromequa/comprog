
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

vector<ll> vladimir(vector<ll> a)
{
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll k, c;
    cin >> k >> c;
    vector<ll> a(k);
    for (ll &x : a)
        cin >> x;
    vector<ll> res = vladimir(a);
    for (ll x : res)
        cout << x << ' ';
    cout << k << endl;
    return 0;
}