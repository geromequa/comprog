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

    ll n, w;
    cin >> n >> w;
    cin.ignore();
    vector<tuple<ll, ll, ll>> waves;
    rep(i, n)
    {
        char c;
        cin >> c;
        if (c == '!')
        {
            ll p, l, a;
            cin >> p >> l >> a;
            waves.push_back(make_tuple(p, l - 1, a));
        }
        else if (c == '?')
        {
            ll x;
            ll amplitude = 0;
            cin >> x;
            for (auto [p, l, a] : waves)
            {
                ll dif;
                if (p <= x && x <= p + l)
                {
                    dif = (x - p) % 4;
                    switch (dif)
                    {
                    case 0:
                        amplitude += a;
                        break;
                    case 2:
                        amplitude -= a;

                    default:
                        break;
                    }
                }
            }
            cout << amplitude << endl;
        }
    }
    return 0;
}