#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll v, m;
        cin >> v >> m;   // v = value; m = num coins
        vector<ll> c(m); // coins
        for (ll j = 0; j < m; j++)
            cin >> c[j];
        ll dp_l = v + c[m - 1] * c[m - 1] + 1;
        vector<ll> dp(dp_l, 0);
        // init
        for (ll j = 0; j < m; j++)
            dp[c[j]] = 1;
        // dp step
        for (ll j = 1; j < dp_l; j++)
        {
            if (dp[j] == 1)
                continue;
            ll min_a = dp[j - 1] + 1;
            for (ll l = 1; l < m; l++)
            {
                if (c[l] > j)
                    break;
                min_a = dp[j - c[l]] + 1 < min_a ? dp[j - c[l]] + 1 : min_a;
            }
            dp[j] = min_a;
        }
        // change
        for (ll j = v; j < dp_l; j++)
        {
            if (dp[j] + dp[j - v] < dp[v])
                dp[v] = dp[j] + dp[j - v];
        }
        cout << dp[v] << endl;
    }
    cout.flush();
    return 0;
}