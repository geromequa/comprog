
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

string checkPattern(string p, string s, int m, int n)
{

    if (m - 1 > n)
    {
        return "NO";
    }
    int i = 0;
    if (!(p[0] == '*' || p[0] == '+'))
    {
        for (i = 0; i < min(m, n); i++)
        {
            if (p[i] == s[i])
            {
                continue;
            }
            else if (p[i] == '*')
            {
                if (i == m - 1)
                    return "YES";
                break;
            }
            else if (p[i] == '+')
            {
                if (i == m - 1)
                {
                    if (i + 2 <= n)
                    {
                        return "YES";
                    }
                    else
                    {
                        return "NO";
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    int j = p.size() - 1;
    for (int k = 0; k < min(m, n); k++)
    {
        if (p[j] == s[n - 1 - k])
        {
            j--;
            continue;
        }
        else if (p[j] == '*')
        {
            return "YES";
        }
        else if (p[j] == '+')
        {
            if (n - j - i > 0)
            {
                return "YES";
            }
            else
            {
                return "NO";
            }
        }
        else
        {
            return "NO";
        }
    }
    if (m == n)
    {
        return "YES";
    }
    return "NO";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll t;
    cin >> t;
    cin.ignore();
    rep(i, t)
    {
        string s, p;
        getline(cin, p);
        getline(cin, s);
        int m = p.size();
        int n = s.size();
        cout << checkPattern(p, s, m, n) << endl;
    }

    return 0;
}
