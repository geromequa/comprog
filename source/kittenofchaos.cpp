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

    string s, t;
    cin >> s;
    cin >> t;
    bool h = false;
    bool v = false;
    bool r = false;
    ll n = s.size();
    for (char c : t)
    {
        switch (c)
        {
        case 'h':
            h = !h;
            break;
        case 'v':
            v = !v;
            break;
        case 'r':
            r = !r;
            break;
        default:
            break;
        }
    }
    if (v)
    {
        for (char &c : s)
        {
            switch (c)
            {
            case 'b':
                c = 'p';
                break;
            case 'd':
                c = 'q';
                break;
            case 'p':
                c = 'b';
                break;
            case 'q':
                c = 'd';
                break;
            default:
                break;
            }
        }
    }
    if (h)
    {
        string tmp = s;
        for (ll i = 0; i < tmp.size(); i++)
        {
            switch (tmp[i])
            {
            case 'b':
                s[n - i - 1] = 'd';
                break;
            case 'q':
                s[n - i - 1] = 'p';
                break;
            case 'd':
                s[n - i - 1] = 'b';
                break;
            case 'p':
                s[n - i - 1] = 'q';
                break;
            default:
                break;
            }
            if (i != s.size() - i)
            {
                switch (tmp[n - i - 1])
                {
                case 'b':
                    s[i] = 'd';
                    break;
                case 'q':
                    s[i] = 'p';
                    break;
                case 'd':
                    s[i] = 'b';
                    break;
                case 'p':
                    s[i] = 'q';
                    break;
                default:
                    break;
                }
            }
        }
    }
    if (r)
    {
        string tmp = s;
        for (ll i = 0; i < tmp.size(); i++)
        {
            switch (tmp[i])
            {
            case 'b':
                s[n - i - 1] = 'q';
                break;
            case 'q':
                s[n - i - 1] = 'b';
                break;
            case 'd':
                s[n - i - 1] = 'p';
                break;
            case 'p':
                s[n - i - 1] = 'd';
                break;
            default:
                break;
            }
            if (i != s.size() - i)
            {
                switch (tmp[n - i - 1])
                {
                case 'b':
                    s[i] = 'q';
                    break;
                case 'q':
                    s[i] = 'b';
                    break;
                case 'd':
                    s[i] = 'p';
                    break;
                case 'p':
                    s[i] = 'd';
                    break;
                default:
                    break;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}