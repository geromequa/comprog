
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll numArrangements(ll n, ll p)
{
    vector<vector<ll>> dp(n + 1, vector<ll>(p + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            dp[i][j] = (dp[i - 1][j - 1] + j * dp[i - 1][j]);
        }
    }

    return dp[n][p] % 998244353;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;
    rep(i, t)
    {
        ll n, p;
        cin >> n >> p;
        cout << numArrangements(n, p) << endl;
    }
    // content

    return 0;
}
