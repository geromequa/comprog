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

    ll t;
    cin >> t;

    rep(i, t)
    {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        ll d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        if (d > (r1 + r2) || d < abs(r1 - r2))
        {
            cout << 0 << endl;
            continue;
        }
        if (d == 0 && r1 == r2)
        {
            cout << "oo" << endl;
            continue;
        }
        if (d == (r1 + r2) || d == abs(r1 - r2))
        {
            cout << 1 << endl;
            continue;
        }
        if (abs(r1 - r2) < d && d < (r1 + r2))
        {
            cout << 2 << endl;
            continue;
        }
    }

    return 0;
}
