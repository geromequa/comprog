
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
    sort(all(p), [](ll a, ll b)
         { return b < a; });
    ll sum = 0;
    ll i;
    for (i = 0; i <= n; i++)
    {
        if (n == 1)
        {
            return (u > n) ? 0 : 1;
        }
        if (!i)
            continue;
        if ((sum + p[i - 1]) >= u * i)
        {
            sum += p[i - 1];
        }
        else
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << i << endl;

    return 0;
}
