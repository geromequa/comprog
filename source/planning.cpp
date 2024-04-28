
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

ll planning(vector<ll> &contests, int n)
{
    vector<ll> backward(n, 1);
    vector<ll> forward(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (contests[j] < contests[i])
            {
                forward[i] = max(forward[i], forward[j] + 1);
            }
            if (contests[n - j - 1] < contests[n - i - 1])
            {
                backward[n - i - 1] = max(backward[n - i - 1], backward[n - j - 1] + 1);
            }
        }
    }

    ll m = 0;
    for (int i = 0; i < n; i++)
    {
        m = max(m, backward[i] + forward[i]);
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
    cout << planning(contests, n) - 1 << endl;

    return 0;
}
