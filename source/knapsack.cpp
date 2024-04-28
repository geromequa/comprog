
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll knapsack(ll n, ll M, vector<int> &input)
{
    vector<ll> dp(n, 0);

    for (ll i = 0; i < n; i++)
    {
        dp[i] = input[i];
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = i - 1; j >= 0; j--)
        {
            if (input[i] + dp[j] <= M)
            {
                dp[i] = max(dp[i], input[i] + dp[j]);
            }
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
    vector<int> input(n);
    for (auto &x : input)
    {
        cin >> x;
    }
    cout << knapsack(n, M, input) << endl;
    // content

    return 0;
}

// ll knapsack(ll n, ll M, vector<ll> &input)
//{
//     sort(all(input));
//     ll sum = 0;
//     ll it = 0;
//     bool x = false;
//     bool y = false;
//     while (it < n)
//     {
//         if ((x && input[it] == 1) || input[it] == 2)
//         {
//             y = true;
//         }
//         else if (input[it] == 1)
//         {
//             x = true;
//         }
//
//         if (sum + input[it] <= M)
//         {
//             sum += input[it];
//             it++;
//         }
//         else if (M == (sum + 1))
//         {
//             if (input[it] == 2 && x)
//             {
//                 it++;
//                 sum++;
//                 break;
//             }
//             else if (input[it] == 3 && y)
//             {
//                 it++;
//                 sum++;
//                 break;
//             }
//             break;
//         }
//         else if ((M == sum + 2) && input[it] == 3)
//         {
//             if (x)
//             {
//                 it++;
//                 sum += 2;
//                 break;
//             }
//             else if (y)
//             {
//                 it++;
//                 sum += 1;
//                 break;
//             }
//             break;
//         }
//         else
//             break;
//     }
//     return sum;
// }