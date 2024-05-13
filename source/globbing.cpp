
#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

string checkPattern(string s, string p)
{
    if (p[0] == '*' || p[0] == '+')
    {
        int j = p.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == s[j])
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
                if (s.size() - 1 - i > 0)
                {
                    return "YES";
                }
                else
                    return "NO";
            }
            else
                return "NO";
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == p[i])
            {
                continue;
            }
            else if (p[i] == '*')
            {
                if (p.size() == i + 1)
                {
                    return "YES";
                }
                else
                    break;
            }
            else if (p[i] == '+')
            {
                if (p.size() == i + 1 && s.size() > i + 1)
                {
                    return "YES";
                }
                else
                    break;
            }
            else
            {
                return "NO";
            }
        }
        int j = p.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == p[j])
            {
                j--;
                continue;
            }
            else if (p[j] == '*' || p[j] == '+')
            {
                return "YES";
            }
            else
                return "NO";
        }
    }
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
        cout << checkPattern(s, p) << endl;
    }

    return 0;
}
