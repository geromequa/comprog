#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n, q;
    cin >> n >> q;
    vector<uint64_t> inverters(n);
    rep(i, n)
    {
        cin >> hex >> inverters[i];
    }

    vector<uint64_t> prefix(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
    {
        prefix[i] = prefix[i - 1] ^ inverters[i - 1];
    }

    while (q--)
    {
        ll s, r;
        cin >> dec >> s >> r;
        s--;
        r--;

        uint64_t xor_pattern;
        if (s <= r)
        {
            xor_pattern = prefix[r] ^ prefix[s];
        }
        else
        {
            xor_pattern = (prefix[n] ^ prefix[s]) ^ prefix[r];
        }

        cout << xor_pattern << endl;
    }

    return 0;
}
