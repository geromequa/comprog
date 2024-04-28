
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll minCoins(ll debt, vector<ll> &coins)
{
    ll MAX = 11;
    ll coinSum = 0;
    for (auto &coin : coins)
        coinSum += coin;
    vector<ll> dp(2 * coinSum + 1, MAX);
    dp[debt] = 0;

    for (int coin : coins)
    {

        for (ll i = coin - 1; i <= 2 * coinSum; i++)
        {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        for (ll i = 0; i <= 2 * coinSum - coin; i++)
        {
            dp[i] = min(dp[i], dp[i + coin] + 1);
        }
    }

    return dp[coinSum + debt];
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
        ll X, C;
        cin >> X >> C;
        vector<ll> input(C);
        for (auto &i : input)
        {
            cin >> i;
        }
        cout << minCoins(X, input) << endl;
    }
    // content

    return 0;
}
