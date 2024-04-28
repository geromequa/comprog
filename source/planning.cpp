
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

vector<ll> calculateLongestSequence(vector<ll> &contests, int n)
{
    vector<ll> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (contests[j] < contests[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}

ll planning(vector<ll> &contests, int n)
{
    vector<ll> asc = calculateLongestSequence(contests, n);
    reverse(contests.begin(), contests.end());
    vector<ll> desc = calculateLongestSequence(contests, n);
    ll m = 0;
    for (int i = 0; i < n; i++)
    {
        m = max(m, asc[i] + desc[n - i] - 1);
    }
    return m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;
    vector<ll> contests(n);
    for (auto &i : contests)
    {
        cin >> i;
    }
    cout << planning(contests, n) << endl;

    return 0;
}
