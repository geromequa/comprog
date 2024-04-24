
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

pair<int, int> setBorders(ll r, ll l, ll n)
{
    int x, y, z;
    ll current = (l - r + 1) / 2;
    cout << "? " << current << " " << current + 1 << endl;
    cout.flush();
    cin >> x;
    cout << "? n 1" << endl;
    cout.flush();
    cin >> y;
    if (y)
    {
        cout << "? 1 2" << endl;
        cout.flush();
        cin >> z;
        if (z)
        {
            if (x)
            {
                cout << "? " << current << " 1" << endl;
                cout.flush();
                cin >> z;
                if (z)
                {
                    r = current;
                }
                else
                {
                    l = current;
                }
            }
            else
            {
                r = current;
            }
        }
        else
        {
            cout << "! 1" << endl;
            cout.flush();
            return {-1, -1};
        }
    }
    else
    {
        cout << "? " << n << " " << n - 1 << endl;
        cout.flush();
        cin >> z;
        if (z)
        {
            cout << "! " << n << endl;
            cout.flush();
            return {-1, -1};
        }
        else
        {
            if (x)
            {
                l = current;
            }
            else
            {
                cout << "? " << current << " " << n << endl;
                cout.flush();
                cin >> z;
                if (z)
                {
                    l = current;
                }
                else
                {
                    r = current;
                }
            }
        }
    }
    return {r, l};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll n;
    cin >> n;
    ll current;
    auto [r, l] = setBorders(0, n, n);
    while (true)
    {
        if (r - l == 1)
        {
            cout << "! " << l << endl;
            cout.flush();
            return 0;
        }
        int b;
        current = (r - l + 1) / 2;
        cout << "? " << current << " " << current + 1 << endl;
        cout.flush();
        cin >> b;
        if (b)
        {
            r = current;
        }
        else
        {
            l = current;
        }
    }
}
