#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, m, k;
    cin >> n >> m >> k;
    ll left = n - k;
    ll right = k;
    ll cost = 0;
    for (ll i = 1; i <= left; i++)
    {
        cost += i;
    }
    ll cost2 = 0;
    for (ll i = 1; i <= right; i++)
    {
        cost2 += i;
    }
    ll difference = abs(left - right) * min(left, right);

    while (cost + cost2 + difference + n > m)
    {
        if (left > right)
        {
            cost -= left;
            left--;
        }
        else
        {
            cost2 -= right;
            right--;
        }
        difference = abs(left - right) * min(left, right);
    }
    ll leftover = m - cost - cost2 - difference - n;
    ll x = 1;
    while (leftover > n)
    {
        leftover -= n;
        x++;
    }
    cout << max(left, right) + x << endl;
    return 0;
}
