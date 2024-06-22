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

    ll n, H;
    cin >> n >> H;

    vector<vector<ll>> books(n);
    ll total_width = 0;
    rep(i, n)
    {
        ll l, w, h;
        cin >> l >> w >> h;
        books[i] = {l, w, h};
        sort(all(books[i]));
        if (books[i][1] <= H)
        {
            total_width += books[i][0];
        }
        else if (books[i][0] <= H)
        {
            total_width += books[i][1];
        }
        else
        {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << total_width << endl;

    return 0;
}