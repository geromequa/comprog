
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, u;
    cin >> n >> u;
    vector<ll> p(n);
    for (auto &i : p)
        cin >> i;
    sort(all(p), greater<>());
    ll sum = 0;
    ll i;
    ll rem = 0;
    rep(i, n)
    {
        rem += p[i] - u;
        if (rem < 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
