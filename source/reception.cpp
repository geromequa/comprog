
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> p(n), c(n), dp(n, 1e18);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        dp[i] = c[i];
        ll total = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            total += p[i] - p[j];
            dp[i] = min(dp[i], dp[j] + c[i] + total);
            dp[j] = min(dp[j], dp[i]);
        }
    }
    cout << *min_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
