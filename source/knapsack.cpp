
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll knapsack(ll n, ll M, vector<ll> input)
{
    vector<ll> dp(n);
    dp[0] = input[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] + input[i] <= M)
                dp[i] = max(dp[i], dp[j] + input[i]);
        }
    }
    return *max_element(all(dp));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, M;
    cin >> n >> M;
    vector<ll> input(n);
    for (auto &i : input)
    {
        cin >> i;
    }
    cout << knapsack(n, M, input) << endl;
    // content

    return 0;
}
