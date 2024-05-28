
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

void party(Graph &G, ll node, vector<pair<ll, ll>> &dp)
{
    if (G[node].empty())
    {
        return;
    }
    for (auto i : G[node])
        party(G, i, dp);
    for (auto i : G[node])
    {
        dp[node].first += dp[i].second;
        dp[node].second += max(dp[i].first, dp[i].second);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;

    Graph G(n);
    vector<pair<ll, ll>> dp(n, {0, 0});
    for (auto &[a, b] : dp)
    {
        cin >> a;
    }
    rep(i, n - 1)
    {
        ll a;
        cin >> a;
        G[a - 1].push_back(i + 1);
    }

    party(G, 0, dp);
    cout << max(dp[0].first, dp[0].second) << endl;

    return 0;
}
