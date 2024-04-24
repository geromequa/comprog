
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;
    ll current = (n + 2 - 1) / 2;
    ll l = 1;
    ll r = n;
    while (true)
    {
        if (l - r == 1)
        {
            cout << "! " + current << endl;
            return 0;
        }
        int d;
        cout << "? " + current + (current + 1) << endl;
        cin >> d;
        if (d)
        {
            r = current;
            current = (l + r + 1) / 2;
        }
        else
        {
            l = current;
            current = (l + r + 1) / 2;
        }
    }
    return 0;
}
