#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

ll parcelParadox(Graph &G, ll n)
{
    ll result = 0;
    rep(i, n)
    {
        if (G[i].size() == 1)
        {
            result++;
        }
    }
    if (result % 2 == 0)
    {
        return result / 2;
    }
    else
    {
        return (result + 1) / 2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;

    Graph G = vector<vector<ll>>(n);

    rep(i, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    cout << parcelParadox(G, n) << endl;

    return 0;
}
