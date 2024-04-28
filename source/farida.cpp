
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll farida(vector<ll> &monsters)
{
    vector<pair<ll, ll>> dp(monsters.size());
    dp[0] = {monsters[0], 0};
    for (ll i = 1; i < monsters.size(); i++)
    {
        dp[i].first = dp[i - 1].second + monsters[i];
        dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
    }
    return max(dp.back().first, dp.back().second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll N;
    cin >> N;
    vector<ll> monsters(N);
    for (auto &i : monsters)
    {
        cin >> i;
    }
    cout << farida(monsters) << endl;
    // content

    return 0;
}
