
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int minOps(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]}) + 1;
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string s;
    cin >> s;
    cout << minOps(s) << endl;
    // content

    return 0;
}
